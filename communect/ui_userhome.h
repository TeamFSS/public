/********************************************************************************
** Form generated from reading UI file 'userhome.ui'
**
** Created: Wed Apr 2 14:57:56 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERHOME_H
#define UI_USERHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_UserHome
{
public:
    QLabel *logo_upperleft;
    QFrame *line_separator;
    QLabel *username_label;
    QPushButton *logoutbutton;
    QFrame *userhome_frame;
    QLabel *userhomelabel;
    QLabel *usernamelabel;
    QLabel *lastloginlabel;
    QLabel *lasterrorlabel;
    QPushButton *home_button;
    QPushButton *messaging_button;
    QPushButton *acctmgmt_button;
    QPushButton *rates_button;
    QPushButton *connectionstatus_button;
    QPushButton *historylogs_button;
    QFrame *rates_frame;
    QLabel *rates_servicetype_label;
    QLabel *rates_oldrate_label;
    QLineEdit *rates_oldratelabel;
    QLabel *rates_newrate_label;
    QLineEdit *rates_newratelabel;
    QPushButton *rates_savebutton;
    QPushButton *rates_cancelbutton;
    QComboBox *rates_combobox;
    QFrame *modifyuser_frame;
    QLabel *modifyuser_username_label;
    QCheckBox *changepass_checkbox;
    QCheckBox *changeshortcode_checkbox;
    QGroupBox *changepasswordgroup;
    QLineEdit *confirmnewpassword_line;
    QLabel *modifyuser_newpassword_label;
    QLabel *modifyuser_confirmnew_label;
    QLineEdit *newpassword_line;
    QLabel *modifyuser_oldpassword_label;
    QLineEdit *oldpasswordline;
    QGroupBox *changeshortcodegroup;
    QLineEdit *newshortcode_line;
    QLabel *oldshortcode_label;
    QLabel *modifyuser_newshortcode_label;
    QLineEdit *oldshortcode_line;
    QGroupBox *modifyprivilegesgroup;
    QCheckBox *grantrates_checkbox;
    QCheckBox *grantadduser_checkbox;
    QCheckBox *grantshortcodes_checkbox;
    QCheckBox *grantmodifyuser_checkbox;
    QCheckBox *grantsendalerts_checkbox;
    QCheckBox *granthistlogs_checkbox;
    QCheckBox *grantconfigsettings_checkbox;
    QCheckBox *grantsurvrecord_checkbox;
    QCheckBox *grantmodpriv_checkbox;
    QCheckBox *modifypriv_checkbox;
    QPushButton *saveacctbutton;
    QPushButton *acctmgmt_cancelbutton;
    QLabel *modprivusername_label;
    QFrame *historylogs_frame;
    QLabel *historylogs_date_label;
    QTableView *historylogs_tableview;
    QComboBox *month_combobox;
    QComboBox *day_combobox;
    QComboBox *year_combobox;
    QFrame *unitcommunication_frame;
    QLabel *unitcommunication_recipient_label;
    QLabel *unitcommunication_message_label;
    QPlainTextEdit *unitcommmessage_text;
    QPushButton *unitcommsend_button;
    QPushButton *unitcommcancel_button;
    QComboBox *unitcommunication_combobox;
    QPushButton *configsettings_button;
    QPushButton *survivor_button;
    QFrame *messaging_frame;
    QPushButton *communityalerts_button;
    QPushButton *unitcommunication_button;
    QLabel *messaging_notiflabel;
    QFrame *communityalerts_frame;
    QLabel *commalertmessage_label;
    QPlainTextEdit *commalertmessage_text;
    QPushButton *commalertssend_button;
    QPushButton *commalertscancel_button;
    QFrame *acctmgmt_frame;
    QPushButton *adduser_button;
    QPushButton *modifyuser_button;
    QLabel *acctmgmt_notiflabel;
    QFrame *adduser_frame;
    QLabel *adduser_username_label;
    QLabel *adduser_password_label;
    QLabel *adduser_retypepassword_label;
    QLineEdit *adduser_usernameline;
    QLineEdit *adduser_passwordline;
    QLineEdit *adduser_retypepasswordline;
    QPushButton *addusersave_button;
    QPushButton *addusercancel_button;
    QFrame *logout_frame;
    QLabel *logo_picture;
    QLabel *logout_message_label;
    QFrame *searchuser_frame;
    QLineEdit *searchuserline;
    QPushButton *searchuser_button;
    QLabel *searchuser_username_label;
    QLabel *searchuser_label;
    QFrame *tmsi_frame;
    QTableView *tmsi_tableview;
    QFrame *emergency911_frame;
    QTableView *e911_tableView;
    QLabel *e911_date_label;
    QComboBox *e911_month_combobox;
    QComboBox *e911_day_combobox;
    QComboBox *e911_year_combobox;
    QFrame *configsettings_frame;
    QPushButton *addconfig_button;
    QPushButton *modifyconfig_button;
    QLabel *config_notiflabel;
    QFrame *modifyconfig_frame;
    QComboBox *configsettings_comboBox;
    QLabel *configsettings_oldvalue_label;
    QLabel *configsettings_newvalue_label;
    QLineEdit *configsettings_oldvalue_line;
    QLineEdit *configsettings_newvalue_line;
    QPushButton *configsettings_cancel_button;
    QPushButton *configsettings_save_button;
    QRadioButton *configsettings_edit_radiobutton;
    QRadioButton *configsettings_delete_radiobutton;
    QFrame *addconfig_frame;
    QLabel *configsettings_create_name_label;
    QLabel *configsettings_value_name_label;
    QLabel *configsettings_comment_name_label;
    QLineEdit *configsettings_name_line;
    QLineEdit *configsettings_value_line;
    QLineEdit *configsettings_comment_line;
    QPushButton *configsettings_createcancel_button;
    QPushButton *configsettings_createsave_button;

    void setupUi(QDialog *UserHome)
    {
        if (UserHome->objectName().isEmpty())
            UserHome->setObjectName(QString::fromUtf8("UserHome"));
        UserHome->resize(750, 535);
        logo_upperleft = new QLabel(UserHome);
        logo_upperleft->setObjectName(QString::fromUtf8("logo_upperleft"));
        logo_upperleft->setGeometry(QRect(10, 20, 201, 81));
        logo_upperleft->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logo_upperleft->setScaledContents(true);
        line_separator = new QFrame(UserHome);
        line_separator->setObjectName(QString::fromUtf8("line_separator"));
        line_separator->setGeometry(QRect(20, 90, 711, 16));
        line_separator->setFrameShape(QFrame::HLine);
        line_separator->setFrameShadow(QFrame::Sunken);
        username_label = new QLabel(UserHome);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        username_label->setFont(font);
        logoutbutton = new QPushButton(UserHome);
        logoutbutton->setObjectName(QString::fromUtf8("logoutbutton"));
        logoutbutton->setGeometry(QRect(669, 70, 61, 23));
        userhome_frame = new QFrame(UserHome);
        userhome_frame->setObjectName(QString::fromUtf8("userhome_frame"));
        userhome_frame->setGeometry(QRect(260, 150, 461, 361));
        userhome_frame->setFrameShape(QFrame::StyledPanel);
        userhome_frame->setFrameShadow(QFrame::Raised);
        userhomelabel = new QLabel(userhome_frame);
        userhomelabel->setObjectName(QString::fromUtf8("userhomelabel"));
        userhomelabel->setGeometry(QRect(30, 50, 91, 31));
        usernamelabel = new QLabel(userhome_frame);
        usernamelabel->setObjectName(QString::fromUtf8("usernamelabel"));
        usernamelabel->setGeometry(QRect(60, 100, 351, 31));
        lastloginlabel = new QLabel(userhome_frame);
        lastloginlabel->setObjectName(QString::fromUtf8("lastloginlabel"));
        lastloginlabel->setGeometry(QRect(60, 140, 351, 41));
        lasterrorlabel = new QLabel(userhome_frame);
        lasterrorlabel->setObjectName(QString::fromUtf8("lasterrorlabel"));
        lasterrorlabel->setGeometry(QRect(60, 190, 351, 31));
        home_button = new QPushButton(UserHome);
        home_button->setObjectName(QString::fromUtf8("home_button"));
        home_button->setGeometry(QRect(30, 150, 181, 41));
        messaging_button = new QPushButton(UserHome);
        messaging_button->setObjectName(QString::fromUtf8("messaging_button"));
        messaging_button->setGeometry(QRect(30, 190, 181, 41));
        acctmgmt_button = new QPushButton(UserHome);
        acctmgmt_button->setObjectName(QString::fromUtf8("acctmgmt_button"));
        acctmgmt_button->setGeometry(QRect(30, 230, 181, 41));
        rates_button = new QPushButton(UserHome);
        rates_button->setObjectName(QString::fromUtf8("rates_button"));
        rates_button->setGeometry(QRect(30, 270, 181, 41));
        connectionstatus_button = new QPushButton(UserHome);
        connectionstatus_button->setObjectName(QString::fromUtf8("connectionstatus_button"));
        connectionstatus_button->setGeometry(QRect(30, 310, 181, 41));
        historylogs_button = new QPushButton(UserHome);
        historylogs_button->setObjectName(QString::fromUtf8("historylogs_button"));
        historylogs_button->setGeometry(QRect(30, 390, 181, 41));
        rates_frame = new QFrame(UserHome);
        rates_frame->setObjectName(QString::fromUtf8("rates_frame"));
        rates_frame->setGeometry(QRect(260, 150, 461, 361));
        rates_frame->setFrameShape(QFrame::StyledPanel);
        rates_frame->setFrameShadow(QFrame::Raised);
        rates_servicetype_label = new QLabel(rates_frame);
        rates_servicetype_label->setObjectName(QString::fromUtf8("rates_servicetype_label"));
        rates_servicetype_label->setGeometry(QRect(40, 40, 91, 16));
        rates_oldrate_label = new QLabel(rates_frame);
        rates_oldrate_label->setObjectName(QString::fromUtf8("rates_oldrate_label"));
        rates_oldrate_label->setGeometry(QRect(130, 95, 57, 15));
        rates_oldratelabel = new QLineEdit(rates_frame);
        rates_oldratelabel->setObjectName(QString::fromUtf8("rates_oldratelabel"));
        rates_oldratelabel->setEnabled(false);
        rates_oldratelabel->setGeometry(QRect(200, 90, 113, 23));
        rates_oldratelabel->setReadOnly(true);
        rates_newrate_label = new QLabel(rates_frame);
        rates_newrate_label->setObjectName(QString::fromUtf8("rates_newrate_label"));
        rates_newrate_label->setGeometry(QRect(130, 132, 61, 16));
        rates_newratelabel = new QLineEdit(rates_frame);
        rates_newratelabel->setObjectName(QString::fromUtf8("rates_newratelabel"));
        rates_newratelabel->setGeometry(QRect(200, 130, 113, 23));
        rates_savebutton = new QPushButton(rates_frame);
        rates_savebutton->setObjectName(QString::fromUtf8("rates_savebutton"));
        rates_savebutton->setGeometry(QRect(270, 230, 80, 23));
        rates_cancelbutton = new QPushButton(rates_frame);
        rates_cancelbutton->setObjectName(QString::fromUtf8("rates_cancelbutton"));
        rates_cancelbutton->setGeometry(QRect(150, 230, 80, 23));
        rates_combobox = new QComboBox(rates_frame);
        rates_combobox->setObjectName(QString::fromUtf8("rates_combobox"));
        rates_combobox->setGeometry(QRect(150, 37, 241, 23));
        modifyuser_frame = new QFrame(UserHome);
        modifyuser_frame->setObjectName(QString::fromUtf8("modifyuser_frame"));
        modifyuser_frame->setGeometry(QRect(260, 150, 461, 361));
        modifyuser_frame->setFrameShape(QFrame::StyledPanel);
        modifyuser_frame->setFrameShadow(QFrame::Raised);
        modifyuser_username_label = new QLabel(modifyuser_frame);
        modifyuser_username_label->setObjectName(QString::fromUtf8("modifyuser_username_label"));
        modifyuser_username_label->setGeometry(QRect(15, 20, 71, 16));
        changepass_checkbox = new QCheckBox(modifyuser_frame);
        changepass_checkbox->setObjectName(QString::fromUtf8("changepass_checkbox"));
        changepass_checkbox->setGeometry(QRect(15, 40, 221, 21));
        changeshortcode_checkbox = new QCheckBox(modifyuser_frame);
        changeshortcode_checkbox->setObjectName(QString::fromUtf8("changeshortcode_checkbox"));
        changeshortcode_checkbox->setGeometry(QRect(15, 150, 211, 21));
        changepasswordgroup = new QGroupBox(modifyuser_frame);
        changepasswordgroup->setObjectName(QString::fromUtf8("changepasswordgroup"));
        changepasswordgroup->setEnabled(false);
        changepasswordgroup->setGeometry(QRect(15, 60, 351, 91));
        confirmnewpassword_line = new QLineEdit(changepasswordgroup);
        confirmnewpassword_line->setObjectName(QString::fromUtf8("confirmnewpassword_line"));
        confirmnewpassword_line->setGeometry(QRect(140, 55, 141, 23));
        modifyuser_newpassword_label = new QLabel(changepasswordgroup);
        modifyuser_newpassword_label->setObjectName(QString::fromUtf8("modifyuser_newpassword_label"));
        modifyuser_newpassword_label->setGeometry(QRect(10, 35, 121, 16));
        modifyuser_confirmnew_label = new QLabel(changepasswordgroup);
        modifyuser_confirmnew_label->setObjectName(QString::fromUtf8("modifyuser_confirmnew_label"));
        modifyuser_confirmnew_label->setGeometry(QRect(10, 58, 131, 21));
        newpassword_line = new QLineEdit(changepasswordgroup);
        newpassword_line->setObjectName(QString::fromUtf8("newpassword_line"));
        newpassword_line->setGeometry(QRect(140, 30, 141, 23));
        modifyuser_oldpassword_label = new QLabel(changepasswordgroup);
        modifyuser_oldpassword_label->setObjectName(QString::fromUtf8("modifyuser_oldpassword_label"));
        modifyuser_oldpassword_label->setGeometry(QRect(10, 8, 121, 21));
        oldpasswordline = new QLineEdit(changepasswordgroup);
        oldpasswordline->setObjectName(QString::fromUtf8("oldpasswordline"));
        oldpasswordline->setGeometry(QRect(140, 5, 141, 23));
        changeshortcodegroup = new QGroupBox(modifyuser_frame);
        changeshortcodegroup->setObjectName(QString::fromUtf8("changeshortcodegroup"));
        changeshortcodegroup->setEnabled(false);
        changeshortcodegroup->setGeometry(QRect(15, 169, 281, 61));
        newshortcode_line = new QLineEdit(changeshortcodegroup);
        newshortcode_line->setObjectName(QString::fromUtf8("newshortcode_line"));
        newshortcode_line->setGeometry(QRect(140, 30, 141, 23));
        oldshortcode_label = new QLabel(changeshortcodegroup);
        oldshortcode_label->setObjectName(QString::fromUtf8("oldshortcode_label"));
        oldshortcode_label->setGeometry(QRect(10, 10, 121, 16));
        modifyuser_newshortcode_label = new QLabel(changeshortcodegroup);
        modifyuser_newshortcode_label->setObjectName(QString::fromUtf8("modifyuser_newshortcode_label"));
        modifyuser_newshortcode_label->setGeometry(QRect(10, 33, 151, 16));
        oldshortcode_line = new QLineEdit(changeshortcodegroup);
        oldshortcode_line->setObjectName(QString::fromUtf8("oldshortcode_line"));
        oldshortcode_line->setEnabled(false);
        oldshortcode_line->setGeometry(QRect(140, 5, 141, 23));
        modifyprivilegesgroup = new QGroupBox(modifyuser_frame);
        modifyprivilegesgroup->setObjectName(QString::fromUtf8("modifyprivilegesgroup"));
        modifyprivilegesgroup->setEnabled(false);
        modifyprivilegesgroup->setGeometry(QRect(15, 250, 411, 91));
        grantrates_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantrates_checkbox->setObjectName(QString::fromUtf8("grantrates_checkbox"));
        grantrates_checkbox->setGeometry(QRect(15, 10, 85, 21));
        grantadduser_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantadduser_checkbox->setObjectName(QString::fromUtf8("grantadduser_checkbox"));
        grantadduser_checkbox->setGeometry(QRect(140, 10, 91, 21));
        grantshortcodes_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantshortcodes_checkbox->setObjectName(QString::fromUtf8("grantshortcodes_checkbox"));
        grantshortcodes_checkbox->setGeometry(QRect(15, 33, 101, 21));
        grantmodifyuser_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantmodifyuser_checkbox->setObjectName(QString::fromUtf8("grantmodifyuser_checkbox"));
        grantmodifyuser_checkbox->setGeometry(QRect(140, 56, 121, 21));
        grantsendalerts_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantsendalerts_checkbox->setObjectName(QString::fromUtf8("grantsendalerts_checkbox"));
        grantsendalerts_checkbox->setGeometry(QRect(140, 33, 121, 21));
        granthistlogs_checkbox = new QCheckBox(modifyprivilegesgroup);
        granthistlogs_checkbox->setObjectName(QString::fromUtf8("granthistlogs_checkbox"));
        granthistlogs_checkbox->setGeometry(QRect(15, 56, 111, 21));
        grantconfigsettings_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantconfigsettings_checkbox->setObjectName(QString::fromUtf8("grantconfigsettings_checkbox"));
        grantconfigsettings_checkbox->setGeometry(QRect(260, 10, 131, 21));
        grantsurvrecord_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantsurvrecord_checkbox->setObjectName(QString::fromUtf8("grantsurvrecord_checkbox"));
        grantsurvrecord_checkbox->setGeometry(QRect(260, 56, 151, 21));
        grantmodpriv_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantmodpriv_checkbox->setObjectName(QString::fromUtf8("grantmodpriv_checkbox"));
        grantmodpriv_checkbox->setGeometry(QRect(260, 33, 211, 21));
        modifypriv_checkbox = new QCheckBox(modifyuser_frame);
        modifypriv_checkbox->setObjectName(QString::fromUtf8("modifypriv_checkbox"));
        modifypriv_checkbox->setGeometry(QRect(15, 237, 231, 21));
        saveacctbutton = new QPushButton(modifyuser_frame);
        saveacctbutton->setObjectName(QString::fromUtf8("saveacctbutton"));
        saveacctbutton->setGeometry(QRect(360, 330, 80, 23));
        acctmgmt_cancelbutton = new QPushButton(modifyuser_frame);
        acctmgmt_cancelbutton->setObjectName(QString::fromUtf8("acctmgmt_cancelbutton"));
        acctmgmt_cancelbutton->setGeometry(QRect(270, 330, 80, 23));
        modprivusername_label = new QLabel(modifyuser_frame);
        modprivusername_label->setObjectName(QString::fromUtf8("modprivusername_label"));
        modprivusername_label->setGeometry(QRect(100, 20, 291, 16));
        modifyuser_username_label->raise();
        changepass_checkbox->raise();
        changeshortcode_checkbox->raise();
        changepasswordgroup->raise();
        modifyprivilegesgroup->raise();
        modifypriv_checkbox->raise();
        saveacctbutton->raise();
        acctmgmt_cancelbutton->raise();
        modprivusername_label->raise();
        changeshortcodegroup->raise();
        historylogs_frame = new QFrame(UserHome);
        historylogs_frame->setObjectName(QString::fromUtf8("historylogs_frame"));
        historylogs_frame->setGeometry(QRect(260, 150, 461, 361));
        historylogs_frame->setFrameShape(QFrame::StyledPanel);
        historylogs_frame->setFrameShadow(QFrame::Raised);
        historylogs_date_label = new QLabel(historylogs_frame);
        historylogs_date_label->setObjectName(QString::fromUtf8("historylogs_date_label"));
        historylogs_date_label->setGeometry(QRect(70, 30, 41, 16));
        historylogs_tableview = new QTableView(historylogs_frame);
        historylogs_tableview->setObjectName(QString::fromUtf8("historylogs_tableview"));
        historylogs_tableview->setGeometry(QRect(30, 60, 401, 271));
        month_combobox = new QComboBox(historylogs_frame);
        month_combobox->setObjectName(QString::fromUtf8("month_combobox"));
        month_combobox->setGeometry(QRect(220, 25, 101, 23));
        day_combobox = new QComboBox(historylogs_frame);
        day_combobox->setObjectName(QString::fromUtf8("day_combobox"));
        day_combobox->setGeometry(QRect(340, 25, 51, 23));
        year_combobox = new QComboBox(historylogs_frame);
        year_combobox->setObjectName(QString::fromUtf8("year_combobox"));
        year_combobox->setGeometry(QRect(120, 25, 79, 23));
        unitcommunication_frame = new QFrame(UserHome);
        unitcommunication_frame->setObjectName(QString::fromUtf8("unitcommunication_frame"));
        unitcommunication_frame->setGeometry(QRect(260, 150, 461, 361));
        unitcommunication_frame->setFrameShape(QFrame::StyledPanel);
        unitcommunication_frame->setFrameShadow(QFrame::Raised);
        unitcommunication_recipient_label = new QLabel(unitcommunication_frame);
        unitcommunication_recipient_label->setObjectName(QString::fromUtf8("unitcommunication_recipient_label"));
        unitcommunication_recipient_label->setGeometry(QRect(30, 30, 91, 16));
        unitcommunication_message_label = new QLabel(unitcommunication_frame);
        unitcommunication_message_label->setObjectName(QString::fromUtf8("unitcommunication_message_label"));
        unitcommunication_message_label->setGeometry(QRect(30, 80, 91, 21));
        unitcommmessage_text = new QPlainTextEdit(unitcommunication_frame);
        unitcommmessage_text->setObjectName(QString::fromUtf8("unitcommmessage_text"));
        unitcommmessage_text->setGeometry(QRect(110, 80, 321, 221));
        unitcommsend_button = new QPushButton(unitcommunication_frame);
        unitcommsend_button->setObjectName(QString::fromUtf8("unitcommsend_button"));
        unitcommsend_button->setGeometry(QRect(350, 320, 80, 23));
        unitcommcancel_button = new QPushButton(unitcommunication_frame);
        unitcommcancel_button->setObjectName(QString::fromUtf8("unitcommcancel_button"));
        unitcommcancel_button->setGeometry(QRect(110, 320, 80, 23));
        unitcommunication_combobox = new QComboBox(unitcommunication_frame);
        unitcommunication_combobox->setObjectName(QString::fromUtf8("unitcommunication_combobox"));
        unitcommunication_combobox->setGeometry(QRect(130, 30, 251, 23));
        configsettings_button = new QPushButton(UserHome);
        configsettings_button->setObjectName(QString::fromUtf8("configsettings_button"));
        configsettings_button->setGeometry(QRect(30, 350, 181, 41));
        survivor_button = new QPushButton(UserHome);
        survivor_button->setObjectName(QString::fromUtf8("survivor_button"));
        survivor_button->setGeometry(QRect(30, 430, 181, 41));
        messaging_frame = new QFrame(UserHome);
        messaging_frame->setObjectName(QString::fromUtf8("messaging_frame"));
        messaging_frame->setGeometry(QRect(260, 150, 461, 361));
        messaging_frame->setFrameShape(QFrame::StyledPanel);
        messaging_frame->setFrameShadow(QFrame::Raised);
        communityalerts_button = new QPushButton(messaging_frame);
        communityalerts_button->setObjectName(QString::fromUtf8("communityalerts_button"));
        communityalerts_button->setGeometry(QRect(130, 100, 221, 51));
        unitcommunication_button = new QPushButton(messaging_frame);
        unitcommunication_button->setObjectName(QString::fromUtf8("unitcommunication_button"));
        unitcommunication_button->setGeometry(QRect(130, 180, 221, 51));
        messaging_notiflabel = new QLabel(messaging_frame);
        messaging_notiflabel->setObjectName(QString::fromUtf8("messaging_notiflabel"));
        messaging_notiflabel->setGeometry(QRect(25, 50, 411, 21));
        communityalerts_frame = new QFrame(UserHome);
        communityalerts_frame->setObjectName(QString::fromUtf8("communityalerts_frame"));
        communityalerts_frame->setGeometry(QRect(260, 150, 461, 361));
        communityalerts_frame->setFrameShape(QFrame::StyledPanel);
        communityalerts_frame->setFrameShadow(QFrame::Raised);
        commalertmessage_label = new QLabel(communityalerts_frame);
        commalertmessage_label->setObjectName(QString::fromUtf8("commalertmessage_label"));
        commalertmessage_label->setGeometry(QRect(30, 50, 81, 21));
        commalertmessage_text = new QPlainTextEdit(communityalerts_frame);
        commalertmessage_text->setObjectName(QString::fromUtf8("commalertmessage_text"));
        commalertmessage_text->setGeometry(QRect(120, 50, 311, 241));
        commalertssend_button = new QPushButton(communityalerts_frame);
        commalertssend_button->setObjectName(QString::fromUtf8("commalertssend_button"));
        commalertssend_button->setGeometry(QRect(350, 310, 80, 23));
        commalertscancel_button = new QPushButton(communityalerts_frame);
        commalertscancel_button->setObjectName(QString::fromUtf8("commalertscancel_button"));
        commalertscancel_button->setGeometry(QRect(120, 310, 80, 23));
        acctmgmt_frame = new QFrame(UserHome);
        acctmgmt_frame->setObjectName(QString::fromUtf8("acctmgmt_frame"));
        acctmgmt_frame->setGeometry(QRect(260, 150, 461, 361));
        acctmgmt_frame->setFrameShape(QFrame::StyledPanel);
        acctmgmt_frame->setFrameShadow(QFrame::Raised);
        adduser_button = new QPushButton(acctmgmt_frame);
        adduser_button->setObjectName(QString::fromUtf8("adduser_button"));
        adduser_button->setGeometry(QRect(130, 100, 221, 51));
        modifyuser_button = new QPushButton(acctmgmt_frame);
        modifyuser_button->setObjectName(QString::fromUtf8("modifyuser_button"));
        modifyuser_button->setGeometry(QRect(130, 180, 221, 51));
        acctmgmt_notiflabel = new QLabel(acctmgmt_frame);
        acctmgmt_notiflabel->setObjectName(QString::fromUtf8("acctmgmt_notiflabel"));
        acctmgmt_notiflabel->setGeometry(QRect(33, 50, 401, 21));
        adduser_frame = new QFrame(UserHome);
        adduser_frame->setObjectName(QString::fromUtf8("adduser_frame"));
        adduser_frame->setGeometry(QRect(260, 150, 461, 361));
        adduser_frame->setFrameShape(QFrame::StyledPanel);
        adduser_frame->setFrameShadow(QFrame::Raised);
        adduser_username_label = new QLabel(adduser_frame);
        adduser_username_label->setObjectName(QString::fromUtf8("adduser_username_label"));
        adduser_username_label->setGeometry(QRect(70, 85, 101, 16));
        adduser_password_label = new QLabel(adduser_frame);
        adduser_password_label->setObjectName(QString::fromUtf8("adduser_password_label"));
        adduser_password_label->setGeometry(QRect(70, 125, 111, 16));
        adduser_retypepassword_label = new QLabel(adduser_frame);
        adduser_retypepassword_label->setObjectName(QString::fromUtf8("adduser_retypepassword_label"));
        adduser_retypepassword_label->setGeometry(QRect(70, 163, 141, 21));
        adduser_usernameline = new QLineEdit(adduser_frame);
        adduser_usernameline->setObjectName(QString::fromUtf8("adduser_usernameline"));
        adduser_usernameline->setGeometry(QRect(210, 80, 191, 23));
        adduser_passwordline = new QLineEdit(adduser_frame);
        adduser_passwordline->setObjectName(QString::fromUtf8("adduser_passwordline"));
        adduser_passwordline->setGeometry(QRect(210, 120, 191, 23));
        adduser_retypepasswordline = new QLineEdit(adduser_frame);
        adduser_retypepasswordline->setObjectName(QString::fromUtf8("adduser_retypepasswordline"));
        adduser_retypepasswordline->setGeometry(QRect(210, 160, 191, 23));
        addusersave_button = new QPushButton(adduser_frame);
        addusersave_button->setObjectName(QString::fromUtf8("addusersave_button"));
        addusersave_button->setGeometry(QRect(320, 260, 80, 23));
        addusercancel_button = new QPushButton(adduser_frame);
        addusercancel_button->setObjectName(QString::fromUtf8("addusercancel_button"));
        addusercancel_button->setGeometry(QRect(70, 260, 80, 23));
        logout_frame = new QFrame(UserHome);
        logout_frame->setObjectName(QString::fromUtf8("logout_frame"));
        logout_frame->setGeometry(QRect(0, 0, 781, 541));
        logout_frame->setFrameShape(QFrame::StyledPanel);
        logout_frame->setFrameShadow(QFrame::Raised);
        logout_frame->setLineWidth(0);
        logo_picture = new QLabel(logout_frame);
        logo_picture->setObjectName(QString::fromUtf8("logo_picture"));
        logo_picture->setGeometry(QRect(260, 200, 241, 91));
        logo_picture->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logo_picture->setScaledContents(true);
        logout_message_label = new QLabel(logout_frame);
        logout_message_label->setObjectName(QString::fromUtf8("logout_message_label"));
        logout_message_label->setGeometry(QRect(200, 300, 401, 41));
        QFont font1;
        font1.setPointSize(10);
        logout_message_label->setFont(font1);
        searchuser_frame = new QFrame(UserHome);
        searchuser_frame->setObjectName(QString::fromUtf8("searchuser_frame"));
        searchuser_frame->setGeometry(QRect(260, 150, 461, 361));
        searchuser_frame->setFrameShape(QFrame::StyledPanel);
        searchuser_frame->setFrameShadow(QFrame::Raised);
        searchuserline = new QLineEdit(searchuser_frame);
        searchuserline->setObjectName(QString::fromUtf8("searchuserline"));
        searchuserline->setGeometry(QRect(100, 70, 201, 23));
        searchuser_button = new QPushButton(searchuser_frame);
        searchuser_button->setObjectName(QString::fromUtf8("searchuser_button"));
        searchuser_button->setGeometry(QRect(330, 70, 80, 23));
        searchuser_button->setDefault(true);
        searchuser_username_label = new QLabel(searchuser_frame);
        searchuser_username_label->setObjectName(QString::fromUtf8("searchuser_username_label"));
        searchuser_username_label->setGeometry(QRect(20, 75, 71, 16));
        searchuser_label = new QLabel(searchuser_frame);
        searchuser_label->setObjectName(QString::fromUtf8("searchuser_label"));
        searchuser_label->setGeometry(QRect(30, 100, 381, 20));
        tmsi_frame = new QFrame(UserHome);
        tmsi_frame->setObjectName(QString::fromUtf8("tmsi_frame"));
        tmsi_frame->setGeometry(QRect(260, 150, 461, 361));
        tmsi_frame->setFrameShape(QFrame::StyledPanel);
        tmsi_frame->setFrameShadow(QFrame::Raised);
        tmsi_tableview = new QTableView(tmsi_frame);
        tmsi_tableview->setObjectName(QString::fromUtf8("tmsi_tableview"));
        tmsi_tableview->setGeometry(QRect(20, 20, 421, 311));
        emergency911_frame = new QFrame(UserHome);
        emergency911_frame->setObjectName(QString::fromUtf8("emergency911_frame"));
        emergency911_frame->setGeometry(QRect(260, 150, 461, 361));
        emergency911_frame->setFrameShape(QFrame::StyledPanel);
        emergency911_frame->setFrameShadow(QFrame::Raised);
        e911_tableView = new QTableView(emergency911_frame);
        e911_tableView->setObjectName(QString::fromUtf8("e911_tableView"));
        e911_tableView->setGeometry(QRect(30, 60, 401, 271));
        e911_date_label = new QLabel(emergency911_frame);
        e911_date_label->setObjectName(QString::fromUtf8("e911_date_label"));
        e911_date_label->setGeometry(QRect(70, 30, 41, 16));
        e911_month_combobox = new QComboBox(emergency911_frame);
        e911_month_combobox->setObjectName(QString::fromUtf8("e911_month_combobox"));
        e911_month_combobox->setGeometry(QRect(220, 25, 101, 23));
        e911_day_combobox = new QComboBox(emergency911_frame);
        e911_day_combobox->setObjectName(QString::fromUtf8("e911_day_combobox"));
        e911_day_combobox->setGeometry(QRect(340, 25, 51, 23));
        e911_year_combobox = new QComboBox(emergency911_frame);
        e911_year_combobox->setObjectName(QString::fromUtf8("e911_year_combobox"));
        e911_year_combobox->setGeometry(QRect(120, 25, 79, 23));
        configsettings_frame = new QFrame(UserHome);
        configsettings_frame->setObjectName(QString::fromUtf8("configsettings_frame"));
        configsettings_frame->setGeometry(QRect(260, 150, 461, 361));
        configsettings_frame->setFrameShape(QFrame::StyledPanel);
        configsettings_frame->setFrameShadow(QFrame::Raised);
        addconfig_button = new QPushButton(configsettings_frame);
        addconfig_button->setObjectName(QString::fromUtf8("addconfig_button"));
        addconfig_button->setGeometry(QRect(130, 100, 221, 51));
        modifyconfig_button = new QPushButton(configsettings_frame);
        modifyconfig_button->setObjectName(QString::fromUtf8("modifyconfig_button"));
        modifyconfig_button->setGeometry(QRect(130, 180, 221, 51));
        config_notiflabel = new QLabel(configsettings_frame);
        config_notiflabel->setObjectName(QString::fromUtf8("config_notiflabel"));
        config_notiflabel->setGeometry(QRect(33, 50, 401, 21));
        modifyconfig_button->raise();
        config_notiflabel->raise();
        addconfig_button->raise();
        modifyconfig_frame = new QFrame(UserHome);
        modifyconfig_frame->setObjectName(QString::fromUtf8("modifyconfig_frame"));
        modifyconfig_frame->setGeometry(QRect(260, 150, 461, 361));
        modifyconfig_frame->setFrameShape(QFrame::StyledPanel);
        modifyconfig_frame->setFrameShadow(QFrame::Raised);
        configsettings_comboBox = new QComboBox(modifyconfig_frame);
        configsettings_comboBox->setObjectName(QString::fromUtf8("configsettings_comboBox"));
        configsettings_comboBox->setGeometry(QRect(60, 60, 331, 23));
        configsettings_oldvalue_label = new QLabel(modifyconfig_frame);
        configsettings_oldvalue_label->setObjectName(QString::fromUtf8("configsettings_oldvalue_label"));
        configsettings_oldvalue_label->setGeometry(QRect(60, 165, 81, 16));
        configsettings_newvalue_label = new QLabel(modifyconfig_frame);
        configsettings_newvalue_label->setObjectName(QString::fromUtf8("configsettings_newvalue_label"));
        configsettings_newvalue_label->setGeometry(QRect(60, 215, 81, 16));
        configsettings_oldvalue_line = new QLineEdit(modifyconfig_frame);
        configsettings_oldvalue_line->setObjectName(QString::fromUtf8("configsettings_oldvalue_line"));
        configsettings_oldvalue_line->setEnabled(false);
        configsettings_oldvalue_line->setGeometry(QRect(140, 160, 251, 23));
        configsettings_newvalue_line = new QLineEdit(modifyconfig_frame);
        configsettings_newvalue_line->setObjectName(QString::fromUtf8("configsettings_newvalue_line"));
        configsettings_newvalue_line->setGeometry(QRect(140, 210, 251, 23));
        configsettings_cancel_button = new QPushButton(modifyconfig_frame);
        configsettings_cancel_button->setObjectName(QString::fromUtf8("configsettings_cancel_button"));
        configsettings_cancel_button->setGeometry(QRect(140, 290, 80, 23));
        configsettings_save_button = new QPushButton(modifyconfig_frame);
        configsettings_save_button->setObjectName(QString::fromUtf8("configsettings_save_button"));
        configsettings_save_button->setGeometry(QRect(310, 290, 80, 23));
        configsettings_edit_radiobutton = new QRadioButton(modifyconfig_frame);
        configsettings_edit_radiobutton->setObjectName(QString::fromUtf8("configsettings_edit_radiobutton"));
        configsettings_edit_radiobutton->setGeometry(QRect(60, 110, 100, 21));
        configsettings_delete_radiobutton = new QRadioButton(modifyconfig_frame);
        configsettings_delete_radiobutton->setObjectName(QString::fromUtf8("configsettings_delete_radiobutton"));
        configsettings_delete_radiobutton->setGeometry(QRect(220, 110, 100, 21));
        addconfig_frame = new QFrame(UserHome);
        addconfig_frame->setObjectName(QString::fromUtf8("addconfig_frame"));
        addconfig_frame->setGeometry(QRect(260, 150, 461, 361));
        addconfig_frame->setFrameShape(QFrame::StyledPanel);
        addconfig_frame->setFrameShadow(QFrame::Raised);
        configsettings_create_name_label = new QLabel(addconfig_frame);
        configsettings_create_name_label->setObjectName(QString::fromUtf8("configsettings_create_name_label"));
        configsettings_create_name_label->setGeometry(QRect(60, 107, 91, 31));
        configsettings_value_name_label = new QLabel(addconfig_frame);
        configsettings_value_name_label->setObjectName(QString::fromUtf8("configsettings_value_name_label"));
        configsettings_value_name_label->setGeometry(QRect(60, 165, 57, 15));
        configsettings_comment_name_label = new QLabel(addconfig_frame);
        configsettings_comment_name_label->setObjectName(QString::fromUtf8("configsettings_comment_name_label"));
        configsettings_comment_name_label->setGeometry(QRect(60, 215, 71, 16));
        configsettings_name_line = new QLineEdit(addconfig_frame);
        configsettings_name_line->setObjectName(QString::fromUtf8("configsettings_name_line"));
        configsettings_name_line->setGeometry(QRect(160, 110, 251, 23));
        configsettings_value_line = new QLineEdit(addconfig_frame);
        configsettings_value_line->setObjectName(QString::fromUtf8("configsettings_value_line"));
        configsettings_value_line->setGeometry(QRect(160, 160, 251, 23));
        configsettings_comment_line = new QLineEdit(addconfig_frame);
        configsettings_comment_line->setObjectName(QString::fromUtf8("configsettings_comment_line"));
        configsettings_comment_line->setGeometry(QRect(160, 210, 251, 23));
        configsettings_createcancel_button = new QPushButton(addconfig_frame);
        configsettings_createcancel_button->setObjectName(QString::fromUtf8("configsettings_createcancel_button"));
        configsettings_createcancel_button->setGeometry(QRect(140, 290, 80, 23));
        configsettings_createsave_button = new QPushButton(addconfig_frame);
        configsettings_createsave_button->setObjectName(QString::fromUtf8("configsettings_createsave_button"));
        configsettings_createsave_button->setGeometry(QRect(310, 290, 80, 23));
        logout_frame->raise();
        acctmgmt_button->raise();
        logo_upperleft->raise();
        line_separator->raise();
        username_label->raise();
        logoutbutton->raise();
        home_button->raise();
        rates_button->raise();
        historylogs_button->raise();
        configsettings_button->raise();
        survivor_button->raise();
        adduser_frame->raise();
        unitcommunication_frame->raise();
        searchuser_frame->raise();
        connectionstatus_button->raise();
        communityalerts_frame->raise();
        emergency911_frame->raise();
        historylogs_frame->raise();
        configsettings_frame->raise();
        tmsi_frame->raise();
        rates_frame->raise();
        acctmgmt_frame->raise();
        userhome_frame->raise();
        messaging_button->raise();
        messaging_frame->raise();
        modifyuser_frame->raise();
        addconfig_frame->raise();
        modifyconfig_frame->raise();

        retranslateUi(UserHome);

        QMetaObject::connectSlotsByName(UserHome);
    } // setupUi

    void retranslateUi(QDialog *UserHome)
    {
        UserHome->setWindowTitle(QApplication::translate("UserHome", "Dialog", 0));
        logo_upperleft->setText(QString());
        username_label->setText(QString());
        logoutbutton->setText(QApplication::translate("UserHome", "Logout", 0));
        userhomelabel->setText(QApplication::translate("UserHome", "Login Details:", 0));
        usernamelabel->setText(QApplication::translate("UserHome", "Username: ", 0));
        lastloginlabel->setText(QApplication::translate("UserHome", "Last Successful Login:", 0));
        lasterrorlabel->setText(QApplication::translate("UserHome", "Last Failed Login:", 0));
        home_button->setText(QApplication::translate("UserHome", "Home", 0));
        messaging_button->setText(QApplication::translate("UserHome", "Messaging", 0));
        acctmgmt_button->setText(QApplication::translate("UserHome", "Accounts Management", 0));
        rates_button->setText(QApplication::translate("UserHome", "Rates Management", 0));
        connectionstatus_button->setText(QApplication::translate("UserHome", "Connection Status", 0));
        historylogs_button->setText(QApplication::translate("UserHome", "History Logs", 0));
        rates_servicetype_label->setText(QApplication::translate("UserHome", "Service Type:", 0));
        rates_oldrate_label->setText(QApplication::translate("UserHome", "Old rate:", 0));
        rates_newrate_label->setText(QApplication::translate("UserHome", "New rate:", 0));
        rates_savebutton->setText(QApplication::translate("UserHome", "Save", 0));
        rates_cancelbutton->setText(QApplication::translate("UserHome", "Reset", 0));
        modifyuser_username_label->setText(QApplication::translate("UserHome", "Username: ", 0));
        changepass_checkbox->setText(QApplication::translate("UserHome", "Change Password", 0));
        changeshortcode_checkbox->setText(QApplication::translate("UserHome", "Change Shortcode", 0));
        changepasswordgroup->setTitle(QString());
        modifyuser_newpassword_label->setText(QApplication::translate("UserHome", "New Password:", 0));
        modifyuser_confirmnew_label->setText(QApplication::translate("UserHome", "Confirm New:", 0));
        modifyuser_oldpassword_label->setText(QApplication::translate("UserHome", "Old Password:", 0));
        changeshortcodegroup->setTitle(QString());
        oldshortcode_label->setText(QApplication::translate("UserHome", "Old Shortcode: ", 0));
        modifyuser_newshortcode_label->setText(QApplication::translate("UserHome", "New Shortcode:", 0));
        modifyprivilegesgroup->setTitle(QString());
        grantrates_checkbox->setText(QApplication::translate("UserHome", "Rates", 0));
        grantadduser_checkbox->setText(QApplication::translate("UserHome", "Add User", 0));
        grantshortcodes_checkbox->setText(QApplication::translate("UserHome", "Shortcodes", 0));
        grantmodifyuser_checkbox->setText(QApplication::translate("UserHome", "Modify User", 0));
        grantsendalerts_checkbox->setText(QApplication::translate("UserHome", "Send Alerts", 0));
        granthistlogs_checkbox->setText(QApplication::translate("UserHome", "History Logs", 0));
        grantconfigsettings_checkbox->setText(QApplication::translate("UserHome", "Config Settings", 0));
        grantsurvrecord_checkbox->setText(QApplication::translate("UserHome", "Survivor Records", 0));
        grantmodpriv_checkbox->setText(QApplication::translate("UserHome", "Modify Privileges", 0));
        modifypriv_checkbox->setText(QApplication::translate("UserHome", "Modify Privileges", 0));
        saveacctbutton->setText(QApplication::translate("UserHome", "Save", 0));
        acctmgmt_cancelbutton->setText(QApplication::translate("UserHome", "Back", 0));
        modprivusername_label->setText(QString());
        historylogs_date_label->setText(QApplication::translate("UserHome", "Date:", 0));
        month_combobox->clear();
        month_combobox->insertItems(0, QStringList()
         << QApplication::translate("UserHome", "January", 0)
         << QApplication::translate("UserHome", "February", 0)
         << QApplication::translate("UserHome", "March", 0)
         << QApplication::translate("UserHome", "April", 0)
         << QApplication::translate("UserHome", "May", 0)
         << QApplication::translate("UserHome", "June", 0)
         << QApplication::translate("UserHome", "July", 0)
         << QApplication::translate("UserHome", "August", 0)
         << QApplication::translate("UserHome", "September", 0)
         << QApplication::translate("UserHome", "October", 0)
         << QApplication::translate("UserHome", "November", 0)
         << QApplication::translate("UserHome", "December", 0)
        );
        unitcommunication_recipient_label->setText(QApplication::translate("UserHome", "Recipient/s:", 0));
        unitcommunication_message_label->setText(QApplication::translate("UserHome", "Message:", 0));
        unitcommsend_button->setText(QApplication::translate("UserHome", "Send", 0));
        unitcommcancel_button->setText(QApplication::translate("UserHome", "Cancel", 0));
        configsettings_button->setText(QApplication::translate("UserHome", "Config Settings", 0));
        survivor_button->setText(QApplication::translate("UserHome", "Survivor Recording", 0));
        communityalerts_button->setText(QApplication::translate("UserHome", "Community Alerts\n"
"(Send To All Connected)", 0));
        unitcommunication_button->setText(QApplication::translate("UserHome", "Unit Communication\n"
"(Send To Specific Person)", 0));
        messaging_notiflabel->setText(QString());
        commalertmessage_label->setText(QApplication::translate("UserHome", "Message:", 0));
        commalertssend_button->setText(QApplication::translate("UserHome", "Send", 0));
        commalertscancel_button->setText(QApplication::translate("UserHome", "Cancel", 0));
        adduser_button->setText(QApplication::translate("UserHome", "Add User", 0));
        modifyuser_button->setText(QApplication::translate("UserHome", "Modify User", 0));
        acctmgmt_notiflabel->setText(QString());
        adduser_username_label->setText(QApplication::translate("UserHome", "Username:", 0));
        adduser_password_label->setText(QApplication::translate("UserHome", "Password:", 0));
        adduser_retypepassword_label->setText(QApplication::translate("UserHome", "Re-type Password:", 0));
        addusersave_button->setText(QApplication::translate("UserHome", "Add User", 0));
        addusercancel_button->setText(QApplication::translate("UserHome", "Cancel", 0));
        logo_picture->setText(QString());
        logout_message_label->setText(QApplication::translate("UserHome", "You have successfully logged out of the Communect System.", 0));
        searchuser_button->setText(QApplication::translate("UserHome", "Search", 0));
        searchuser_username_label->setText(QApplication::translate("UserHome", "Username", 0));
        searchuser_label->setText(QString());
        e911_date_label->setText(QApplication::translate("UserHome", "Date:", 0));
        e911_month_combobox->clear();
        e911_month_combobox->insertItems(0, QStringList()
         << QApplication::translate("UserHome", "January", 0)
         << QApplication::translate("UserHome", "February", 0)
         << QApplication::translate("UserHome", "March", 0)
         << QApplication::translate("UserHome", "April", 0)
         << QApplication::translate("UserHome", "May", 0)
         << QApplication::translate("UserHome", "June", 0)
         << QApplication::translate("UserHome", "July", 0)
         << QApplication::translate("UserHome", "August", 0)
         << QApplication::translate("UserHome", "September", 0)
         << QApplication::translate("UserHome", "October", 0)
         << QApplication::translate("UserHome", "November", 0)
         << QApplication::translate("UserHome", "December", 0)
        );
        addconfig_button->setText(QApplication::translate("UserHome", "Add Config", 0));
        modifyconfig_button->setText(QApplication::translate("UserHome", "Modify/Delete Config", 0));
        config_notiflabel->setText(QString());
        configsettings_oldvalue_label->setText(QApplication::translate("UserHome", "Old Value:", 0));
        configsettings_newvalue_label->setText(QApplication::translate("UserHome", "New value:", 0));
        configsettings_cancel_button->setText(QApplication::translate("UserHome", "Reset", 0));
        configsettings_save_button->setText(QApplication::translate("UserHome", "Save", 0));
        configsettings_edit_radiobutton->setText(QApplication::translate("UserHome", "Edit", 0));
        configsettings_delete_radiobutton->setText(QApplication::translate("UserHome", "Delete", 0));
        configsettings_create_name_label->setText(QApplication::translate("UserHome", "Config name:", 0));
        configsettings_value_name_label->setText(QApplication::translate("UserHome", "Value:", 0));
        configsettings_comment_name_label->setText(QApplication::translate("UserHome", "Comment:", 0));
        configsettings_createcancel_button->setText(QApplication::translate("UserHome", "Reset", 0));
        configsettings_createsave_button->setText(QApplication::translate("UserHome", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class UserHome: public Ui_UserHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHOME_H
