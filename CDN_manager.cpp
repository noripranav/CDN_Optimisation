#include "CDN_Manager.hpp"
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <random>
// Constructor
CDNManager::CDNManager() {
    // Initialize random seed for selecting random movies
    std::srand(std::time(0));
}

// Destructor
CDNManager::~CDNManager() {
    // Delete all dynamically allocated CDN nodes
    for (auto& [key, node] : cdnNodes) {
        delete node;
    }
}
std::string getKeyFromValue(const std::unordered_map<std::string, CDNNode*>& map, const CDNNode* node) {
    for (const auto& pair : map) {
        if (pair.second == node) {
            return pair.first;  // return the key if the value matches
        }
    }
    std::string t;
    return t;
}

// Adds a new CDN node at the specified (x, y) coordinates and initializes with random popular movies
void CDNManager::addCDNNode(double x, double y) {
    std::string key = std::to_string(x) + "," + std::to_string(y);  // Unique key based on coordinates
    cdnNodes[key] = new CDNNode(x, y);
    std::cout<<"Node added at :"<<key<<std::endl;
    // Initialize CDN node with a few random popular movies
    initializeCDNNodeWithPopularMovies(cdnNodes[key], 9); // Adjust number of movies as needed
    std::vector<std::string> movie_names = cdnNodes[key]->get_movie_names();
    for(auto a :movie_names)
    {
        std::cout<<"        "<<a<<std::endl;
    }
}

// Adds a movie to the main server's library
void CDNManager::addMovieToMainServer(const std::string& movieName, std::string imagepath) {
    mainServer.addMovie(movieName, imagepath);
}

// Marks a movie as popular and stores it in all CDN nodes
void CDNManager::markMovieAsPopular(const std::string& movieName , CDNNode*& node) {
    Movie* movie = mainServer.getMovie(movieName);
    if (movie) {
        std::vector<std::string> movie_names = node->get_movie_names();
        std::vector<std::pair<int, std::string>> freqs;
        std::string r = getKeyFromValue(cdnNodes, node) + "_" + movieName;

        for(auto a: movie_names)
        {
            std::string requestKey = getKeyFromValue(cdnNodes, node) + "_" + a;
            freqs.push_back(std::make_pair(requestCount[requestKey], a));
        }
        std::sort(freqs.begin(), freqs.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
            return a.first < b.first;
        });

        if(freqs[0].first < requestCount[r])
        {
            node->remove_mov(freqs[0].second);
            node->storePopularMovie(movie);
        }
    }
}

// Initializes a CDN node with a random selection of popular movies
void CDNManager::initializeCDNNodeWithPopularMovies(CDNNode* cdnNode, int numMovies) {
    const auto& allMovies = mainServer.getAllMovies();  // Assume MainServer has this function
    std::vector<Movie*> randomMovies;

    for (int i = 0; i < numMovies && !allMovies.empty(); ++i) {
        int randomIndex = std::rand() % allMovies.size();
        randomMovies.push_back(allMovies[randomIndex]);
    }
    int i =10;
    for (Movie* movie : randomMovies) {
        std::string r = getKeyFromValue(cdnNodes, cdnNode) + "_" + movie->getName();
        requestCount[r] = i++;
        cdnNode->storePopularMovie(movie);
    }
}

// Helper function to find all CDN nodes within a specified radius using a min-heap
std::priority_queue<std::pair<CDNNode*,double>, std::vector<std::pair<CDNNode*,double>>, DistanceComparator>
CDNManager::findCDNNodesInRadius(double userX, double userY, double radius) {
    DistanceComparator comp(userX, userY);
    std::priority_queue<std::pair<CDNNode*, double>, std::vector<std::pair<CDNNode*,double>>, DistanceComparator> nodesInRange(comp);

    for (auto& [key, node] : cdnNodes) {
        double dx = node->getX() - userX;
        double dy = node->getY() - userY;
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= radius) {
            nodesInRange.push(std::make_pair(node,distance));  // Add node to the min-heap if within radius
        }
    }
    return nodesInRange;
}
// Handles a movie request based on the user's location and radius
std::pair<Movie*, std::string> CDNManager::requestMovie(const std::string& movieName, double userX, double userY, double radius) {
    auto nodesInRange = findCDNNodesInRadius(userX, userY, radius);
    std::cout<<"Near nodes : "<<std::endl;
    auto nir = nodesInRange;
    while(!nir.empty())
    {
        CDNNode* node = nir.top().first;
        std::cout<<"     "<<node->getX()<<" , "<<node->getY()<<std::endl;
        nir.pop();
    }
    nir = nodesInRange;
    // Check each CDN node in range for the requested movie
    while (!nodesInRange.empty()) {
        CDNNode* node = nodesInRange.top().first;  // Closest node
        nodesInRange.pop();

        Movie* movie = node->fetchMovie(movieName);
        if (movie) {
            std::string requestKey = getKeyFromValue(cdnNodes, node) + "_" + movieName;
            requestCount[requestKey]++;
            std::string s = "Movie found in server at location" + std::to_string(static_cast<int>(node->getX()))+" "+std::to_string(static_cast<int>(node->getY()));
            return make_pair(movie,s);  // Return if found in CDN node
        }
    }

    // If not found in any CDN node, retrieve from the main server
    if(mainServer.getMovie(movieName) != nullptr)
    {
        CDNNode* node = nir.top().first;  // Closest node
        std::string requestKey = getKeyFromValue(cdnNodes, node) + "_" + movieName;
        requestCount[requestKey]++;
        markMovieAsPopular(movieName, node);
        std::string s ="Movie found in main server";
        return make_pair(mainServer.getMovie(movieName),s);
    }
    else
    {
        std::string s ="Movie Not Found";
        return make_pair(nullptr,s);
    }
    return std::make_pair(nullptr, "");
}
#include <random> // For random sampling

std::vector<Movie*> CDNManager::getTopMoviesForNode(CDNNode* node) {
    std::vector<std::pair<int, std::string>> movieRequests;  // Store movie names and their request counts
    std::string nodeKey = getKeyFromValue(cdnNodes, node);

    // Populate the movieRequests vector with request counts for movies associated with this node
    bool allCountsZero = true;
    for (const auto& entry : requestCount) {
        std::string requestKey = entry.first;
        int count = entry.second;

        // Check if this request count corresponds to the specified node
        if (requestKey.find(nodeKey + "_") == 0) {
            std::string movieName = requestKey.substr(nodeKey.size() + 1);  // Skip "nodeKey_"
            movieRequests.push_back({count, movieName});

            // Update if any count is non-zero
            if (count != 0) {
                allCountsZero = false;
            }
        }
    }

    std::vector<Movie*> topMovies;
    if (allCountsZero) {
        // If all request counts are zero, get 9 random movies
        const auto& allMovies = mainServer.getAllMovies();  // Assume mainServer has a method to get all movies
        std::random_device rd;
        std::mt19937 gen(rd());

        // Select up to 9 random movies from the list
        std::sample(allMovies.begin(), allMovies.end(), std::back_inserter(topMovies), 9, gen);
    } else {
        // Sort by request count in descending order
        std::sort(movieRequests.begin(), movieRequests.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        // Select the top 9 movies based on request count
        for (int i = 0; i < 9 && i < movieRequests.size(); ++i) {
            Movie* movie = mainServer.getMovie(movieRequests[i].second);
            if (movie) {
                topMovies.push_back(movie);
            }
        }
    }

    return topMovies;
}

CDNNode* CDNManager::getNearestNode(int userx, int usery, double radius)
{
    auto it = findCDNNodesInRadius(userx, usery, radius);
    return it.top().first;
}

void CDNManager::initializeRequestCount() {
    // Loop through all CDN nodes
    for (auto& [key, node] : cdnNodes) {
        // Get the list of movie names in the current node
        std::vector<std::string> movieNames = node->get_movie_names();

        // Set the request count for each movie in the node to 0
        for (const auto& movieName : movieNames) {
            std::string requestKey = key + "_" + movieName;
            requestCount[requestKey] = 0;
        }
    }
}


