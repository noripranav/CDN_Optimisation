    #include "mainwindow.h"
    #include "ui_mainwindow.h"

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        // Initialize the QStackedWidget (assuming you added it to the UI in Qt Designer)
        stackedWidget = ui->stackedWidget;  // This should match the name of the QStackedWidget in your .ui file

        // Create a ne instance of WelcomeWindow and add it to the stacked widget
        welcomeWindow = new WelcomeWindow();
        resultsPage = new ResultsPage();

        stackedWidget->addWidget(welcomeWindow);  // Add WelcomeWindow to the stack
        stackedWidget->addWidget(resultsPage);

        // Set the first page (WelcomeWindow) to be shown
        stackedWidget->setCurrentWidget(welcomeWindow);  // Show WelcomeWindow as the first page
        // Connect the switchToResultsPage signal from WelcomeWindow to the setCurrentWidget slot of QStackedWidget
        connect(welcomeWindow, &WelcomeWindow::switchToResultsPage, this, &MainWindow::switchToResultsPage);
        connect(resultsPage, &ResultsPage::switchToMainPage, this, &MainWindow::switchToMainPage);}

    MainWindow::~MainWindow()
    {
        delete ui;
    }
    void MainWindow::switchToResultsPage(int userX, int userY)
    {
        // Call the function in ResultsPage to update coordinates
        resultsPage->updateCoordinates(userX, userY);
        resultsPage-> update_nearest_node();

        // Switch to the ResultsPage
        ui->stackedWidget->setCurrentWidget(resultsPage);
    }
    void MainWindow::switchToMainPage(){
        ui->stackedWidget->setCurrentWidget(welcomeWindow);
    }
