/********************************************************************************
** Form generated from reading UI file 'accountsmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSMANAGEMENT_H
#define UI_ACCOUNTSMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccountsManagement
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QFrame *line;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QFrame *acctmgmt_frame;
    QLabel *label_6;
    QCheckBox *changepass_checkbox;
    QCheckBox *changeshortcode_checkbox;
    QGroupBox *groupBox;
    QLineEdit *confirmnewpassword_line;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *newpassword_line;
    QLabel *label_9;
    QLineEdit *oldpasswordline;
    QGroupBox *groupBox_2;
    QLineEdit *newshortcode_line;
    QLabel *oldshortcode_label;
    QLabel *label_11;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *modifypriv_checkbox;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QDialog *AccountsManagement)
    {
        if (AccountsManagement->objectName().isEmpty())
            AccountsManagement->setObjectName(QStringLiteral("AccountsManagement"));
        AccountsManagement->resize(773, 535);
        pushButton_2 = new QPushButton(AccountsManagement);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 150, 181, 41));
        pushButton_5 = new QPushButton(AccountsManagement);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 270, 181, 41));
        pushButton_6 = new QPushButton(AccountsManagement);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_7 = new QPushButton(AccountsManagement);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 350, 181, 41));
        line = new QFrame(AccountsManagement);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(AccountsManagement);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(669, 70, 61, 23));
        pushButton_3 = new QPushButton(AccountsManagement);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_4 = new QPushButton(AccountsManagement);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 230, 181, 41));
        label = new QLabel(AccountsManagement);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 201, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(AccountsManagement);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        acctmgmt_frame = new QFrame(AccountsManagement);
        acctmgmt_frame->setObjectName(QStringLiteral("acctmgmt_frame"));
        acctmgmt_frame->setGeometry(QRect(270, 140, 461, 361));
        acctmgmt_frame->setFrameShape(QFrame::StyledPanel);
        acctmgmt_frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(acctmgmt_frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 20, 291, 16));
        changepass_checkbox = new QCheckBox(acctmgmt_frame);
        changepass_checkbox->setObjectName(QStringLiteral("changepass_checkbox"));
        changepass_checkbox->setGeometry(QRect(20, 40, 221, 21));
        changeshortcode_checkbox = new QCheckBox(acctmgmt_frame);
        changeshortcode_checkbox->setObjectName(QStringLiteral("changeshortcode_checkbox"));
        changeshortcode_checkbox->setGeometry(QRect(20, 170, 211, 21));
        groupBox = new QGroupBox(acctmgmt_frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 40, 351, 121));
        confirmnewpassword_line = new QLineEdit(groupBox);
        confirmnewpassword_line->setObjectName(QStringLiteral("confirmnewpassword_line"));
        confirmnewpassword_line->setGeometry(QRect(140, 92, 141, 23));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 64, 121, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 94, 131, 21));
        newpassword_line = new QLineEdit(groupBox);
        newpassword_line->setObjectName(QStringLiteral("newpassword_line"));
        newpassword_line->setGeometry(QRect(140, 62, 141, 23));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 34, 121, 21));
        oldpasswordline = new QLineEdit(groupBox);
        oldpasswordline->setObjectName(QStringLiteral("oldpasswordline"));
        oldpasswordline->setGeometry(QRect(140, 30, 141, 23));
        groupBox_2 = new QGroupBox(acctmgmt_frame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 170, 281, 80));
        newshortcode_line = new QLineEdit(groupBox_2);
        newshortcode_line->setObjectName(QStringLiteral("newshortcode_line"));
        newshortcode_line->setGeometry(QRect(140, 50, 141, 23));
        oldshortcode_label = new QLabel(groupBox_2);
        oldshortcode_label->setObjectName(QStringLiteral("oldshortcode_label"));
        oldshortcode_label->setGeometry(QRect(10, 30, 221, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 55, 151, 16));
        groupBox_3 = new QGroupBox(acctmgmt_frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 260, 201, 91));
        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 30, 85, 21));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 55, 211, 21));
        modifypriv_checkbox = new QCheckBox(acctmgmt_frame);
        modifypriv_checkbox->setObjectName(QStringLiteral("modifypriv_checkbox"));
        modifypriv_checkbox->setGeometry(QRect(20, 260, 231, 21));
        pushButton_8 = new QPushButton(acctmgmt_frame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(360, 330, 80, 23));
        pushButton_9 = new QPushButton(acctmgmt_frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(270, 330, 80, 23));

        retranslateUi(AccountsManagement);

        QMetaObject::connectSlotsByName(AccountsManagement);
    } // setupUi

    void retranslateUi(QDialog *AccountsManagement)
    {
        AccountsManagement->setWindowTitle(QApplication::translate("AccountsManagement", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("AccountsManagement", "Home", 0));
        pushButton_5->setText(QApplication::translate("AccountsManagement", "Rates Management", 0));
        pushButton_6->setText(QApplication::translate("AccountsManagement", "Connection Status", 0));
        pushButton_7->setText(QApplication::translate("AccountsManagement", "History Logs", 0));
        pushButton->setText(QApplication::translate("AccountsManagement", "Logout", 0));
        pushButton_3->setText(QApplication::translate("AccountsManagement", "Messaging", 0));
        pushButton_4->setText(QApplication::translate("AccountsManagement", "Accounts Management", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("AccountsManagement", "You are logged in as ____________", 0));
        label_6->setText(QApplication::translate("AccountsManagement", "Username: adelen", 0));
        changepass_checkbox->setText(QApplication::translate("AccountsManagement", "Change Password", 0));
        changeshortcode_checkbox->setText(QApplication::translate("AccountsManagement", "Change Shortcode", 0));
        groupBox->setTitle(QString());
        label_7->setText(QApplication::translate("AccountsManagement", "New Password:", 0));
        label_8->setText(QApplication::translate("AccountsManagement", "Confirm New:", 0));
        label_9->setText(QApplication::translate("AccountsManagement", "Old Password:", 0));
        groupBox_2->setTitle(QString());
        oldshortcode_label->setText(QApplication::translate("AccountsManagement", "Old Shortcode: 12345", 0));
        label_11->setText(QApplication::translate("AccountsManagement", "New Shortcode:", 0));
        groupBox_3->setTitle(QString());
        checkBox_4->setText(QApplication::translate("AccountsManagement", "Rates", 0));
        checkBox_5->setText(QApplication::translate("AccountsManagement", "Modify Privileges", 0));
        modifypriv_checkbox->setText(QApplication::translate("AccountsManagement", "Modify Privileges", 0));
        pushButton_8->setText(QApplication::translate("AccountsManagement", "Save", 0));
        pushButton_9->setText(QApplication::translate("AccountsManagement", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountsManagement: public Ui_AccountsManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSMANAGEMENT_H
