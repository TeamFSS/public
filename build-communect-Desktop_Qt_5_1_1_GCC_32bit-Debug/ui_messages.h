/********************************************************************************
** Form generated from reading UI file 'messages.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

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

class Ui_messages
{
public:
    QFrame *line;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QDialog *messages)
    {
        if (messages->objectName().isEmpty())
            messages->setObjectName(QStringLiteral("messages"));
        messages->resize(741, 531);
        line = new QFrame(messages);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(messages);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(669, 70, 61, 23));
        label = new QLabel(messages);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 201, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(messages);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        pushButton_2 = new QPushButton(messages);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 150, 181, 41));
        pushButton_5 = new QPushButton(messages);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 270, 181, 41));
        pushButton_7 = new QPushButton(messages);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 350, 181, 41));
        pushButton_6 = new QPushButton(messages);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_3 = new QPushButton(messages);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_4 = new QPushButton(messages);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 230, 181, 41));
        frame = new QFrame(messages);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(260, 150, 461, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 115, 101, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 155, 111, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 193, 141, 21));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 110, 191, 23));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 150, 191, 23));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 190, 191, 23));
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(320, 260, 80, 23));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(70, 260, 80, 23));

        retranslateUi(messages);

        QMetaObject::connectSlotsByName(messages);
    } // setupUi

    void retranslateUi(QDialog *messages)
    {
        messages->setWindowTitle(QApplication::translate("messages", "Dialog", 0));
        pushButton->setText(QApplication::translate("messages", "Logout", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("messages", "You are logged in as ____________", 0));
        pushButton_2->setText(QApplication::translate("messages", "Home", 0));
        pushButton_5->setText(QApplication::translate("messages", "Rates Management", 0));
        pushButton_7->setText(QApplication::translate("messages", "History Logs", 0));
        pushButton_6->setText(QApplication::translate("messages", "Connection Status", 0));
        pushButton_3->setText(QApplication::translate("messages", "Messaging", 0));
        pushButton_4->setText(QApplication::translate("messages", "Accounts Management", 0));
        label_3->setText(QApplication::translate("messages", "Username:", 0));
        label_4->setText(QApplication::translate("messages", "Password:", 0));
        label_5->setText(QApplication::translate("messages", "Re-type Password:", 0));
        pushButton_8->setText(QApplication::translate("messages", "Add User", 0));
        pushButton_9->setText(QApplication::translate("messages", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class messages: public Ui_messages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_H
