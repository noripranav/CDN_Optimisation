# CDN Server with Movie Searcher

A Content Delivery Network (CDN) server application that efficiently distributes and displays movie images. Developed in **C++** and **Qt** for a responsive GUI, this application enables users to view popular movie images or search for specific titles based on location.

## Table of Contents
- [Features](#features)
- [Project Structure](#project-structure)
- [Setup](#setup)
- [Usage](#usage)
- [Classes and Components](#classes-and-components)
- [Future Improvements](#future-improvements)

## Features
- **Location-Based Image Display**: Displays movie images from the CDN node nearest to the user's location.
- **Movie Search**: Users can search by movie name; if found, the image and details are displayed.
- **Grid Layout Display**: Movies are presented in a dynamic 3x3 grid layout, which adjusts based on available data.
- **CDN Node Management**: The `CDNManager` class efficiently handles CDN nodes and stores popular movies for quick retrieval.

## Project Structure
The project is organized into the following components:

- **WelcomeWindow**: Displays the initial interface and collects user coordinates.
- **ResultsPage**: Shows movie images based on user location, allows searching, and updates based on the nearest CDN node.
- **CDNManager**: Manages the main server, CDN nodes, movie requests, and stores popular movies.
- **Movie**: Represents a movie object with properties such as name and poster image.
- **CDNNode**: Represents individual CDN nodes with coordinates and a cache of popular movies.
- **MainServer**: Central repository for all movies.

## Setup

### Prerequisites
1. **Qt Framework**: Download and install from [Qt Framework](https://www.qt.io/download-dev#eval-form) for GUI support.
2. **C++ Compiler**: Requires a compiler compatible with C++11 or newer.
3. **Filesystem Library**: Requires C++17 for file handling.

### Network Requirements
For optimal performance and stability, connect via LAN instead of WiFi when running the application.

### Installation
1. **Clone the Repository**
    ```bash
    git clone https://github.com/OmChandraSharma/CDN_Optimization.git
    ```
2. **Open All Project Files in Qt Creator**  
    - Launch Qt Creator and open all files within the `CDN_Optimization` folder to ensure all dependencies and components are loaded correctly.
3. **Build the Project**
    - In Qt Creator, select **Build** to compile the project.
4. **Run the Project**
    - After building, click **Run** to start the application and open the GUI for the CDN Server with Movie Searcher.

## Usage

### Initial Setup
1. Start the application to open the Welcome Window.
2. Enter your coordinates (X and Y between 0 and 200) and submit. These coordinates help calculate the nearest CDN node.

### Viewing Movie Images
- The `ResultsPage` displays movie images based on your location, showing popular movies from the nearest CDN node in a 3x3 grid layout.

### Search for a Movie
- Use the search bar to enter a movie name and search across CDN nodes. If found, the movie's image and details are displayed.

## Classes and Components
- **WelcomeWindow**: Collects and validates user coordinates and connects inputs to `ResultsPage`.
- **ResultsPage**: Displays images from the nearest CDN node and includes a search bar.
- **CDNManager**: Manages CDN nodes and efficiently retrieves popular movies.
- **CDNNode**: Represents a CDN node with (x, y) coordinates and stores nearby popular movies.
- **Movie**: Defines movie properties, including name and image path.
- **MainServer**: Central repository for movies and manages image paths for retrieval.

## Future Improvements
- **Dynamic Node Allocation**: Enable CDN nodes to adjust their cache based on recent user requests.
- **Improved Search Functionality**: Add fuzzy matching for flexible search results.
- **Enhanced Image Caching**: Implement advanced caching for frequently accessed images to improve performance.
