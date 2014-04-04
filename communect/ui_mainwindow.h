/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Apr 3 12:46:21 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *loginbutton;
    QLabel *logolabel;
    QFrame *line;
    QFrame *line_2;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *usernameline;
    QLabel *passwordlabel;
    QLineEdit *passwordline;
    QLabel *usernamelabel;
    QLabel *main_notiflabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(773, 535);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        loginbutton = new QPushButton(centralWidget);
        loginbutton->setObjectName(QString::fromUtf8("loginbutton"));
        loginbutton->setGeometry(QRect(340, 365, 121, 31));
        loginbutton->setAutoDefault(true);
        loginbutton->setDefault(true);
        logolabel = new QLabel(centralWidget);
        logolabel->setObjectName(QString::fromUtf8("logolabel"));
        logolabel->setGeometry(QRect(166, 50, 431, 191));
        logolabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logolabel->setScaledContents(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(200, 240, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(200, 400, 401, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 420, 201, 16));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 261, 221, 75));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usernameline = new QLineEdit(layoutWidget);
        usernameline->setObjectName(QString::fromUtf8("usernameline"));

        gridLayout->addWidget(usernameline, 0, 1, 1, 1);

        passwordlabel = new QLabel(layoutWidget);
        passwordlabel->setObjectName(QString::fromUtf8("passwordlabel"));

        gridLayout->addWidget(passwordlabel, 1, 0, 1, 1);

        passwordline = new QLineEdit(layoutWidget);
        passwordline->setObjectName(QString::fromUtf8("passwordline"));

        gridLayout->addWidget(passwordline, 1, 1, 1, 1);

        usernamelabel = new QLabel(layoutWidget);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));

        gridLayout->addWidget(usernamelabel, 0, 0, 1, 1);

        main_notiflabel = new QLabel(centralWidget);
        main_notiflabel->setObjectName(QString::fromUtf8("main_notiflabel"));
        main_notiflabel->setGeometry(QRect(140, 340, 521, 21));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        loginbutton->setText(QApplication::translate("MainWindow", "Login", 0));
        logolabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "N users are currently connected.", 0));
        passwordlabel->setText(QApplication::translate("MainWindow", "Password:", 0));
        usernamelabel->setText(QApplication::translate("MainWindow", "Username:", 0));
        main_notiflabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
