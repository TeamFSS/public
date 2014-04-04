/********************************************************************************
** Form generated from reading UI file 'userhome.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserHome
{
public:
    QLabel *logo_upperleft;
    QFrame *line_separator;
    QLabel *username_label;
    QPushButton *logoutbutton;
    QFrame *userhome_frame;
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
    QGroupBox *modifyprivilegesgroup;
    QCheckBox *grantrates_checkbox;
    QCheckBox *grantmodpriv_checkbox;
    QCheckBox *grantadduser_checkbox;
    QCheckBox *grantshortcodes_checkbox;
    QCheckBox *modifypriv_checkbox;
    QPushButton *saveacctbutton;
    QPushButton *acctmgmt_cancelbutton;
    QLabel *modprivusername_label;
    QFrame *historylogs_frame;
    QLabel *historylogs_date_label;
    QTableView *historylogs_tableview;
    QFrame *unitcommunication_frame;
    QLabel *unitcommunication_recipient_label;
    QLabel *unitcommunication_message_label;
    QPlainTextEdit *unitcommmessage_text;
    QPushButton *unitcommsend_button;
    QPushButton *unitcommcancel_button;
    QComboBox *unitcommunication_combobox;
    QPushButton *configsettings_button;
    QPushButton *help_button;
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
    QFrame *configsettings_frame;
    QComboBox *configsettings_comboBox;
    QCheckBox *configsettings_checkBox;
    QLabel *configsettings_oldvalue_label;
    QLabel *configsettings_newvalue_label;
    QLabel *configsettings_configs_label;
    QLineEdit *configsettings_newvalue_line;
    QPushButton *configsettings_save_button;
    QPushButton *configsettings_cancel_button;
    QFrame *help_frame;
    QPlainTextEdit *help_commandresult;
    QScrollBar *verticalScrollBar;
    QFrame *frame_2;
    QPushButton *help_calls;
    QPushButton *help_alarms;
    QPushButton *help_crashme;
    QPushButton *help_noise;
    QPushButton *help_regperiod;
    QPushButton *help_uptime;
    QPushButton *help_exit;
    QPushButton *help_notices;
    QPushButton *help_rxgain;
    QPushButton *help_version;
    QPushButton *help_cellid;
    QPushButton *help_help;
    QPushButton *help_page;
    QPushButton *help_stats;
    QPushButton *help_chans;
    QPushButton *help_load;
    QPushButton *help_power;
    QPushButton *help_tmsis;
    QPushButton *pushButton;
    QLabel *help_commandlabel;
    QWidget *gridLayoutWidget;
    QGridLayout *help_gridLayout;
    QFrame *logout_frame;
    QLabel *logo_picture;
    QLabel *logout_message_label;
    QPushButton *logout_signin_button;
    QFrame *searchuser_frame;
    QLineEdit *searchuserline;
    QPushButton *searchuser_button;
    QLabel *searchuser_username_label;
    QLabel *searchuser_label;
    QFrame *tmsi_frame;
    QTableView *tmsi_tableview;

    void setupUi(QDialog *UserHome)
    {
        if (UserHome->objectName().isEmpty())
            UserHome->setObjectName(QStringLiteral("UserHome"));
        UserHome->resize(750, 535);
        logo_upperleft = new QLabel(UserHome);
        logo_upperleft->setObjectName(QStringLiteral("logo_upperleft"));
        logo_upperleft->setGeometry(QRect(10, 20, 201, 81));
        logo_upperleft->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logo_upperleft->setScaledContents(true);
        line_separator = new QFrame(UserHome);
        line_separator->setObjectName(QStringLiteral("line_separator"));
        line_separator->setGeometry(QRect(20, 90, 711, 16));
        line_separator->setFrameShape(QFrame::HLine);
        line_separator->setFrameShadow(QFrame::Sunken);
        username_label = new QLabel(UserHome);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        username_label->setFont(font);
        logoutbutton = new QPushButton(UserHome);
        logoutbutton->setObjectName(QStringLiteral("logoutbutton"));
        logoutbutton->setGeometry(QRect(669, 70, 61, 23));
        userhome_frame = new QFrame(UserHome);
        userhome_frame->setObjectName(QStringLiteral("userhome_frame"));
        userhome_frame->setGeometry(QRect(260, 150, 461, 361));
        userhome_frame->setFrameShape(QFrame::StyledPanel);
        userhome_frame->setFrameShadow(QFrame::Raised);
        home_button = new QPushButton(UserHome);
        home_button->setObjectName(QStringLiteral("home_button"));
        home_button->setGeometry(QRect(30, 150, 181, 41));
        messaging_button = new QPushButton(UserHome);
        messaging_button->setObjectName(QStringLiteral("messaging_button"));
        messaging_button->setGeometry(QRect(30, 190, 181, 41));
        acctmgmt_button = new QPushButton(UserHome);
        acctmgmt_button->setObjectName(QStringLiteral("acctmgmt_button"));
        acctmgmt_button->setGeometry(QRect(30, 230, 181, 41));
        rates_button = new QPushButton(UserHome);
        rates_button->setObjectName(QStringLiteral("rates_button"));
        rates_button->setGeometry(QRect(30, 270, 181, 41));
        connectionstatus_button = new QPushButton(UserHome);
        connectionstatus_button->setObjectName(QStringLiteral("connectionstatus_button"));
        connectionstatus_button->setGeometry(QRect(30, 310, 181, 41));
        historylogs_button = new QPushButton(UserHome);
        historylogs_button->setObjectName(QStringLiteral("historylogs_button"));
        historylogs_button->setGeometry(QRect(30, 390, 181, 41));
        rates_frame = new QFrame(UserHome);
        rates_frame->setObjectName(QStringLiteral("rates_frame"));
        rates_frame->setGeometry(QRect(260, 150, 461, 361));
        rates_frame->setFrameShape(QFrame::StyledPanel);
        rates_frame->setFrameShadow(QFrame::Raised);
        rates_servicetype_label = new QLabel(rates_frame);
        rates_servicetype_label->setObjectName(QStringLiteral("rates_servicetype_label"));
        rates_servicetype_label->setGeometry(QRect(40, 40, 91, 16));
        rates_oldrate_label = new QLabel(rates_frame);
        rates_oldrate_label->setObjectName(QStringLiteral("rates_oldrate_label"));
        rates_oldrate_label->setGeometry(QRect(130, 95, 57, 15));
        rates_oldratelabel = new QLineEdit(rates_frame);
        rates_oldratelabel->setObjectName(QStringLiteral("rates_oldratelabel"));
        rates_oldratelabel->setGeometry(QRect(200, 90, 113, 23));
        rates_oldratelabel->setReadOnly(true);
        rates_newrate_label = new QLabel(rates_frame);
        rates_newrate_label->setObjectName(QStringLiteral("rates_newrate_label"));
        rates_newrate_label->setGeometry(QRect(130, 132, 61, 16));
        rates_newratelabel = new QLineEdit(rates_frame);
        rates_newratelabel->setObjectName(QStringLiteral("rates_newratelabel"));
        rates_newratelabel->setGeometry(QRect(200, 130, 113, 23));
        rates_savebutton = new QPushButton(rates_frame);
        rates_savebutton->setObjectName(QStringLiteral("rates_savebutton"));
        rates_savebutton->setGeometry(QRect(270, 230, 80, 23));
        rates_cancelbutton = new QPushButton(rates_frame);
        rates_cancelbutton->setObjectName(QStringLiteral("rates_cancelbutton"));
        rates_cancelbutton->setGeometry(QRect(150, 230, 80, 23));
        rates_combobox = new QComboBox(rates_frame);
        rates_combobox->setObjectName(QStringLiteral("rates_combobox"));
        rates_combobox->setGeometry(QRect(150, 37, 241, 23));
        modifyuser_frame = new QFrame(UserHome);
        modifyuser_frame->setObjectName(QStringLiteral("modifyuser_frame"));
        modifyuser_frame->setGeometry(QRect(260, 150, 461, 361));
        modifyuser_frame->setFrameShape(QFrame::StyledPanel);
        modifyuser_frame->setFrameShadow(QFrame::Raised);
        modifyuser_username_label = new QLabel(modifyuser_frame);
        modifyuser_username_label->setObjectName(QStringLiteral("modifyuser_username_label"));
        modifyuser_username_label->setGeometry(QRect(20, 20, 71, 16));
        changepass_checkbox = new QCheckBox(modifyuser_frame);
        changepass_checkbox->setObjectName(QStringLiteral("changepass_checkbox"));
        changepass_checkbox->setGeometry(QRect(20, 40, 221, 21));
        changeshortcode_checkbox = new QCheckBox(modifyuser_frame);
        changeshortcode_checkbox->setObjectName(QStringLiteral("changeshortcode_checkbox"));
        changeshortcode_checkbox->setGeometry(QRect(20, 170, 211, 21));
        changepasswordgroup = new QGroupBox(modifyuser_frame);
        changepasswordgroup->setObjectName(QStringLiteral("changepasswordgroup"));
        changepasswordgroup->setEnabled(false);
        changepasswordgroup->setGeometry(QRect(40, 40, 351, 121));
        confirmnewpassword_line = new QLineEdit(changepasswordgroup);
        confirmnewpassword_line->setObjectName(QStringLiteral("confirmnewpassword_line"));
        confirmnewpassword_line->setGeometry(QRect(140, 92, 141, 23));
        modifyuser_newpassword_label = new QLabel(changepasswordgroup);
        modifyuser_newpassword_label->setObjectName(QStringLiteral("modifyuser_newpassword_label"));
        modifyuser_newpassword_label->setGeometry(QRect(10, 64, 121, 16));
        modifyuser_confirmnew_label = new QLabel(changepasswordgroup);
        modifyuser_confirmnew_label->setObjectName(QStringLiteral("modifyuser_confirmnew_label"));
        modifyuser_confirmnew_label->setGeometry(QRect(10, 94, 131, 21));
        newpassword_line = new QLineEdit(changepasswordgroup);
        newpassword_line->setObjectName(QStringLiteral("newpassword_line"));
        newpassword_line->setGeometry(QRect(140, 62, 141, 23));
        modifyuser_oldpassword_label = new QLabel(changepasswordgroup);
        modifyuser_oldpassword_label->setObjectName(QStringLiteral("modifyuser_oldpassword_label"));
        modifyuser_oldpassword_label->setGeometry(QRect(10, 34, 121, 21));
        oldpasswordline = new QLineEdit(changepasswordgroup);
        oldpasswordline->setObjectName(QStringLiteral("oldpasswordline"));
        oldpasswordline->setGeometry(QRect(140, 30, 141, 23));
        changeshortcodegroup = new QGroupBox(modifyuser_frame);
        changeshortcodegroup->setObjectName(QStringLiteral("changeshortcodegroup"));
        changeshortcodegroup->setEnabled(false);
        changeshortcodegroup->setGeometry(QRect(40, 170, 281, 80));
        newshortcode_line = new QLineEdit(changeshortcodegroup);
        newshortcode_line->setObjectName(QStringLiteral("newshortcode_line"));
        newshortcode_line->setGeometry(QRect(140, 50, 141, 23));
        oldshortcode_label = new QLabel(changeshortcodegroup);
        oldshortcode_label->setObjectName(QStringLiteral("oldshortcode_label"));
        oldshortcode_label->setGeometry(QRect(10, 30, 221, 16));
        modifyuser_newshortcode_label = new QLabel(changeshortcodegroup);
        modifyuser_newshortcode_label->setObjectName(QStringLiteral("modifyuser_newshortcode_label"));
        modifyuser_newshortcode_label->setGeometry(QRect(10, 55, 151, 16));
        modifyprivilegesgroup = new QGroupBox(modifyuser_frame);
        modifyprivilegesgroup->setObjectName(QStringLiteral("modifyprivilegesgroup"));
        modifyprivilegesgroup->setEnabled(true);
        modifyprivilegesgroup->setGeometry(QRect(40, 260, 271, 91));
        grantrates_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantrates_checkbox->setObjectName(QStringLiteral("grantrates_checkbox"));
        grantrates_checkbox->setGeometry(QRect(20, 30, 85, 21));
        grantmodpriv_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantmodpriv_checkbox->setObjectName(QStringLiteral("grantmodpriv_checkbox"));
        grantmodpriv_checkbox->setGeometry(QRect(20, 55, 211, 21));
        grantadduser_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantadduser_checkbox->setObjectName(QStringLiteral("grantadduser_checkbox"));
        grantadduser_checkbox->setGeometry(QRect(160, 30, 91, 21));
        grantshortcodes_checkbox = new QCheckBox(modifyprivilegesgroup);
        grantshortcodes_checkbox->setObjectName(QStringLiteral("grantshortcodes_checkbox"));
        grantshortcodes_checkbox->setGeometry(QRect(160, 55, 101, 21));
        modifypriv_checkbox = new QCheckBox(modifyuser_frame);
        modifypriv_checkbox->setObjectName(QStringLiteral("modifypriv_checkbox"));
        modifypriv_checkbox->setGeometry(QRect(20, 260, 231, 21));
        saveacctbutton = new QPushButton(modifyuser_frame);
        saveacctbutton->setObjectName(QStringLiteral("saveacctbutton"));
        saveacctbutton->setGeometry(QRect(360, 330, 80, 23));
        acctmgmt_cancelbutton = new QPushButton(modifyuser_frame);
        acctmgmt_cancelbutton->setObjectName(QStringLiteral("acctmgmt_cancelbutton"));
        acctmgmt_cancelbutton->setGeometry(QRect(270, 330, 80, 23));
        modprivusername_label = new QLabel(modifyuser_frame);
        modprivusername_label->setObjectName(QStringLiteral("modprivusername_label"));
        modprivusername_label->setGeometry(QRect(100, 20, 291, 16));
        historylogs_frame = new QFrame(UserHome);
        historylogs_frame->setObjectName(QStringLiteral("historylogs_frame"));
        historylogs_frame->setGeometry(QRect(260, 150, 461, 361));
        historylogs_frame->setFrameShape(QFrame::StyledPanel);
        historylogs_frame->setFrameShadow(QFrame::Raised);
        historylogs_date_label = new QLabel(historylogs_frame);
        historylogs_date_label->setObjectName(QStringLiteral("historylogs_date_label"));
        historylogs_date_label->setGeometry(QRect(90, 30, 57, 15));
        historylogs_tableview = new QTableView(historylogs_frame);
        historylogs_tableview->setObjectName(QStringLiteral("historylogs_tableview"));
        historylogs_tableview->setGeometry(QRect(30, 60, 401, 271));
        unitcommunication_frame = new QFrame(UserHome);
        unitcommunication_frame->setObjectName(QStringLiteral("unitcommunication_frame"));
        unitcommunication_frame->setGeometry(QRect(260, 150, 461, 361));
        unitcommunication_frame->setFrameShape(QFrame::StyledPanel);
        unitcommunication_frame->setFrameShadow(QFrame::Raised);
        unitcommunication_recipient_label = new QLabel(unitcommunication_frame);
        unitcommunication_recipient_label->setObjectName(QStringLiteral("unitcommunication_recipient_label"));
        unitcommunication_recipient_label->setGeometry(QRect(30, 30, 91, 16));
        unitcommunication_message_label = new QLabel(unitcommunication_frame);
        unitcommunication_message_label->setObjectName(QStringLiteral("unitcommunication_message_label"));
        unitcommunication_message_label->setGeometry(QRect(30, 80, 91, 21));
        unitcommmessage_text = new QPlainTextEdit(unitcommunication_frame);
        unitcommmessage_text->setObjectName(QStringLiteral("unitcommmessage_text"));
        unitcommmessage_text->setGeometry(QRect(110, 80, 321, 221));
        unitcommsend_button = new QPushButton(unitcommunication_frame);
        unitcommsend_button->setObjectName(QStringLiteral("unitcommsend_button"));
        unitcommsend_button->setGeometry(QRect(350, 320, 80, 23));
        unitcommcancel_button = new QPushButton(unitcommunication_frame);
        unitcommcancel_button->setObjectName(QStringLiteral("unitcommcancel_button"));
        unitcommcancel_button->setGeometry(QRect(110, 320, 80, 23));
        unitcommunication_combobox = new QComboBox(unitcommunication_frame);
        unitcommunication_combobox->setObjectName(QStringLiteral("unitcommunication_combobox"));
        unitcommunication_combobox->setGeometry(QRect(130, 30, 251, 23));
        configsettings_button = new QPushButton(UserHome);
        configsettings_button->setObjectName(QStringLiteral("configsettings_button"));
        configsettings_button->setGeometry(QRect(30, 350, 181, 41));
        help_button = new QPushButton(UserHome);
        help_button->setObjectName(QStringLiteral("help_button"));
        help_button->setGeometry(QRect(30, 430, 181, 41));
        messaging_frame = new QFrame(UserHome);
        messaging_frame->setObjectName(QStringLiteral("messaging_frame"));
        messaging_frame->setGeometry(QRect(260, 150, 461, 361));
        messaging_frame->setFrameShape(QFrame::StyledPanel);
        messaging_frame->setFrameShadow(QFrame::Raised);
        communityalerts_button = new QPushButton(messaging_frame);
        communityalerts_button->setObjectName(QStringLiteral("communityalerts_button"));
        communityalerts_button->setGeometry(QRect(130, 100, 221, 51));
        unitcommunication_button = new QPushButton(messaging_frame);
        unitcommunication_button->setObjectName(QStringLiteral("unitcommunication_button"));
        unitcommunication_button->setGeometry(QRect(130, 180, 221, 51));
        messaging_notiflabel = new QLabel(messaging_frame);
        messaging_notiflabel->setObjectName(QStringLiteral("messaging_notiflabel"));
        messaging_notiflabel->setGeometry(QRect(115, 50, 241, 21));
        communityalerts_frame = new QFrame(UserHome);
        communityalerts_frame->setObjectName(QStringLiteral("communityalerts_frame"));
        communityalerts_frame->setGeometry(QRect(260, 150, 461, 361));
        communityalerts_frame->setFrameShape(QFrame::StyledPanel);
        communityalerts_frame->setFrameShadow(QFrame::Raised);
        commalertmessage_label = new QLabel(communityalerts_frame);
        commalertmessage_label->setObjectName(QStringLiteral("commalertmessage_label"));
        commalertmessage_label->setGeometry(QRect(30, 50, 81, 21));
        commalertmessage_text = new QPlainTextEdit(communityalerts_frame);
        commalertmessage_text->setObjectName(QStringLiteral("commalertmessage_text"));
        commalertmessage_text->setGeometry(QRect(120, 50, 311, 241));
        commalertssend_button = new QPushButton(communityalerts_frame);
        commalertssend_button->setObjectName(QStringLiteral("commalertssend_button"));
        commalertssend_button->setGeometry(QRect(350, 310, 80, 23));
        commalertscancel_button = new QPushButton(communityalerts_frame);
        commalertscancel_button->setObjectName(QStringLiteral("commalertscancel_button"));
        commalertscancel_button->setGeometry(QRect(120, 310, 80, 23));
        acctmgmt_frame = new QFrame(UserHome);
        acctmgmt_frame->setObjectName(QStringLiteral("acctmgmt_frame"));
        acctmgmt_frame->setGeometry(QRect(260, 150, 461, 361));
        acctmgmt_frame->setFrameShape(QFrame::StyledPanel);
        acctmgmt_frame->setFrameShadow(QFrame::Raised);
        adduser_button = new QPushButton(acctmgmt_frame);
        adduser_button->setObjectName(QStringLiteral("adduser_button"));
        adduser_button->setGeometry(QRect(130, 100, 221, 51));
        modifyuser_button = new QPushButton(acctmgmt_frame);
        modifyuser_button->setObjectName(QStringLiteral("modifyuser_button"));
        modifyuser_button->setGeometry(QRect(130, 180, 221, 51));
        acctmgmt_notiflabel = new QLabel(acctmgmt_frame);
        acctmgmt_notiflabel->setObjectName(QStringLiteral("acctmgmt_notiflabel"));
        acctmgmt_notiflabel->setGeometry(QRect(123, 50, 241, 21));
        adduser_frame = new QFrame(UserHome);
        adduser_frame->setObjectName(QStringLiteral("adduser_frame"));
        adduser_frame->setGeometry(QRect(260, 150, 461, 361));
        adduser_frame->setFrameShape(QFrame::StyledPanel);
        adduser_frame->setFrameShadow(QFrame::Raised);
        adduser_username_label = new QLabel(adduser_frame);
        adduser_username_label->setObjectName(QStringLiteral("adduser_username_label"));
        adduser_username_label->setGeometry(QRect(70, 85, 101, 16));
        adduser_password_label = new QLabel(adduser_frame);
        adduser_password_label->setObjectName(QStringLiteral("adduser_password_label"));
        adduser_password_label->setGeometry(QRect(70, 125, 111, 16));
        adduser_retypepassword_label = new QLabel(adduser_frame);
        adduser_retypepassword_label->setObjectName(QStringLiteral("adduser_retypepassword_label"));
        adduser_retypepassword_label->setGeometry(QRect(70, 163, 141, 21));
        adduser_usernameline = new QLineEdit(adduser_frame);
        adduser_usernameline->setObjectName(QStringLiteral("adduser_usernameline"));
        adduser_usernameline->setGeometry(QRect(210, 80, 191, 23));
        adduser_passwordline = new QLineEdit(adduser_frame);
        adduser_passwordline->setObjectName(QStringLiteral("adduser_passwordline"));
        adduser_passwordline->setGeometry(QRect(210, 120, 191, 23));
        adduser_retypepasswordline = new QLineEdit(adduser_frame);
        adduser_retypepasswordline->setObjectName(QStringLiteral("adduser_retypepasswordline"));
        adduser_retypepasswordline->setGeometry(QRect(210, 160, 191, 23));
        addusersave_button = new QPushButton(adduser_frame);
        addusersave_button->setObjectName(QStringLiteral("addusersave_button"));
        addusersave_button->setGeometry(QRect(320, 260, 80, 23));
        addusercancel_button = new QPushButton(adduser_frame);
        addusercancel_button->setObjectName(QStringLiteral("addusercancel_button"));
        addusercancel_button->setGeometry(QRect(70, 260, 80, 23));
        configsettings_frame = new QFrame(UserHome);
        configsettings_frame->setObjectName(QStringLiteral("configsettings_frame"));
        configsettings_frame->setGeometry(QRect(260, 150, 461, 361));
        configsettings_frame->setFrameShape(QFrame::StyledPanel);
        configsettings_frame->setFrameShadow(QFrame::Raised);
        configsettings_comboBox = new QComboBox(configsettings_frame);
        configsettings_comboBox->setObjectName(QStringLiteral("configsettings_comboBox"));
        configsettings_comboBox->setGeometry(QRect(100, 80, 271, 23));
        configsettings_checkBox = new QCheckBox(configsettings_frame);
        configsettings_checkBox->setObjectName(QStringLiteral("configsettings_checkBox"));
        configsettings_checkBox->setGeometry(QRect(120, 150, 85, 21));
        configsettings_oldvalue_label = new QLabel(configsettings_frame);
        configsettings_oldvalue_label->setObjectName(QStringLiteral("configsettings_oldvalue_label"));
        configsettings_oldvalue_label->setGeometry(QRect(120, 190, 111, 16));
        configsettings_newvalue_label = new QLabel(configsettings_frame);
        configsettings_newvalue_label->setObjectName(QStringLiteral("configsettings_newvalue_label"));
        configsettings_newvalue_label->setGeometry(QRect(120, 230, 121, 16));
        configsettings_configs_label = new QLabel(configsettings_frame);
        configsettings_configs_label->setObjectName(QStringLiteral("configsettings_configs_label"));
        configsettings_configs_label->setGeometry(QRect(40, 40, 57, 21));
        configsettings_newvalue_line = new QLineEdit(configsettings_frame);
        configsettings_newvalue_line->setObjectName(QStringLiteral("configsettings_newvalue_line"));
        configsettings_newvalue_line->setGeometry(QRect(220, 230, 131, 23));
        configsettings_save_button = new QPushButton(configsettings_frame);
        configsettings_save_button->setObjectName(QStringLiteral("configsettings_save_button"));
        configsettings_save_button->setGeometry(QRect(290, 290, 80, 23));
        configsettings_cancel_button = new QPushButton(configsettings_frame);
        configsettings_cancel_button->setObjectName(QStringLiteral("configsettings_cancel_button"));
        configsettings_cancel_button->setGeometry(QRect(100, 290, 80, 23));
        help_frame = new QFrame(UserHome);
        help_frame->setObjectName(QStringLiteral("help_frame"));
        help_frame->setGeometry(QRect(260, 150, 461, 361));
        help_frame->setFrameShape(QFrame::StyledPanel);
        help_frame->setFrameShadow(QFrame::Raised);
        help_commandresult = new QPlainTextEdit(help_frame);
        help_commandresult->setObjectName(QStringLiteral("help_commandresult"));
        help_commandresult->setEnabled(false);
        help_commandresult->setGeometry(QRect(20, 220, 421, 121));
        verticalScrollBar = new QScrollBar(help_frame);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(424, 200, 20, 141));
        verticalScrollBar->setOrientation(Qt::Vertical);
        frame_2 = new QFrame(help_frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(20, 10, 421, 159));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        help_calls = new QPushButton(frame_2);
        help_calls->setObjectName(QStringLiteral("help_calls"));
        help_calls->setGeometry(QRect(96, 10, 80, 23));
        help_alarms = new QPushButton(frame_2);
        help_alarms->setObjectName(QStringLiteral("help_alarms"));
        help_alarms->setGeometry(QRect(10, 10, 80, 23));
        help_crashme = new QPushButton(frame_2);
        help_crashme->setObjectName(QStringLiteral("help_crashme"));
        help_crashme->setGeometry(QRect(10, 39, 80, 23));
        help_noise = new QPushButton(frame_2);
        help_noise->setObjectName(QStringLiteral("help_noise"));
        help_noise->setGeometry(QRect(10, 68, 80, 23));
        help_regperiod = new QPushButton(frame_2);
        help_regperiod->setObjectName(QStringLiteral("help_regperiod"));
        help_regperiod->setGeometry(QRect(10, 97, 80, 23));
        help_uptime = new QPushButton(frame_2);
        help_uptime->setObjectName(QStringLiteral("help_uptime"));
        help_uptime->setGeometry(QRect(10, 126, 80, 23));
        help_exit = new QPushButton(frame_2);
        help_exit->setObjectName(QStringLiteral("help_exit"));
        help_exit->setGeometry(QRect(96, 39, 80, 23));
        help_notices = new QPushButton(frame_2);
        help_notices->setObjectName(QStringLiteral("help_notices"));
        help_notices->setGeometry(QRect(96, 68, 80, 23));
        help_rxgain = new QPushButton(frame_2);
        help_rxgain->setObjectName(QStringLiteral("help_rxgain"));
        help_rxgain->setGeometry(QRect(96, 97, 80, 23));
        help_version = new QPushButton(frame_2);
        help_version->setObjectName(QStringLiteral("help_version"));
        help_version->setGeometry(QRect(96, 126, 80, 23));
        help_cellid = new QPushButton(frame_2);
        help_cellid->setObjectName(QStringLiteral("help_cellid"));
        help_cellid->setGeometry(QRect(182, 10, 80, 23));
        help_help = new QPushButton(frame_2);
        help_help->setObjectName(QStringLiteral("help_help"));
        help_help->setGeometry(QRect(182, 39, 80, 23));
        help_page = new QPushButton(frame_2);
        help_page->setObjectName(QStringLiteral("help_page"));
        help_page->setGeometry(QRect(182, 68, 80, 23));
        help_stats = new QPushButton(frame_2);
        help_stats->setObjectName(QStringLiteral("help_stats"));
        help_stats->setGeometry(QRect(182, 97, 80, 23));
        help_chans = new QPushButton(frame_2);
        help_chans->setObjectName(QStringLiteral("help_chans"));
        help_chans->setGeometry(QRect(268, 10, 80, 23));
        help_load = new QPushButton(frame_2);
        help_load->setObjectName(QStringLiteral("help_load"));
        help_load->setGeometry(QRect(268, 39, 80, 23));
        help_power = new QPushButton(frame_2);
        help_power->setObjectName(QStringLiteral("help_power"));
        help_power->setGeometry(QRect(268, 68, 80, 23));
        help_tmsis = new QPushButton(frame_2);
        help_tmsis->setObjectName(QStringLiteral("help_tmsis"));
        help_tmsis->setGeometry(QRect(268, 97, 80, 23));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(182, 126, 80, 23));
        help_commandlabel = new QLabel(help_frame);
        help_commandlabel->setObjectName(QStringLiteral("help_commandlabel"));
        help_commandlabel->setGeometry(QRect(20, 190, 401, 21));
        gridLayoutWidget = new QWidget(help_frame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 190, 361, 131));
        help_gridLayout = new QGridLayout(gridLayoutWidget);
        help_gridLayout->setObjectName(QStringLiteral("help_gridLayout"));
        help_gridLayout->setContentsMargins(0, 0, 0, 0);
        help_commandresult->raise();
        verticalScrollBar->raise();
        help_commandlabel->raise();
        frame_2->raise();
        gridLayoutWidget->raise();
        logout_frame = new QFrame(UserHome);
        logout_frame->setObjectName(QStringLiteral("logout_frame"));
        logout_frame->setGeometry(QRect(0, 0, 781, 541));
        logout_frame->setFrameShape(QFrame::StyledPanel);
        logout_frame->setFrameShadow(QFrame::Raised);
        logout_frame->setLineWidth(0);
        logo_picture = new QLabel(logout_frame);
        logo_picture->setObjectName(QStringLiteral("logo_picture"));
        logo_picture->setGeometry(QRect(260, 170, 241, 91));
        logo_picture->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logo_picture->setScaledContents(true);
        logout_message_label = new QLabel(logout_frame);
        logout_message_label->setObjectName(QStringLiteral("logout_message_label"));
        logout_message_label->setGeometry(QRect(180, 270, 401, 41));
        QFont font1;
        font1.setPointSize(10);
        logout_message_label->setFont(font1);
        logout_signin_button = new QPushButton(logout_frame);
        logout_signin_button->setObjectName(QStringLiteral("logout_signin_button"));
        logout_signin_button->setGeometry(QRect(350, 330, 80, 23));
        searchuser_frame = new QFrame(UserHome);
        searchuser_frame->setObjectName(QStringLiteral("searchuser_frame"));
        searchuser_frame->setGeometry(QRect(260, 150, 461, 361));
        searchuser_frame->setFrameShape(QFrame::StyledPanel);
        searchuser_frame->setFrameShadow(QFrame::Raised);
        searchuserline = new QLineEdit(searchuser_frame);
        searchuserline->setObjectName(QStringLiteral("searchuserline"));
        searchuserline->setGeometry(QRect(100, 70, 201, 23));
        searchuser_button = new QPushButton(searchuser_frame);
        searchuser_button->setObjectName(QStringLiteral("searchuser_button"));
        searchuser_button->setGeometry(QRect(330, 70, 80, 23));
        searchuser_username_label = new QLabel(searchuser_frame);
        searchuser_username_label->setObjectName(QStringLiteral("searchuser_username_label"));
        searchuser_username_label->setGeometry(QRect(20, 75, 71, 16));
        searchuser_label = new QLabel(searchuser_frame);
        searchuser_label->setObjectName(QStringLiteral("searchuser_label"));
        searchuser_label->setGeometry(QRect(30, 100, 381, 20));
        tmsi_frame = new QFrame(UserHome);
        tmsi_frame->setObjectName(QStringLiteral("tmsi_frame"));
        tmsi_frame->setGeometry(QRect(260, 150, 461, 361));
        tmsi_frame->setFrameShape(QFrame::StyledPanel);
        tmsi_frame->setFrameShadow(QFrame::Raised);
        tmsi_tableview = new QTableView(tmsi_frame);
        tmsi_tableview->setObjectName(QStringLiteral("tmsi_tableview"));
        tmsi_tableview->setGeometry(QRect(20, 20, 421, 311));
        logo_upperleft->raise();
        line_separator->raise();
        username_label->raise();
        logoutbutton->raise();
        home_button->raise();
        messaging_button->raise();
        acctmgmt_button->raise();
        rates_button->raise();
        connectionstatus_button->raise();
        historylogs_button->raise();
        configsettings_button->raise();
        help_button->raise();
        acctmgmt_frame->raise();
        userhome_frame->raise();
        tmsi_frame->raise();
        help_frame->raise();
        messaging_frame->raise();
        adduser_frame->raise();
        communityalerts_frame->raise();
        configsettings_frame->raise();
        historylogs_frame->raise();
        modifyuser_frame->raise();
        rates_frame->raise();
        searchuser_frame->raise();
        unitcommunication_frame->raise();
        logout_frame->raise();

        retranslateUi(UserHome);

        QMetaObject::connectSlotsByName(UserHome);
    } // setupUi

    void retranslateUi(QDialog *UserHome)
    {
        UserHome->setWindowTitle(QApplication::translate("UserHome", "Dialog", 0));
        logo_upperleft->setText(QString());
        username_label->setText(QString());
        logoutbutton->setText(QApplication::translate("UserHome", "Logout", 0));
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
        rates_combobox->clear();
        rates_combobox->insertItems(0, QStringList()
         << QApplication::translate("UserHome", "in-network-SMS", 0)
         << QApplication::translate("UserHome", "out-of-network-SMS", 0)
         << QApplication::translate("UserHome", "in-network-call", 0)
         << QApplication::translate("UserHome", "out-of-network-call", 0)
        );
        modifyuser_username_label->setText(QApplication::translate("UserHome", "Username: ", 0));
        changepass_checkbox->setText(QApplication::translate("UserHome", "Change Password", 0));
        changeshortcode_checkbox->setText(QApplication::translate("UserHome", "Change Shortcode", 0));
        changepasswordgroup->setTitle(QString());
        modifyuser_newpassword_label->setText(QApplication::translate("UserHome", "New Password:", 0));
        modifyuser_confirmnew_label->setText(QApplication::translate("UserHome", "Confirm New:", 0));
        modifyuser_oldpassword_label->setText(QApplication::translate("UserHome", "Old Password:", 0));
        changeshortcodegroup->setTitle(QString());
        oldshortcode_label->setText(QApplication::translate("UserHome", "Old Shortcode: 12345", 0));
        modifyuser_newshortcode_label->setText(QApplication::translate("UserHome", "New Shortcode:", 0));
        modifyprivilegesgroup->setTitle(QString());
        grantrates_checkbox->setText(QApplication::translate("UserHome", "Rates", 0));
        grantmodpriv_checkbox->setText(QApplication::translate("UserHome", "Modify Privileges", 0));
        grantadduser_checkbox->setText(QApplication::translate("UserHome", "Add User", 0));
        grantshortcodes_checkbox->setText(QApplication::translate("UserHome", "Shortcodes", 0));
        modifypriv_checkbox->setText(QApplication::translate("UserHome", "Modify Privileges", 0));
        saveacctbutton->setText(QApplication::translate("UserHome", "Save", 0));
        acctmgmt_cancelbutton->setText(QApplication::translate("UserHome", "Back", 0));
        modprivusername_label->setText(QString());
        historylogs_date_label->setText(QApplication::translate("UserHome", "Date", 0));
        unitcommunication_recipient_label->setText(QApplication::translate("UserHome", "Recipient/s:", 0));
        unitcommunication_message_label->setText(QApplication::translate("UserHome", "Message:", 0));
        unitcommsend_button->setText(QApplication::translate("UserHome", "Send", 0));
        unitcommcancel_button->setText(QApplication::translate("UserHome", "Cancel", 0));
        configsettings_button->setText(QApplication::translate("UserHome", "Config Settings", 0));
        help_button->setText(QApplication::translate("UserHome", "Help", 0));
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
        configsettings_comboBox->clear();
        configsettings_comboBox->insertItems(0, QStringList()
         << QApplication::translate("UserHome", "CLI.SocketPath", 0)
         << QApplication::translate("UserHome", "Control.Reporting.PhysStatusTable", 0)
         << QApplication::translate("UserHome", "Control.Reporting.TransactionTable", 0)
         << QApplication::translate("UserHome", "Control.Reporting.StatsTable", 0)
         << QApplication::translate("UserHome", "Control.Reporting.TMSITable", 0)
         << QApplication::translate("UserHome", "Control.Call.QueryRRLP.Early", 0)
         << QApplication::translate("UserHome", "Control.Call.QueryRRLP.Late", 0)
         << QApplication::translate("UserHome", "Control.GSMTAP.TargetIP", 0)
         << QApplication::translate("UserHome", "Control.LUR.AttachDetach", 0)
         << QApplication::translate("UserHome", "Control.LUR.FailedRegistration.Message", 0)
         << QApplication::translate("UserHome", "Control.LUR.FailedRegistration.ShortCode", 0)
         << QApplication::translate("UserHome", "Control.LUR.NormalRegistration.Message", 0)
         << QApplication::translate("UserHome", "Control.LUR.NormalRegistration.ShortCode", 0)
         << QApplication::translate("UserHome", "Control.LUR.OpenRegistration.Message", 0)
         << QApplication::translate("UserHome", "Control.LUR.OpenRegistration.ShortCode", 0)
         << QApplication::translate("UserHome", "Control.LUR.QueryClassmark", 0)
         << QApplication::translate("UserHome", "Control.LUR.QueryIMEI", 0)
         << QApplication::translate("UserHome", "Control.LUR.QueryRRLP", 0)
         << QApplication::translate("UserHome", "Control.LUR.SendTMSIs", 0)
         << QApplication::translate("UserHome", "Control.LUR.UnprovisionedRejectCause", 0)
         << QApplication::translate("UserHome", "Control.NumSQLTries", 0)
         << QApplication::translate("UserHome", "Control.SMS.QueryRRLP", 0)
         << QApplication::translate("UserHome", "Control.TMSITable.MaxAge", 0)
         << QApplication::translate("UserHome", "Control.TMSITable.MaxSize", 0)
         << QApplication::translate("UserHome", "Control.VEA", 0)
         << QApplication::translate("UserHome", "GSM.CCCH.AGCH.QMax", 0)
         << QApplication::translate("UserHome", "GSM.CCCH.CCCH-CONF", 0)
         << QApplication::translate("UserHome", "GSM.Channels.SDCCHReserve", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.CELL-RESELECT-HYSTERESIS", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.MS-TXPWR-MAX-CCH", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.NCCsPermitted", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.NECI", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.Neighbors", 0)
         << QApplication::translate("UserHome", "GSM.CellSelection.RXLEV-ACCESS-MIN", 0)
         << QApplication::translate("UserHome", "GSM.Channels.C1sFirst", 0)
         << QApplication::translate("UserHome", "GSM.Channels.NumC1s", 0)
         << QApplication::translate("UserHome", "GSM.Channels.NumC7s", 0)
         << QApplication::translate("UserHome", "GSM.Control.GPRSMaxIgnore", 0)
         << QApplication::translate("UserHome", "GSM.Identity.BSIC.BCC", 0)
         << QApplication::translate("UserHome", "GSM.Identity.BSIC.NCC", 0)
         << QApplication::translate("UserHome", "GSM.Identity.ShortName", 0)
         << QApplication::translate("UserHome", "GSM.Identity.ShowCountry", 0)
         << QApplication::translate("UserHome", "GSM.MS.Power.Damping", 0)
         << QApplication::translate("UserHome", "GSM.MS.Power.Max", 0)
         << QApplication::translate("UserHome", "GSM.MS.Power.Min", 0)
         << QApplication::translate("UserHome", "GSM.MS.TA.Damping", 0)
         << QApplication::translate("UserHome", "GSM.MS.TA.Max", 0)
         << QApplication::translate("UserHome", "GSM.MaxSpeechLatency", 0)
         << QApplication::translate("UserHome", "GSM.RACH.AC", 0)
         << QApplication::translate("UserHome", "GSM.RACH.MaxRetrans", 0)
         << QApplication::translate("UserHome", "GSM.RACH.TxInteger", 0)
         << QApplication::translate("UserHome", "GSM.Radio.ARFCNs", 0)
         << QApplication::translate("UserHome", "GSM.RADIO-LINK-TIMEOUT", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.ACCURACY", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.ALMANAC.REFRESH.TIME", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.ALMANAC.URL", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.EPHEMERIS.REFRESH.TIME", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.EPHEMERIS.URL", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.RESPONSETIME", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.SEED.ALTITUDE", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.SEED.LATITUDE", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.SEED.LONGITUDE", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.SERVER.URL", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.ALMANAC.ASSIST.PRESENT", 0)
         << QApplication::translate("UserHome", "GSM.RRLP.EPHEMERIS.ASSIST.COUNT", 0)
         << QApplication::translate("UserHome", "GSM.Radio.Band", 0)
         << QApplication::translate("UserHome", "GSM.Radio.C0", 0)
         << QApplication::translate("UserHome", "GSM.Radio.MaxExpectedDelaySpread", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.MaxAttenDB", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.MinAttenDB", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.NumSamples", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.Period", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.SamplePeriod", 0)
         << QApplication::translate("UserHome", "GSM.Radio.PowerManager.TargetT3122", 0)
         << QApplication::translate("UserHome", "GSM.Radio.RSSITarget", 0)
         << QApplication::translate("UserHome", "GSM.Radio.NeedBSIC", 0)
         << QApplication::translate("UserHome", "GSM.Timer.T3113", 0)
         << QApplication::translate("UserHome", "GSM.Timer.T3122Max", 0)
         << QApplication::translate("UserHome", "GSM.Timer.T3122Min", 0)
         << QApplication::translate("UserHome", "GSM.Timer.T3212", 0)
         << QApplication::translate("UserHome", "Log.Alarms.Max", 0)
         << QApplication::translate("UserHome", "Log.Level.CallControl.cpp", 0)
         << QApplication::translate("UserHome", "Log.Level.MobilityManagement.cpp", 0)
         << QApplication::translate("UserHome", "Log.Level.RadioResource.cpp", 0)
         << QApplication::translate("UserHome", "Log.Level.SMSControl.cpp", 0)
         << QApplication::translate("UserHome", "NTP.Server", 0)
         << QApplication::translate("UserHome", "RTP.Range", 0)
         << QApplication::translate("UserHome", "RTP.Start", 0)
         << QApplication::translate("UserHome", "SIP.RFC3428.NoTrying", 0)
         << QApplication::translate("UserHome", "SIP.DTMF.RFC2833", 0)
         << QApplication::translate("UserHome", "SIP.DTMF.RFC2833.PayloadType", 0)
         << QApplication::translate("UserHome", "SIP.DTMF.RFC2967", 0)
         << QApplication::translate("UserHome", "SIP.Local.IP", 0)
         << QApplication::translate("UserHome", "SIP.Local.Port", 0)
         << QApplication::translate("UserHome", "SIP.MaxForwards", 0)
         << QApplication::translate("UserHome", "SIP.Proxy.Registration", 0)
         << QApplication::translate("UserHome", "SIP.Proxy.SMS", 0)
         << QApplication::translate("UserHome", "SIP.Proxy.Speech", 0)
         << QApplication::translate("UserHome", "SIP.RegistrationPeriod", 0)
         << QApplication::translate("UserHome", "SIP.SMSC", 0)
         << QApplication::translate("UserHome", "SIP.Timer.A", 0)
         << QApplication::translate("UserHome", "SIP.Timer.B", 0)
         << QApplication::translate("UserHome", "SIP.Timer.E", 0)
         << QApplication::translate("UserHome", "SIP.Timer.F", 0)
         << QApplication::translate("UserHome", "SIP.Timer.J", 0)
         << QApplication::translate("UserHome", "SIP.Timer.H", 0)
         << QApplication::translate("UserHome", "SIP.Timer.I", 0)
         << QApplication::translate("UserHome", "SMS.DefaultDestSMSC", 0)
         << QApplication::translate("UserHome", "SMS.FakeSrcSMSC", 0)
         << QApplication::translate("UserHome", "SMS.MIMEType", 0)
         << QApplication::translate("UserHome", "SubscriberRegistry.Manager.Title", 0)
         << QApplication::translate("UserHome", "SubscriberRegistry.Manager.Url", 0)
         << QApplication::translate("UserHome", "SubscriberRegistry.Manager.VisibleColumns", 0)
         << QApplication::translate("UserHome", "SubscriberRegistry.db", 0)
         << QApplication::translate("UserHome", "SubscriberRegistry.Port", 0)
         << QApplication::translate("UserHome", "TRX.IP", 0)
         << QApplication::translate("UserHome", "TRX.Port", 0)
         << QApplication::translate("UserHome", "TRX.RadioFrequencyOffset", 0)
         << QApplication::translate("UserHome", "TRX.Timeout.Clock", 0)
         << QApplication::translate("UserHome", "TRX.Timeout.Start", 0)
         << QApplication::translate("UserHome", "TRX.TxAttenOffset", 0)
         << QApplication::translate("UserHome", "Test.SIP.SimulatedPacketLoss", 0)
         << QApplication::translate("UserHome", "Control.LUR.OpenRegistration", 0)
         << QApplication::translate("UserHome", "GSM.Radio.RXGain", 0)
         << QApplication::translate("UserHome", "GSM.Radio.RxGain", 0)
         << QApplication::translate("UserHome", "GSM.Identity.MCC", 0)
         << QApplication::translate("UserHome", "GSM.Identity.MNC", 0)
         << QApplication::translate("UserHome", "GSM.Identity.LAC", 0)
         << QApplication::translate("UserHome", "GSM.Identity.CI", 0)
         << QApplication::translate("UserHome", "Log.Level", 0)
        );
        configsettings_checkBox->setText(QApplication::translate("UserHome", "Enable", 0));
        configsettings_oldvalue_label->setText(QApplication::translate("UserHome", "Old Value:", 0));
        configsettings_newvalue_label->setText(QApplication::translate("UserHome", "New Value:", 0));
        configsettings_configs_label->setText(QApplication::translate("UserHome", "Configs", 0));
        configsettings_save_button->setText(QApplication::translate("UserHome", "Save", 0));
        configsettings_cancel_button->setText(QApplication::translate("UserHome", "Cancel", 0));
        help_calls->setText(QApplication::translate("UserHome", "calls", 0));
        help_alarms->setText(QApplication::translate("UserHome", "alarms", 0));
        help_crashme->setText(QApplication::translate("UserHome", "crashme", 0));
        help_noise->setText(QApplication::translate("UserHome", "noise", 0));
        help_regperiod->setText(QApplication::translate("UserHome", "regperiod", 0));
        help_uptime->setText(QApplication::translate("UserHome", "uptime", 0));
        help_exit->setText(QApplication::translate("UserHome", "exit", 0));
        help_notices->setText(QApplication::translate("UserHome", "notices", 0));
        help_rxgain->setText(QApplication::translate("UserHome", "rxgain", 0));
        help_version->setText(QApplication::translate("UserHome", "version", 0));
        help_cellid->setText(QApplication::translate("UserHome", "cellid", 0));
        help_help->setText(QApplication::translate("UserHome", "help", 0));
        help_page->setText(QApplication::translate("UserHome", "page", 0));
        help_stats->setText(QApplication::translate("UserHome", "stats", 0));
        help_chans->setText(QApplication::translate("UserHome", "chans", 0));
        help_load->setText(QApplication::translate("UserHome", "load", 0));
        help_power->setText(QApplication::translate("UserHome", "power", 0));
        help_tmsis->setText(QApplication::translate("UserHome", "tmsis", 0));
        pushButton->setText(QApplication::translate("UserHome", "PushButton", 0));
        help_commandlabel->setText(QApplication::translate("UserHome", "Command:", 0));
        logo_picture->setText(QString());
        logout_message_label->setText(QApplication::translate("UserHome", "You have successfully logged out of the Communect System.", 0));
        logout_signin_button->setText(QApplication::translate("UserHome", "Login", 0));
        searchuser_button->setText(QApplication::translate("UserHome", "Search", 0));
        searchuser_username_label->setText(QApplication::translate("UserHome", "Username", 0));
        searchuser_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserHome: public Ui_UserHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHOME_H
