/********************************************************************************
** Form generated from reading UI file 'resultspage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSPAGE_H
#define UI_RESULTSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultsPage
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *ResultsPage)
    {
        if (ResultsPage->objectName().isEmpty())
            ResultsPage->setObjectName("ResultsPage");
        ResultsPage->resize(963, 461);
        ResultsPage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label = new QLabel(ResultsPage);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 70, 691, 41));
        label_2 = new QLabel(ResultsPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 30, 101, 41));
        pushButton = new QPushButton(ResultsPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 30, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(ResultsPage);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 140, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(ResultsPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 161, 21));
        pushButton_2 = new QPushButton(ResultsPage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 140, 80, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(ResultsPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 320, 321, 91));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(ResultsPage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 190, 371, 111));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(ResultsPage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 161, 111));

        retranslateUi(ResultsPage);

        QMetaObject::connectSlotsByName(ResultsPage);
    } // setupUi

    void retranslateUi(QWidget *ResultsPage)
    {
        ResultsPage->setWindowTitle(QCoreApplication::translate("ResultsPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("ResultsPage", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">Popular Movie Searches On the Nearest Server</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ResultsPage", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">MENU</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ResultsPage", "Change Location", nullptr));
        label_3->setText(QCoreApplication::translate("ResultsPage", "<html><head/><body><p><span style=\" font-size:8pt; font-style:italic; color:#ffffff;\">Search For Movies :</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ResultsPage", "Search", nullptr));
        label_4->setText(QCoreApplication::translate("ResultsPage", "<html><head/><body><p><span style=\" font-size:26pt; color:#ffffff;\"><br/></span></p></body></html>", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("ResultsPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultsPage: public Ui_ResultsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSPAGE_H
