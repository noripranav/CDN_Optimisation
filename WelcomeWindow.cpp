#include "WelcomeWindow.h"
#include <string>
#include <QIntValidator>
#include <QMessageBox>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    QIntValidator *intValidator = new QIntValidator(0, 200, this);
    ui->UserX->setValidator(intValidator);
    ui->UserY->setValidator(intValidator);
    // connect(ui->submitcordsbtn, &QPushButton::clicked, this, &WelcomeWindow::on_submitcordsbtn_clicked);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

int userX;
int userY;

void WelcomeWindow::on_UserX_textChanged(const QString &arg1)
{
    userX = arg1.toInt();
    std::cout<<userX<<std::endl;

    if (userX < 0 || userX > 200) {
        ui->UserX->clear();
        QMessageBox::warning(this, "Input Error", "Please enter a number between 0 and 200.");
        return;
    }
}

void WelcomeWindow::on_UserY_textChanged(const QString &arg1)
{
    userY = arg1.toInt();
    std::cout<<userY<<std::endl;

    if (userY < 0 || userY > 200) {
        ui->UserY->clear();
        QMessageBox::warning(this, "Input Error", "Please enter a number between 0 and 200.");
        return;
    }

}




void WelcomeWindow::on_submitcordsbtn_clicked()
{
    emit switchToResultsPage(userX, userY);  // Emit the signal to switch to ResultsPage
}

