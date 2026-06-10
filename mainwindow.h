#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "WelcomeWindow.h"  // Include the header for WelcomeWindow
#include "resultspage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void switchToResultsPage(int userX, int userY);
    ResultsPage* resultsPage;
    void switchToMainPage();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;  // Pointer to the QStackedWidget
    WelcomeWindow* welcomeWindow;
};

#endif // MAINWINDOW_H
