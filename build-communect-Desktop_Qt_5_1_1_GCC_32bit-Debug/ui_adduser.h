/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

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

class Ui_AddUser
{
public:
    QFrame *adduser_frame;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *AddUser)
    {
        if (AddUser->objectName().isEmpty())
            AddUser->setObjectName(QStringLiteral("AddUser"));
        AddUser->resize(773, 535);
        adduser_frame = new QFrame(AddUser);
        adduser_frame->setObjectName(QStringLiteral("adduser_frame"));
        adduser_frame->setGeometry(QRect(270, 140, 461, 361));
        adduser_frame->setFrameShape(QFrame::StyledPanel);
        adduser_frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(adduser_frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 70, 201, 23));
        pushButton = new QPushButton(adduser_frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 70, 80, 23));
        label = new QLabel(adduser_frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 75, 71, 16));
        pushButton_5 = new QPushButton(AddUser);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 270, 181, 41));
        pushButton_6 = new QPushButton(AddUser);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_3 = new QPushButton(AddUser);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_4 = new QPushButton(AddUser);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(669, 70, 61, 23));
        line = new QFrame(AddUser);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_7 = new QPushButton(AddUser);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 230, 181, 41));
        pushButton_8 = new QPushButton(AddUser);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(30, 150, 181, 41));
        pushButton_9 = new QPushButton(AddUser);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(30, 350, 181, 41));
        label_4 = new QLabel(AddUser);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_4->setFont(font);
        label_5 = new QLabel(AddUser);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 20, 201, 81));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_5->setScaledContents(true);

        retranslateUi(AddUser);

        QMetaObject::connectSlotsByName(AddUser);
    } // setupUi

    void retranslateUi(QDialog *AddUser)
    {
        AddUser->setWindowTitle(QApplication::translate("AddUser", "Dialog", 0));
        pushButton->setText(QApplication::translate("AddUser", "Search", 0));
        label->setText(QApplication::translate("AddUser", "Username", 0));
        pushButton_5->setText(QApplication::translate("AddUser", "Rates Management", 0));
        pushButton_6->setText(QApplication::translate("AddUser", "Connection Status", 0));
        pushButton_3->setText(QApplication::translate("AddUser", "Messaging", 0));
        pushButton_4->setText(QApplication::translate("AddUser", "Logout", 0));
        pushButton_7->setText(QApplication::translate("AddUser", "Accounts Management", 0));
        pushButton_8->setText(QApplication::translate("AddUser", "Home", 0));
        pushButton_9->setText(QApplication::translate("AddUser", "History Logs", 0));
        label_4->setText(QApplication::translate("AddUser", "You are logged in as ____________", 0));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddUser: public Ui_AddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H