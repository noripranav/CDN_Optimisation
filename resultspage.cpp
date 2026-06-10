#include "resultspage.h"
#include "ui_resultspage.h"
namespace fs = std::filesystem;

ResultsPage::ResultsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResultsPage),gridLayout(new QGridLayout(this))
{
    ui->setupUi(this);
    setLayout(gridLayout);  // Set the grid layout as the main layout
    QWidget *gridContainer = new QWidget(this);

    // Set the desired position and size for the grid layout (adjust values as needed)
    gridContainer->setGeometry(300, 100, 600, 400);  // (x, y, width, height)

    // Initialize and apply the grid layout to the container
    gridLayout = new QGridLayout(gridContainer);
    gridContainer->setLayout(gridLayout);
    gridLayout->setHorizontalSpacing(-2);  // Decrease horizontal spacing (default is 6)
    gridLayout->setVerticalSpacing(-2);
    std::string logo_path = "./assests/cover.png";
    QPixmap pixmap(QString::fromStdString(logo_path));

    // Check if the image exists and is valid
    if (!pixmap.isNull()) {
        // Set the pixmap (image) to the QLabel
        ui->label_6->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->label_6->setAlignment(Qt::AlignCenter);  // Center the image in the label
    } else {
        // Handle case where the image is not found
        ui->label_6->setText("Image not found");
    }


}
ResultsPage::~ResultsPage()
{
    delete ui;
}

void set_up_main_server(std::string movieDirectoryPath, CDNManager& manager)
{
    // Reading all movie images from the directory and adding them to the main server
    for (const auto& entry : fs::directory_iterator(movieDirectoryPath)) {
        if (entry.is_regular_file()) {
            std::string movieName = entry.path().stem().string();  // Extract movie name from file name
            std::string imagePath = entry.path().string();          // Full path to the image file
            // std::cout << movieName  << " "<< imagePath << std::endl;
            manager.addMovieToMainServer(movieName, imagePath);
        }
    }
    std::cout<<"------------------------"<<std::endl;
}

void AddCDNNodes(CDNManager& manager)
{
    int x =20;
    int y =20;
    for(int i =0; i <5; ++i)
    {
        for(int j =0; j <5; ++j)
        {
            manager.addCDNNode(x,y);
            y += 40;
        }
        y =20;
        x+= 40;
    }
    std::cout<<"----------------------------------"<<std::endl;
}
void ResultsPage::updateCoordinates(int newX, int newY)
{
    UserX = newX;
    UserY = newY;
    std::cout<<"updated x: "<<UserX<<" "<<"Updated y : "<<UserY<<std::endl;

    // You can update the UI to reflect the new coordinates if necessary
    // For example:
    // ui->xCoordLabel->setText(QString::number(xCoord));
    // ui->yCoordLabel->setText(QString::number(yCoord));
}
void ResultsPage::displayImages(const QStringList& imagePaths)
{
    // Clear any existing widgets in the grid layout
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Add images in a 3x3 grid
    int row = 0, col = 0;
    for (int i = 0; i < imagePaths.size() && i < 9; ++i) {  // Limit to 9 images
        const QString& imagePath = imagePaths[i];

        // Create a QLabel to hold the image
        QLabel* imageLabel = new QLabel(this);
        QPixmap pixmap(imagePath);

        // Check if the image exists and can be loaded
        if (!pixmap.isNull()) {
            // Scale the pixmap to fit a smaller size for the grid, e.g., 100x100
            imageLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            imageLabel->setAlignment(Qt::AlignCenter);

            // Add the label to the grid layout
            gridLayout->addWidget(imageLabel, row, col);

            // Update row and column for next position
            col++;
            if (col == 3) {  // Move to the next row after 3 images
                col = 0;
                row++;
            }
        } else {
            // Handle case if the image fails to load
            imageLabel->setText("Image not found");
            gridLayout->addWidget(imageLabel, row, col);
            col++;
            if (col == 3) {
                col = 0;
                row++;
            }
        }
    }
}
QStringList ResultsPage::getImagePaths(const std::vector<Movie*>& movies) {
    QStringList imagePaths;

    for (const Movie* movie : movies) {
        imagePaths.append(QString::fromStdString(movie->getPoster()));  // Convert each image path to QString and add to the list
    }

    return imagePaths;
}
void ResultsPage::update_nearest_node()
{
    top = manager.getNearestNode(UserX, UserY, 30);
    std::vector<Movie*> popMovies = manager.getTopMoviesForNode(top);
    for(auto a: popMovies)
    {
        std::cout<<a->getPoster()<<std::endl;
    }
    QStringList moviePaths = getImagePaths(popMovies);
    displayImages(moviePaths);

}

void ResultsPage::on_lineEdit_textChanged(const QString &arg1)
{
    requested_movie = arg1.toStdString();
}


void ResultsPage::on_pushButton_2_clicked()
{
    std::pair<Movie*,std::string> req= manager.requestMovie(requested_movie , UserX , UserY , 30);

    ui->label_4->setText(QString::fromStdString(req.second));
    if(req.first == nullptr)
        return;
    QPixmap pixmap(QString::fromStdString(req.first->getPoster()));

    // Check if the image exists and is valid
    if (!pixmap.isNull()) {
        // Set the pixmap (image) to the QLabel
        ui->label_5->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->label_5->setAlignment(Qt::AlignCenter);  // Center the image in the label
    } else {
        // Handle case where the image is not found
        ui->label_5->setText("Image not found");
    }
    std::vector<Movie*> popMovies = manager.getTopMoviesForNode(top);
    QStringList moviePaths = getImagePaths(popMovies);
    displayImages(moviePaths);
}

void ResultsPage::on_pushButton_clicked()
{
    emit switchToMainPage();
}

