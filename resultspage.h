#ifndef RESULTSPAGE_H
#define RESULTSPAGE_H
#include "CDN_manager.hpp"
#include <QWidget>
#include<iostream>
#include <filesystem> // For reading files in the directory
#include <QGridLayout>
#include <vector>
#include <qpixmap.h>

namespace Ui {
class ResultsPage;
}

class ResultsPage : public QWidget
{
    Q_OBJECT
public:
    explicit ResultsPage(QWidget *parent = nullptr);
    ~ResultsPage();
    // Global coordinates
    CDNNode* top;
    int UserX;
    int UserY;


    // Function to change coordinates
    void updateCoordinates(int newX, int newY);
    // Function to set and display images from file paths
    void displayImages(const QStringList& imagePaths);
    CDNManager manager;
    QStringList getImagePaths(const std::vector<Movie*>& movies);
    void update_nearest_node();
    std::string requested_movie;
signals:
    void switchToMainPage();
private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ResultsPage *ui;
    QGridLayout* gridLayout;  // Grid layout to display images
};
void set_up_main_server(std::string movieDirectoryPath, CDNManager& manager);
void AddCDNNodes(CDNManager& manager);

#endif // RESULTSPAGE_H
