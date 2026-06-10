#include "mainwindow.h"
// #include "../CDN/mainwindow.cpp"
#include <QApplication>
#include <string>
#include <iostream>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;


    w.show();
    // Path to the directory containing movie images
    std::string movieDirectoryPath = "./assests";

    //intiaise main-server
    set_up_main_server(movieDirectoryPath, w.resultsPage->manager);

    //add node servers
    AddCDNNodes(w.resultsPage->manager);
    // User requests a movie


    return a.exec();
    ;
}
