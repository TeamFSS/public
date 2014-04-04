/********************************************************************************
** Form generated from reading UI file 'searchuser.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHUSER_H
#define UI_SEARCHUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_searchuser_frame
{
public:
    QFrame *userhome_frame;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QFrame *line;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;

    void setupUi(QDialog *searchuser_frame)
    {
        if (searchuser_frame->objectName().isEmpty())
            searchuser_frame->setObjectName(QStringLiteral("searchuser_frame"));
        searchuser_frame->resize(773, 698);
        userhome_frame = new QFrame(searchuser_frame);
        userhome_frame->setObjectName(QStringLiteral("userhome_frame"));
        userhome_frame->setGeometry(QRect(270, 140, 461, 361));
        userhome_frame->setFrameShape(QFrame::StyledPanel);
        userhome_frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(userhome_frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 70, 91, 23));
        lineEdit = new QLineEdit(userhome_frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 70, 181, 23));
        label = new QLabel(userhome_frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 73, 91, 16));
        pushButton_3 = new QPushButton(searchuser_frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_6 = new QPushButton(searchuser_frame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_7 = new QPushButton(searchuser_frame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 350, 181, 41));
        pushButton_2 = new QPushButton(searchuser_frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 150, 181, 41));
        label_3 = new QLabel(searchuser_frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        pushButton_4 = new QPushButton(searchuser_frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(669, 70, 61, 23));
        line = new QFrame(searchuser_frame);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(searchuser_frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 201, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_2->setScaledContents(true);
        pushButton_5 = new QPushButton(searchuser_frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 230, 181, 41));
        pushButton_8 = new QPushButton(searchuser_frame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(30, 270, 181, 41));

        retranslateUi(searchuser_frame);

        QMetaObject::connectSlotsByName(searchuser_frame);
    } // setupUi

    void retranslateUi(QDialog *searchuser_frame)
    {
        searchuser_frame->setWindowTitle(QApplication::translate("searchuser_frame", "Dialog", 0));
        pushButton->setText(QApplication::translate("searchuser_frame", "Search User", 0));
        label->setText(QApplication::translate("searchuser_frame", "Username:", 0));
        pushButton_3->setText(QApplication::translate("searchuser_frame", "Messaging", 0));
        pushButton_6->setText(QApplication::translate("searchuser_frame", "Connection Status", 0));
        pushButton_7->setText(QApplication::translate("searchuser_frame", "History Logs", 0));
        pushButton_2->setText(QApplication::translate("searchuser_frame", "Home", 0));
        label_3->setText(QApplication::translate("searchuser_frame", "You are logged in as ____________", 0));
        pushButton_4->setText(QApplication::translate("searchuser_frame", "Logout", 0));
        label_2->setText(QString());
        pushButton_5->setText(QApplication::translate("searchuser_frame", "Accounts Management", 0));
        pushButton_8->setText(QApplication::translate("searchuser_frame", "Rates Management", 0));
    } // retranslateUi

};

namespace Ui {
    class searchuser_frame: public Ui_searchuser_frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHUSER_H
