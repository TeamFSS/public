/********************************************************************************
** Form generated from reading UI file 'communityalerts.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNITYALERTS_H
#define UI_COMMUNITYALERTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CommunityAlerts
{
public:
    QFrame *frame;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *CommunityAlerts)
    {
        if (CommunityAlerts->objectName().isEmpty())
            CommunityAlerts->setObjectName(QStringLiteral("CommunityAlerts"));
        CommunityAlerts->resize(773, 535);
        frame = new QFrame(CommunityAlerts);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(270, 140, 461, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 81, 16));
        plainTextEdit = new QPlainTextEdit(frame);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(120, 50, 311, 241));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 310, 80, 23));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 310, 80, 23));
        pushButton_5 = new QPushButton(CommunityAlerts);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 270, 181, 41));
        pushButton_6 = new QPushButton(CommunityAlerts);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_3 = new QPushButton(CommunityAlerts);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_4 = new QPushButton(CommunityAlerts);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(670, 70, 61, 23));
        line = new QFrame(CommunityAlerts);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_7 = new QPushButton(CommunityAlerts);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 230, 181, 41));
        pushButton_8 = new QPushButton(CommunityAlerts);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(30, 150, 181, 41));
        pushButton_9 = new QPushButton(CommunityAlerts);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(30, 350, 181, 41));
        label_2 = new QLabel(CommunityAlerts);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_3 = new QLabel(CommunityAlerts);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 201, 81));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_3->setScaledContents(true);

        retranslateUi(CommunityAlerts);

        QMetaObject::connectSlotsByName(CommunityAlerts);
    } // setupUi

    void retranslateUi(QDialog *CommunityAlerts)
    {
        CommunityAlerts->setWindowTitle(QApplication::translate("CommunityAlerts", "Dialog", 0));
        label->setText(QApplication::translate("CommunityAlerts", "Message:", 0));
        pushButton->setText(QApplication::translate("CommunityAlerts", "Send", 0));
        pushButton_2->setText(QApplication::translate("CommunityAlerts", "Cancel", 0));
        pushButton_5->setText(QApplication::translate("CommunityAlerts", "Rates Management", 0));
        pushButton_6->setText(QApplication::translate("CommunityAlerts", "Connection Status", 0));
        pushButton_3->setText(QApplication::translate("CommunityAlerts", "Messaging", 0));
        pushButton_4->setText(QApplication::translate("CommunityAlerts", "Logout", 0));
        pushButton_7->setText(QApplication::translate("CommunityAlerts", "Accounts Management", 0));
        pushButton_8->setText(QApplication::translate("CommunityAlerts", "Home", 0));
        pushButton_9->setText(QApplication::translate("CommunityAlerts", "History Logs", 0));
        label_2->setText(QApplication::translate("CommunityAlerts", "You are logged in as ____________", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CommunityAlerts: public Ui_CommunityAlerts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNITYALERTS_H
