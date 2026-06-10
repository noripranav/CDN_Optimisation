#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H
#include "ui_WelcomeWindow.h"  // Ensure this is included
#include <QWidget>

#include <iostream>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();
signals:
    void switchToResultsPage(int userX, int userY);
private slots:
    void on_UserX_textChanged(const QString &arg1);

    void on_UserY_textChanged(const QString &arg1);

    void on_submitcordsbtn_clicked();

private:
    Ui::WelcomeWindow *ui;
};
#endif // WELCOMEWINDOW_H
