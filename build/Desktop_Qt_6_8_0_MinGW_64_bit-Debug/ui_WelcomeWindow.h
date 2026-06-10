/********************************************************************************
** Form generated from reading UI file 'WelcomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QWidget *centralwidget;
    QLabel *Welcome_text;
    QLineEdit *UserX;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *UserY;
    QLabel *label_5;
    QPushButton *submitcordsbtn;
    QStatusBar *statusbar;

    void setupUi(QWidget *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(932, 451);
        WelcomeWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        centralwidget = new QWidget(WelcomeWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 931, 394));
        Welcome_text = new QLabel(centralwidget);
        Welcome_text->setObjectName("Welcome_text");
        Welcome_text->setGeometry(QRect(20, 50, 891, 111));
        Welcome_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        UserX = new QLineEdit(centralwidget);
        UserX->setObjectName("UserX");
        UserX->setGeometry(QRect(430, 240, 113, 24));
        UserX->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        UserX->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 240, 91, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 190, 281, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 240, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 280, 91, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        UserY = new QLineEdit(centralwidget);
        UserY->setObjectName("UserY");
        UserY->setGeometry(QRect(430, 280, 113, 24));
        UserY->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(550, 280, 49, 16));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        submitcordsbtn = new QPushButton(centralwidget);
        submitcordsbtn->setObjectName("submitcordsbtn");
        submitcordsbtn->setGeometry(QRect(450, 320, 80, 24));
        submitcordsbtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        statusbar = new QStatusBar(WelcomeWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 20, 22));

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QWidget *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "CDN_Project", nullptr));
        Welcome_text->setText(QCoreApplication::translate("WelcomeWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:72pt;\">MOVIE LIBRARY</span></p></body></html>", nullptr));
        UserX->setText(QString());
        label->setText(QCoreApplication::translate("WelcomeWindow", "X - Coordinate :", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Enter Your Location</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("WelcomeWindow", "(0-200)", nullptr));
        label_4->setText(QCoreApplication::translate("WelcomeWindow", "Y - Coordinate : ", nullptr));
        label_5->setText(QCoreApplication::translate("WelcomeWindow", "(0-200)", nullptr));
        submitcordsbtn->setText(QCoreApplication::translate("WelcomeWindow", "SUBMIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
