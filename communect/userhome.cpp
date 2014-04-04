#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userhome.h"
#include "ui_userhome.h"
#include "QMessageBox"
#include "QDebug"
#include "QDate"
#include <QSqlQueryModel>
#include "processes.h"
#include <QGridLayout>

// Database for the TMSI Table
#define TMSI_DB "/var/run/OpenBTSTMSITable.db"

using namespace std;

QString logintomodify;
QString oldhashedpassword;

UserHome::UserHome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserHome)
{
    ui->setupUi(this);

    stringstream ss;
    ss << "You are logged in as \"" << global_login << "\".";
    ui->username_label->setText(QString::fromStdString(ss.str()));
    hideallframes();
    ui->userhome_frame->show();
    ui->home_button->setFocus();

    ui->usernamelabel->setText(QString::fromStdString("Username: " + global_login));
    ui->lastloginlabel->setText(QString::fromStdString("Last successful login: " + global_lastsucc));
    ui->lasterrorlabel->setText(QString::fromStdString("Last failed login: " + global_lasterror));

    ui->adduser_passwordline->setEchoMode(QLineEdit::Password);
    ui->adduser_retypepasswordline->setEchoMode(QLineEdit::Password);
    ui->oldpasswordline->setEchoMode(QLineEdit::Password);
    ui->newpassword_line->setEchoMode(QLineEdit::Password);
    ui->confirmnewpassword_line->setEchoMode(QLineEdit::Password);
    ui->rates_newratelabel->setValidator(new QIntValidator(0, 1000, this));

    checkpermissions();
}

UserHome::~UserHome()
{
    delete ui;
}

// For hiding all the frames when switching modules
void UserHome::hideallframes() {
    ui->userhome_frame->hide();
    ui->rates_frame->hide();
    ui->acctmgmt_frame->hide();
    ui->adduser_frame->hide();
    ui->searchuser_frame->hide();
    ui->modifyuser_frame->hide();
    ui->historylogs_frame->hide();
    ui->messaging_frame->hide();
    ui->communityalerts_frame->hide();
    ui->unitcommunication_frame->hide();
    ui->configsettings_frame->hide();
    ui->logout_frame->hide();
    ui->emergency911_frame->hide();
    ui->addconfig_frame->hide();
    ui->modifyconfig_frame->hide();
    ui->userhome_frame->hide();
    ui->tmsi_frame->hide();

    ui->acctmgmt_notiflabel->setStyleSheet("QLabel { background-color : transparent; color : black;}");
    ui->acctmgmt_notiflabel->setText("");
    ui->messaging_notiflabel->setStyleSheet("QLabel { background-color : transparent; color : black;}");
    ui->messaging_notiflabel->setText("");
    ui->searchuser_label->setStyleSheet("QLabel { background-color : transparent; color : black;}");
    ui->searchuser_label->setText("");

    ui->adduser_passwordline->setText("");
    ui->adduser_retypepasswordline->setText("");
    ui->adduser_usernameline->setText("");
    ui->commalertmessage_text->setPlainText("");
    ui->confirmnewpassword_line->setText("");
    ui->configsettings_newvalue_line->setText("");
    ui->newpassword_line->setText("");
    ui->newshortcode_line->setText("");
    ui->oldpasswordline->setText("");
    ui->searchuserline->setText("");
    ui->unitcommmessage_text->setPlainText("");

    checkpermissions();
}

// For when the home button is clicked
void UserHome::on_home_button_clicked()
{
    hideallframes();
    //show userhome frame
    ui->userhome_frame->show();
}

/***** RATES MANAGEMENT MODULE *****/

// For when service rates are changed, rates displayed are updated
void UserHome::rates_service_changed()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/var/lib/asterisk/sqlite3dir/sqlite3.db");
    db.open();

    QSqlQuery query;
    QString rate = ui->rates_combobox->currentText();
    query.prepare("select rate from rates where service = :rate");
    query.bindValue(":rate", rate);
    query.exec();
    query.next();

    QString oldrate = query.value(0).toString();
    ui->rates_oldratelabel->setText(oldrate);
}

// For accessing the rates module
void UserHome::on_rates_button_clicked()
{
    ui->rates_combobox->clear();
    QString rate;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/var/lib/asterisk/sqlite3dir/sqlite3.db");
    db.open();

    QSqlQuery servicequery;
    servicequery.prepare("SELECT service from rates");
    servicequery.exec();

    while(servicequery.next())
    {
        ui->rates_combobox->addItem(servicequery.value(0).toString());
    }

    QSqlQuery query;

    rate = ui->rates_combobox->currentText();
    query.prepare("select rate from rates where service = :rate");
    query.bindValue(":rate", rate);
    query.exec();
    query.next();

    QString oldrate = query.value(0).toString();
    ui->rates_oldratelabel->setText(oldrate);
    connect(ui->rates_combobox , SIGNAL(currentIndexChanged(int)),this,SLOT(rates_service_changed()));
    hideallframes();
    ui->rates_frame->show();
}

// For changing the value of service rates
void UserHome::on_rates_savebutton_clicked()
{
    if(ui->rates_newratelabel->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Empty new value field.","Please enter a new value.");
    }
    else
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/var/lib/asterisk/sqlite3dir/sqlite3.db");
        db.open();

        QSqlQuery query;
        int newrate = 0;
        QString rate = ui->rates_combobox->currentText();
        newrate = ui->rates_newratelabel->text().toInt();
        query.prepare("update rates set rate = :newrate where service = :rate");
        query.bindValue(":newrate", newrate);
        query.bindValue(":rate", rate);
        query.exec();
        db.close();

        MainWindow mw;
        mw.connect_to_db();
        stringstream strm;
        strm << rate.toUtf8().constData() << " was successfully updated with new rate = " << newrate << "!";
        string desc = strm.str();
        mw.addHistory(desc);

        ui->rates_newratelabel->setText("");
        rates_service_changed();
        hideallframes();
        ui->rates_frame->show();
        ui->rates_button->setFocus();
    }
}

void UserHome::on_rates_cancelbutton_clicked()
{
    ui->rates_newratelabel->setText("");
}

/***** ACCOUNTS MANAGEMENT MODULE *****/

// For accessing the Accounts Management Module
void UserHome::on_acctmgmt_button_clicked()
{
    hideallframes();
    //show acctmgmt frame
    ui->acctmgmt_frame->show();

    MainWindow mw;
    mw.connect_to_db();
    bool hasadduser = mw.hasadduser(QString::fromStdString(global_login));

    if(hasadduser) {
        ui->adduser_button->setEnabled(true);
    } else {
        ui->adduser_button->setEnabled(false);
    }
}

// For accessing the Add User Module
void UserHome::on_adduser_button_clicked()
{
    hideallframes();
    ui->acctmgmt_button->setFocus();
    //show adduser frame
    ui->adduser_frame->show();
}

// For when an add user module cancels an action
void UserHome::on_addusercancel_button_clicked()
{
    //hide adduser frame
    ui->acctmgmt_button->setFocus();
    ui->adduser_frame->hide();
    //show acctmgmt frame
    ui->acctmgmt_frame->show();
}

// For when a user is added to the database
void UserHome::on_addusersave_button_clicked()
{
    MainWindow mw;
    mw.connect_to_db();
    QString newuserlogin = ui->adduser_usernameline->text();
    QString password = ui->adduser_passwordline->text();
    QString retypepassword = ui->adduser_retypepasswordline->text();

    if(newuserlogin == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Empty field.","Please make sure that the username field is filled.");
        ui->adduser_passwordline->setText("");
        ui->adduser_retypepasswordline->setText("");
    }
    else if(password == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Empty field.","Please make sure that the password field is filled.");
        ui->adduser_passwordline->setText("");
        ui->adduser_retypepasswordline->setText("");
    }
    else if(password != retypepassword) {
        QMessageBox messageBox;
        messageBox.critical(0,"Passwords don't match.","Please verify and confirm the password for this user.");
        ui->adduser_passwordline->setText("");
        ui->adduser_retypepasswordline->setText("");
    } else {
        // Check if username is valid
        if (!mw.logincheck(newuserlogin.toUtf8().constData())) {
            QMessageBox messageBox;
            messageBox.critical(0,"Invalid username. Try again.", "Usernames can only contain alphanumeric characters, the underscore character, and the period character.");
            ui->adduser_usernameline->setText("");
            ui->adduser_passwordline->setText("");
            ui->adduser_retypepasswordline->setText("");
        }
        else if(mw.userexists(newuserlogin.toUtf8().constData())) {
            QMessageBox messageBox;
            messageBox.critical(0,"Username already in use. Try again.", "Username already exists in the database. Please choose another one.");
            ui->adduser_usernameline->setText(newuserlogin);
            ui->adduser_passwordline->setText("");
            ui->adduser_retypepasswordline->setText("");
        }
        else {
            //Check first SQL Injection stuff (user and pass and confirmpass)
            string new_pass = mw.passcheck(password.toUtf8().constData());

            //[DB]CODE HERE TO ADD PASSWORD TO DB
            mw.insertnewuseropenbts(newuserlogin.toUtf8().constData(), new_pass);
            stringstream strm;
            strm << "User " << newuserlogin.toUtf8().constData() << " has been added to the system!";
            string desc = strm.str();
            mw.addHistory(desc);

            //hide adduser frame
            ui->adduser_frame->hide();
            //show acctmgmt frame
            ui->acctmgmt_frame->show();

            MainWindow mw;
            mw.connect_to_db();
            bool hasadduser = mw.hasadduser(QString::fromStdString(global_login));

            if(hasadduser) {
                ui->adduser_button->setEnabled(true);
            } else {
                ui->adduser_button->setEnabled(false);
            }

            ui->acctmgmt_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
            stringstream s;
            s << "<center>" << desc << "</center>";
            desc = s.str();
            ui->acctmgmt_notiflabel->setText(desc.c_str());
        }
    }
    ui->acctmgmt_button->setFocus();
}

// For when the modify user button is clicked
void UserHome::on_modifyuser_button_clicked()
{

    ui->acctmgmt_button->setFocus();
    //show searchuser_frame
    hideallframes();
    MainWindow mw;
    mw.connect_to_db();

    if(mw.hasmodpriv(QString::fromStdString(global_login)))
    {
        ui->searchuser_frame->show();
        ui->searchuserline->setFocus();
    }
    else
    {
       ui->searchuserline->setText(QString::fromStdString(global_login));
       on_searchuser_button_clicked();
    }
}

// For when a User is searched in the database for modifying account
void UserHome::on_searchuser_button_clicked()
{
    ui->acctmgmt_button->setFocus();
    QString loginvalue = ui->searchuserline->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/fss/public/openbts/trunk/apps/openbtsusers.db");
    db.open();

    QSqlQuery query;
    query.prepare("select count(*) from users where login = :login");
    query.bindValue(":login", loginvalue);
    query.exec();
    query.next();

    if(query.value(0) == 1)
    {
        //show modifyuser frame
        logintomodify = loginvalue;

        MainWindow mw;
        mw.connect_to_db();
        string shortcode = mw.getshortcodeofuser(logintomodify);
        oldhashedpassword = QString::fromStdString(mw.getpasswordofuser(logintomodify));

        ui->changepass_checkbox->setChecked(false);
        ui->changepasswordgroup->setEnabled(false);
        ui->changeshortcode_checkbox->setChecked(false);
        ui->changeshortcodegroup->setEnabled(false);
        ui->modifypriv_checkbox->setChecked(false);
        ui->modifyprivilegesgroup->setEnabled(false);

        bool hasadduser = mw.hasadduser(logintomodify);
        bool hasmodpriv = mw.hasmodpriv(logintomodify);
        bool hasrates = mw.hasrates(logintomodify);
        bool hasshortcodes = mw.hasshortcodes(logintomodify);

        bool hashistorylogs = mw.hashistorylogs(logintomodify);
        bool hasconfigsettings = mw.hasconfigsettings(logintomodify);
        bool hasmodifyuser = mw.hasmodifyuser(logintomodify);
        bool hascommalerts = mw.hassendalerts(logintomodify);
        bool hassurvrecord = mw.hassurvrecord(logintomodify);

        ui->grantadduser_checkbox->setChecked(hasadduser);
        ui->grantmodpriv_checkbox->setChecked(hasmodpriv);
        ui->grantrates_checkbox->setChecked(hasrates);
        ui->grantshortcodes_checkbox->setChecked(hasshortcodes);

        ui->granthistlogs_checkbox->setChecked(hashistorylogs);
        ui->grantconfigsettings_checkbox->setChecked(hasconfigsettings);
        ui->grantmodifyuser_checkbox->setChecked(hasmodifyuser);
        ui->grantsendalerts_checkbox->setChecked(hascommalerts);
        ui->grantsurvrecord_checkbox->setChecked(hassurvrecord);

        ui->oldshortcode_line->setText(QString::fromStdString(shortcode));
        ui->modprivusername_label->setText(ui->searchuserline->text().toStdString().c_str());
        hideallframes();
        ui->modifyuser_frame->show();
        ui->acctmgmt_button->setFocus();

        bool curruserhasshortcode = mw.hasshortcodes(QString::fromStdString(global_login));
        bool curruserhasmodifypriv = mw.hasmodpriv(QString::fromStdString(global_login));
        bool curruserhasmoduser = mw.hasmodifyuser(QString::fromStdString(global_login));

        if(curruserhasmoduser && (logintomodify != QString::fromStdString(global_login))){
            ui->oldpasswordline->hide();
            ui->modifyuser_oldpassword_label->hide();
        }
        else {
            ui->oldpasswordline->show();
            ui->modifyuser_oldpassword_label->show();
        }
        if(!curruserhasmoduser && (logintomodify != QString::fromStdString(global_login))){
            ui->changepasswordgroup->hide();
            ui->changepass_checkbox->hide();
        }
        else {
            ui->changepasswordgroup->show();
            ui->changepass_checkbox->show();
        }
        if(curruserhasshortcode) {
            ui->changeshortcodegroup->show();
            ui->changeshortcode_checkbox->show();
            ui->changeshortcode_checkbox->setEnabled(true);
        } else {
            ui->changeshortcodegroup->hide();
            ui->changeshortcode_checkbox->hide();
        }
        if(curruserhasmodifypriv) {
            ui->modifyprivilegesgroup->show();
            ui->modifypriv_checkbox->show();
            ui->modifypriv_checkbox->setEnabled(true);
        } else {
            ui->modifyprivilegesgroup->hide();
            ui->modifypriv_checkbox->hide();
        }
    }
    else
    {
        //show searchuser frame
        hideallframes();
        ui->searchuser_frame->show();

        //show label user does not exist
        char* err = "<center>User does not exist.</center>";
        ui->searchuser_label->setStyleSheet("QLabel { background-color : #FF8080; color : black;}");
        ui->searchuser_label->setText(err);
    }
    ui->acctmgmt_button->setFocus();
}

// For when changes on user accounts are saved to the database
void UserHome::on_saveacctbutton_clicked()
{
    bool changepassword = ui->changepass_checkbox->isChecked();
    bool changeshortcode = ui->changeshortcode_checkbox->isChecked();
    bool changepriv = ui->modifypriv_checkbox->isChecked();

    bool grantrates = ui->grantrates_checkbox->isChecked();
    bool grantmodpriv = ui->grantmodpriv_checkbox->isChecked();
    bool grantadduser = ui->grantadduser_checkbox->isChecked();
    bool grantshortcodes = ui->grantshortcodes_checkbox->isChecked();

    bool granthist = ui->granthistlogs_checkbox->isChecked();
    bool grantconfig = ui->grantconfigsettings_checkbox->isChecked();
    bool grantmodifuser = ui->grantmodifyuser_checkbox->isChecked();
    bool grantsendalerts = ui->grantsendalerts_checkbox->isChecked();
    bool grantsurvrecord = ui->grantsurvrecord_checkbox->isChecked();

    QString oldpassword = ui->oldpasswordline->text();
    QString newpassword = ui->newpassword_line->text();
    QString confirmnewpassword = ui->confirmnewpassword_line->text();
    QString newshortcode = ui->newshortcode_line->text();

    bool successupdate = false;
    bool haserror = false;

    MainWindow mw;
    mw.connect_to_db();

    if(changepassword) {
        if(newpassword == "") {
            QMessageBox messageBox;
            messageBox.critical(0,"Empty field.","Please enter a new password.");
            ui->newpassword_line->setText("");
            ui->confirmnewpassword_line->setText("");
            haserror = true;
        }
        else if(newpassword != confirmnewpassword) {
            QMessageBox messageBox;
            messageBox.critical(0,"New passwords don't match","Please reconfirm your new password.");
            ui->newpassword_line->setText("");
            ui->confirmnewpassword_line->setText("");
            haserror = true;
        } else {
            // if user has priv to modify other users, disregard old pass
            if(mw.hasmodifyuser(QString::fromStdString(global_login)) && QString::fromStdString(global_login) != logintomodify);
            // else, check if old pass is correct
            else {
                oldpassword = QString::fromStdString(mw.passcheck(oldpassword.toUtf8().constData()));
                string insertedon = mw.getinsertedon(logintomodify.toUtf8().constData());

                if(oldhashedpassword.toUtf8().constData() != mw.sha256hash(mw.sha256hash(oldpassword.toUtf8().constData()) + insertedon)) {
                    QMessageBox messageBox;
                    messageBox.critical(0,"Wrong password.","Please recheck your current password.");
                    ui->newpassword_line->setText("");
                    ui->confirmnewpassword_line->setText("");
                    ui->oldpasswordline->setText("");
                    haserror = true;
                }
            }
       }
    }

    if(changeshortcode) {
        if(newshortcode == "") {
            QMessageBox messageBox;
            messageBox.critical(0,"New passwords don't match","Please reconfirm your new password.");
            ui->newshortcode_line->setText("");
            haserror = true;
        }
    }

    if(!haserror) {
        //DB FUNCTION
        successupdate = mw.updateuser_database(logintomodify, changepassword, changeshortcode, changepriv, grantrates, grantmodpriv, grantadduser, grantshortcodes, granthist, grantconfig, grantmodifuser, grantsendalerts, grantsurvrecord, newpassword, newshortcode);
    }
    if(successupdate) {
        //hide modifyuser frame
        ui->modifyuser_frame->hide();
        //show acctmgmt frame
        ui->acctmgmt_frame->show();

        MainWindow mw;
        mw.connect_to_db();
        bool hasadduser = mw.hasadduser(QString::fromStdString(global_login));

        if(hasadduser) {
            ui->adduser_button->setEnabled(true);
        } else {
            ui->adduser_button->setEnabled(false);
        }

        ui->acctmgmt_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
        ui->acctmgmt_notiflabel->setText("<center>Account changes have been saved!</center>");
        ui->acctmgmt_button->setFocus();
    }

    checkpermissions();
}

void UserHome::on_changepass_checkbox_toggled(bool checked)
{
    if(checked) {
        ui->changepasswordgroup->setEnabled(true);

    } else {
        ui->changepasswordgroup->setEnabled(false);

    }
}

void UserHome::on_changeshortcode_checkbox_toggled(bool checked)
{
    if(checked) {
        ui->changeshortcodegroup->setEnabled(true);

    } else {
        ui->changeshortcodegroup->setEnabled(false);

    }
}

void UserHome::on_modifypriv_checkbox_toggled(bool checked)
{
    if(checked) {
        ui->modifyprivilegesgroup->setEnabled(true);

    } else {
        ui->modifyprivilegesgroup->setEnabled(false);

    }
}

void UserHome::on_acctmgmt_cancelbutton_clicked()
{
    ui->changepasswordgroup->setEnabled(false);
    ui->changeshortcodegroup->setEnabled(false);
    ui->modifyprivilegesgroup->setEnabled(false);

    ui->oldpasswordline->setText("");
    ui->newpassword_line->setText("");
    ui->confirmnewpassword_line->setText("");
    ui->newshortcode_line->setText("");
    ui->grantrates_checkbox->setChecked(false);
    ui->grantmodpriv_checkbox->setChecked(false);


    ui->changepass_checkbox->setChecked(false);
    ui->changeshortcode_checkbox->setChecked(false);
    ui->modifypriv_checkbox->setChecked(false);

    hideallframes();
    ui->acctmgmt_button->setFocus();
    ui->acctmgmt_frame->show();

    MainWindow mw;
    mw.connect_to_db();
    bool hasadduser = mw.hasadduser(QString::fromStdString(global_login));

    if(hasadduser) {
        ui->adduser_button->setEnabled(true);
    } else {
        ui->adduser_button->setEnabled(false);
    }
}

void UserHome::on_searchuserline_returnPressed()
{
    ui->searchuser_button->click();
}

void UserHome::on_searchuserline_editingFinished()
{
    ui->searchuser_button->setFocus();
}

/***** HISTORY LOGS MODULE *****/

// For accessing the database for the history logs
void UserHome::historylogs_day_changed()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/fss/public/openbts/trunk/apps/openbtsusers.db");
    db.open();

    QSqlQuery query;
    query.prepare("select time(historylogs.insertedon), description, login from historylogs join users using (userid) where date(historylogs.insertedon) = :datevalue order by time(historylogs.insertedon) desc");
    query.bindValue(":datevalue", get_date(ui->year_combobox, ui->month_combobox, ui->day_combobox));
    query.exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Time"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("User"));

    ui->historylogs_tableview->setModel(model);
    ui->historylogs_tableview->setColumnWidth(0,91);
    ui->historylogs_tableview->setColumnWidth(1,200);
    ui->historylogs_tableview->setColumnWidth(2,91);
    ui->historylogs_tableview->setWordWrap(true);
    ui->historylogs_tableview->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void UserHome::historylogs_datefixer()
{
    generate_days(ui->year_combobox, ui->month_combobox, ui->day_combobox);
    historylogs_day_changed();
}

// For accessing the History Logs module
void UserHome::on_historylogs_button_clicked()
{
    hideallframes();
    //show historylogs frame
    ui->historylogs_frame->show();

    ui->day_combobox->clear();
    int counter = 0;
    for(counter = 1; counter < 32; counter++)
    {
        ui->day_combobox->addItem(QString::number(counter));
    }
    for(counter = 2000; counter < 2050; counter++)
    {
         ui->year_combobox->addItem(QString::number(counter));
    }
    connect(ui->month_combobox , SIGNAL(currentIndexChanged(int)),this,SLOT(historylogs_datefixer()));
    connect(ui->day_combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(historylogs_day_changed()));
    connect(ui->year_combobox , SIGNAL(currentIndexChanged(int)),this,SLOT(historylogs_datefixer()));
}

/***** MESSAGING MODULE *****/

// For accessing the messaging module
void UserHome::on_messaging_button_clicked()
{
    hideallframes();
    //show messaging frame
    ui->messaging_frame->show();

    MainWindow mw;
    mw.connect_to_db();
    bool hascommalerts = mw.hassendalerts(QString::fromStdString(global_login));

    if(hascommalerts) {
        ui->communityalerts_button->setEnabled(true);
    } else {
        ui->communityalerts_button->setEnabled(false);
    }
}

// For accessing the community alerts page
void UserHome::on_communityalerts_button_clicked()
{
    hideallframes();
    //show communityalerts_frame
    ui->messaging_button->setFocus();
    ui->communityalerts_frame->show();
}

void UserHome::on_commalertscancel_button_clicked()
{
    //delete draft mesage
    ui->commalertmessage_text->setPlainText("");

    //hide communityalerts_frame
    ui->communityalerts_frame->hide();

    //show messaging frame
    ui->messaging_frame->show();
    ui->messaging_button->setFocus();

    MainWindow mw;
    mw.connect_to_db();
    bool hascommalerts = mw.hassendalerts(QString::fromStdString(global_login));

    if(hascommalerts) {
        ui->communityalerts_button->setEnabled(true);
    } else {
        ui->communityalerts_button->setEnabled(false);
    }
}

// For accessing the unit communication page
void UserHome::on_unitcommunication_button_clicked()
{
    //show unitcommunication_frame
    ui->messaging_button->setFocus();
    ui->unitcommunication_combobox->clear();

    QSqlDatabase tmsi_db = QSqlDatabase::addDatabase("QSQLITE");
    tmsi_db.setDatabaseName(TMSI_DB);
    tmsi_db.open();
    QSqlQuery query("SELECT IMSI from TMSI_TABLE");

    while(query.next())
    {
        ui->unitcommunication_combobox->addItem(query.value(0).toString());
    }
    hideallframes();
    ui->unitcommunication_frame->show();
}

void UserHome::on_unitcommcancel_button_clicked()
{
    //hide unitcommunication_frame
    ui->unitcommunication_frame->hide();

    //show messaging frame
    ui->messaging_frame->show();

    MainWindow mw;
    mw.connect_to_db();
    bool hascommalerts = mw.hassendalerts(QString::fromStdString(global_login));

    if(hascommalerts) {
        ui->communityalerts_button->setEnabled(true);
    } else {
        ui->communityalerts_button->setEnabled(false);
    }

    ui->messaging_button->setFocus();
}

// For community alerts messaging
void UserHome::on_commalertssend_button_clicked()
{
    QString message = ui->commalertmessage_text->toPlainText();
    //send message

    stringstream ss;
    ss << "sendtoall " << message.toUtf8().constData() << "\n";
    cli->write(ss.str().c_str());
    cli->waitForReadyRead();
    QByteArray out = cli->readAll();

    //Then redirect to options page
    ui->messaging_button->setFocus();
    //hide communityalerts_frame
    ui->communityalerts_frame->hide();
    //show messaging frame
    ui->messaging_frame->show();

    MainWindow mw;
    mw.connect_to_db();
    bool hascommalerts = mw.hassendalerts(QString::fromStdString(global_login));

    if(hascommalerts) {
        ui->communityalerts_button->setEnabled(true);
    } else {
        ui->communityalerts_button->setEnabled(false);
    }


    ui->messaging_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
    ui->messaging_notiflabel->setText("<center>Message Sent!</center>");
    ui->commalertmessage_text->setPlainText("");
}

void UserHome::on_unitcommsend_button_clicked()
{
    QString message = ui->unitcommmessage_text->toPlainText();
    QString imsi = ui->unitcommunication_combobox->currentText();

    //send message
    stringstream ss;
    ss << "sendsms " << imsi.toUtf8().constData() << " " << message.toUtf8().constData() << "\n";
    cli->write(ss.str().c_str());
    cli->waitForReadyRead();
    QByteArray out = cli->readAll();

    MainWindow mw;
    mw.connect_to_db();

    ss.str("");
    ss.clear();

    ss << "Message sent to IMSI: " << imsi.toUtf8().constData() << ", \"" << message.toUtf8().constData() << "\"";

    //Then redirect to options page
    ui->messaging_button->setFocus();
    //hide unitcommunication_frame
    ui->unitcommunication_frame->hide();
    //show messaging frame
    ui->messaging_frame->show();

    bool hascommalerts = mw.hassendalerts(QString::fromStdString(global_login));

    if(hascommalerts) {
        ui->communityalerts_button->setEnabled(true);
    } else {
        ui->communityalerts_button->setEnabled(false);
    }


    ui->messaging_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
    ui->messaging_notiflabel->setText("<center>Message Sent!</center>");
    ui->unitcommmessage_text->setPlainText("");

    string msg = ss.str();
    mw.addHistory(msg);
}

/***** CONFIG SETTINGS MODULE *****/

// For the displaying of config values
void UserHome::configsettings_changed()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/etc/OpenBTS/OpenBTS.db");
    db.open();

    QSqlQuery query;
    QString valuestring = ui->configsettings_comboBox->currentText();
    query.prepare("select VALUESTRING from CONFIG where KEYSTRING = :valuestring");
    query.bindValue(":valuestring", valuestring);
    query.exec();
    query.next();
    QString oldvaluestring = query.value(0).toString();
    ui->configsettings_oldvalue_line->setText(oldvaluestring);
}

void UserHome::configsettings_delete_clicked()
{
    ui->configsettings_newvalue_line->setDisabled(true);
}

void UserHome::configsettings_edit_clicked()
{
    ui->configsettings_newvalue_line->setEnabled(true);
}

// For accessing the Config Settings Module
void UserHome::on_configsettings_button_clicked()
{
    hideallframes();
    //show configsettings frame
    ui->configsettings_frame->show();
}

// For displaying configs for modification
void UserHome::on_modifyconfig_button_clicked()
{
    ui->configsettings_comboBox->clear();
    ui->configsettings_newvalue_line->setEnabled(true);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/etc/OpenBTS/OpenBTS.db");
    db.open();
    QSqlQuery keyquery("SELECT KEYSTRING from CONFIG where VALUESTRING not NULL order by KEYSTRING asc");

    while(keyquery.next())
    {
        ui->configsettings_comboBox->addItem(keyquery.value(0).toString());
    }

    QSqlQuery query;

    QString keystring = ui->configsettings_comboBox->currentText();
    query.prepare("select VALUESTRING from CONFIG where KEYSTRING = :keystring");
    query.bindValue(":keystring", keystring);
    query.exec();
    query.next();

    QString oldvaluestring = query.value(0).toString();
    ui->configsettings_oldvalue_line->setText(oldvaluestring);
    connect(ui->configsettings_comboBox , SIGNAL(currentIndexChanged(int)),this,SLOT(configsettings_changed()));
    connect(ui->configsettings_delete_radiobutton, SIGNAL(clicked()),this,SLOT(configsettings_delete_clicked()));
    connect(ui->configsettings_edit_radiobutton, SIGNAL(clicked()),this,SLOT(configsettings_edit_clicked()));
    hideallframes();
    ui->modifyconfig_frame->show();
}

// For saving edited config settings
void UserHome::on_configsettings_save_button_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/etc/OpenBTS/OpenBTS.db");
    db.open();

    QSqlQuery query;
    QString keystring;
    QString newvaluestring;
    string desc;

    if(ui->configsettings_edit_radiobutton->isChecked())
    {
        if(ui->configsettings_newvalue_line->text() == "")
        {
            QMessageBox messageBox;
            messageBox.critical(0,"New value field Empty.","A new value should be entered in editing.");
        }
        else
        {
            keystring = ui->configsettings_comboBox->currentText();
            newvaluestring = ui->configsettings_newvalue_line->text();
            query.prepare("update CONFIG set VALUESTRING = :newvaluestring where KEYSTRING = :keystring");
            query.bindValue(":keystring", keystring);
            query.bindValue(":newvaluestring", newvaluestring);
            query.exec();

            MainWindow mw;
            mw.connect_to_db();
            stringstream strm;
            strm << "Changed the value of " << keystring.toUtf8().constData() << " to " << newvaluestring.toUtf8().constData();
            desc = strm.str();
            mw.addHistory(desc);
            ui->configsettings_edit_radiobutton->setAutoExclusive(false);
            ui->configsettings_edit_radiobutton->setChecked(false);
            ui->configsettings_edit_radiobutton->setAutoExclusive(true);
        }
    }

    if(ui->configsettings_delete_radiobutton->isChecked())
    {
        keystring = ui->configsettings_comboBox->currentText();
        query.prepare("update CONFIG set VALUESTRING = NULL where KEYSTRING = :keystring");
        query.bindValue(":keystring", keystring);
        query.exec();

        MainWindow mw;
        mw.connect_to_db();
        stringstream strm;
        strm << "Deleted " << keystring.toUtf8().constData() << " from the CONFIG table";
        desc = strm.str();
        mw.addHistory(desc);
        ui->configsettings_delete_radiobutton->setAutoExclusive(false);
        ui->configsettings_delete_radiobutton->setChecked(false);
        ui->configsettings_delete_radiobutton->setAutoExclusive(true);
    }

    ui->configsettings_oldvalue_line->setText(newvaluestring);
    ui->configsettings_newvalue_line->setText("");
    db.close();
    ui->modifyconfig_frame->hide();
    ui->configsettings_frame->show();
    ui->config_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
    stringstream s;
    s << "<center>" << desc << "</center>";
    desc = s.str();
    ui->config_notiflabel->setText(desc.c_str());
}

void UserHome::on_addconfig_button_clicked()
{
    hideallframes();
    ui->addconfig_frame->show();
}

void UserHome::on_configsettings_createsave_button_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/etc/OpenBTS/OpenBTS.db");
    db.open();
    string desc;

    QSqlQuery query;

    if(ui->configsettings_name_line->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Name Field Empty.","New config name should be filled.");
    }
    else if(ui->configsettings_value_line->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Value Field Empty.","New config value should be filled.");
    }
    else
    {
        QString newconfigname = ui->configsettings_name_line->text();
        QString newconfigvalue = ui->configsettings_value_line->text();
        QString newconfigcomment = ui->configsettings_comment_line->text();
        query.prepare("insert into CONFIG(KEYSTRING, VALUESTRING, COMMENTS) values(:newconfigname, :newconfigvalue, :newconfigcomment)");
        query.bindValue(":newconfigname", newconfigname);
        query.bindValue(":newconfigvalue", newconfigvalue);
        query.bindValue(":newconfigcomment", newconfigcomment);
        query.exec();

        MainWindow mw;
        mw.connect_to_db();
        stringstream strm;
        strm << "Added new config " << newconfigname.toUtf8().constData();
        desc = strm.str();
        mw.addHistory(desc);
        db.close();
        ui->configsettings_name_line->setText("");
        ui->configsettings_value_line->setText("");
        ui->configsettings_comment_line->setText("");
        ui->addconfig_frame->hide();
        ui->configsettings_frame->show();
        ui->config_notiflabel->setStyleSheet("QLabel { background-color : #8FFF8F; color : black;}");
        stringstream s;
        s << "<center>" << desc << "</center>";
        desc = s.str();
        ui->config_notiflabel->setText(desc.c_str());
    }
}

void UserHome::on_configsettings_createcancel_button_clicked()
{
    ui->configsettings_name_line->setText("");
    ui->configsettings_value_line->setText("");
    ui->configsettings_comment_line->setText("");
    hideallframes();
    ui->addconfig_frame->show();
    ui->configsettings_button->setFocus();
}

void UserHome::on_configsettings_cancel_button_clicked()
{
    ui->configsettings_newvalue_line->setText("");
    ui->configsettings_edit_radiobutton->setAutoExclusive(false);
    ui->configsettings_edit_radiobutton->setChecked(false);
    ui->configsettings_edit_radiobutton->setAutoExclusive(true);
    ui->configsettings_delete_radiobutton->setAutoExclusive(false);
    ui->configsettings_delete_radiobutton->setChecked(false);
    ui->configsettings_delete_radiobutton->setAutoExclusive(true);

    hideallframes();
    ui->modifyconfig_frame->show();
    ui->configsettings_button->setFocus();
}

/***** EMERGENCY MESSAGE MONITORING and SURVIVOR RECORDING MODULE *****/

// For accessing the database for the survivor recording module
void UserHome::survivor_day_changed()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/fss/public/smqueue/trunk/smqueue/emergency.db");
    db.open();

    QSqlQuery query;
    query.prepare("select time(survivors.insertedon), name, age, sex, healthcondition, specialmessage from survivors where date(survivors.insertedon) = :datevalue order by time(survivors.insertedon) desc");
    query.bindValue(":datevalue", get_date(ui->e911_year_combobox, ui->e911_month_combobox, ui->e911_day_combobox));
    query.exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Time"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sex"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Health Condition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Special Message"));

    ui->e911_tableView->setModel(model);
    ui->e911_tableView->setColumnWidth(0, 90);
    ui->e911_tableView->setColumnWidth(1,100);
    ui->e911_tableView->setColumnWidth(2,40);
    ui->e911_tableView->setColumnWidth(3,30);
    ui->e911_tableView->setColumnWidth(4,150);
    ui->e911_tableView->setColumnWidth(5,150);
    ui->e911_tableView->setWordWrap(true);
    ui->e911_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void UserHome::survivor_datefixer()
{
    generate_days(ui->e911_year_combobox, ui->e911_month_combobox, ui->e911_day_combobox);
    survivor_day_changed();
}

// Displays the logs for survivor recording
void UserHome::on_survivor_button_clicked()
{
    hideallframes();

    ui->emergency911_frame->show();

    ui->e911_day_combobox->clear();
    int counter = 0;
    for(counter = 1; counter < 32; counter++)
    {
        ui->e911_day_combobox->addItem(QString::number(counter));
    }
    for(counter = 2000; counter < 2050; counter++)
    {
         ui->e911_year_combobox->addItem(QString::number(counter));
    }
    connect(ui->e911_month_combobox , SIGNAL(currentIndexChanged(int)),this,SLOT(survivor_datefixer()));
    connect(ui->e911_day_combobox, SIGNAL(currentIndexChanged(int)),this,SLOT(survivor_day_changed()));
    connect(ui->e911_year_combobox , SIGNAL(currentIndexChanged(int)),this,SLOT(survivor_datefixer()));
}

QString UserHome::get_date(QComboBox *year_combobox, QComboBox *month_combobox, QComboBox *day_combobox)
{
    QString chosen_date;
    QString months[12] = {"01-", "02-", "03-", "04-", "05-", "06-", "07-", "08-", "09-", "10-", "11-", "12-"};

    chosen_date.append(year_combobox->currentText());
    chosen_date.append("-");
    chosen_date.append(months[month_combobox->currentIndex()]);
    if(day_combobox->currentText().toInt() < 10)
    {
        chosen_date.append("0");
    }
    chosen_date.append(day_combobox->currentText());
    return chosen_date;
}

void UserHome::generate_days(QComboBox *year_combobox, QComboBox *month_combobox, QComboBox *day_combobox)
{
    int counter;

    for(counter = 2000; counter < 2050; counter++)
    {
         year_combobox->addItem(QString::number(counter));
    }

    day_combobox->clear();

    QDate *monthdays = new QDate(year_combobox->currentText().toInt(), month_combobox->currentIndex()+1,1);
    for(counter = 1; counter <= monthdays->daysInMonth(); counter++)
    {
        day_combobox->addItem(QString::number(counter));
    }
    delete monthdays;
}

// For accessing the TMSIS table
void UserHome::on_connectionstatus_button_clicked()
{

    QSqlDatabase tmsi_db = QSqlDatabase::addDatabase("QSQLITE");
    tmsi_db.setDatabaseName(TMSI_DB);
    tmsi_db.open();

    QSqlQueryModel *model = new QSqlQueryModel();
    stringstream query;
    string secs, mins, hrs;
    secs = "(strftime('%s', 'now') - CREATED)";
    mins = "(((strftime('%s', 'now') - CREATED) + 30) / 60)";
    hrs = "(((((strftime('%s', 'now') - CREATED) + 30) / 60) + 30) / 60)";
    query << "select IMSI,";
    query << " CASE WHEN " << secs << " < 300 THEN " << secs << " || ' s'";
    query << " WHEN " << mins << " < 300 THEN " << mins << " || ' m'";
    query << " WHEN " << hrs << " < 120 THEN " << hrs << " || ' h'";
    query << " ELSE ("<< hrs << "+12)/24 || ' d' END,";

    secs = "(strftime('%s', 'now') - ACCESSED)";
    mins = "(((strftime('%s', 'now') - ACCESSED) + 30) / 60)";
    hrs = "(((((strftime('%s', 'now') - ACCESSED) + 30) / 60) + 30) / 60)";

    query << " CASE WHEN " << secs << " < 300 THEN " << secs << " || ' s'";
    query << " WHEN " << mins << " < 300 THEN " << mins << " || ' m'";
    query << " WHEN " << hrs << " < 120 THEN " << hrs << " || ' h'";
    query << " ELSE ("<< hrs << "+12)/24 || ' d' END";
    query << " from TMSI_TABLE";
    model->setQuery(QString::fromStdString(query.str()));

    QString err = QString::fromStdString(query.str());

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IMSI"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Used"));

    ui->tmsi_tableview->setModel(model);

    ui->tmsi_tableview->setColumnWidth(0, 200);
    ui->tmsi_tableview->setColumnWidth(1,100);
    ui->tmsi_tableview->setColumnWidth(2,119);
    ui->tmsi_tableview->setWordWrap(true);
    ui->tmsi_tableview->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    hideallframes();
    ui->tmsi_frame->show();
}

void UserHome::checkpermissions() {

    MainWindow mw;
    mw.connect_to_db();

    bool hasrates = mw.hasrates(QString::fromStdString(global_login));
    bool hassurvivor = mw.hassurvrecord(QString::fromStdString(global_login));
    bool hasconfigset = mw.hasconfigsettings(QString::fromStdString(global_login));
    bool hashistlog = mw.hashistorylogs(QString::fromStdString(global_login));

    if(!hasrates)
        ui->rates_button->setEnabled(false);
    else
        ui->rates_button->setEnabled(true);

    if(!hassurvivor)
        ui->survivor_button->setEnabled(false);
    else
        ui->survivor_button->setEnabled(true);

    if(!hasconfigset)
        ui->configsettings_button->setEnabled(false);
    else
        ui->configsettings_button->setEnabled(true);

    if(!hashistlog)
        ui->historylogs_button->setEnabled(false);
    else
        ui->historylogs_button->setEnabled(true);
}

void UserHome::on_logoutbutton_clicked()
{
    this->hideallframes();
    ui->home_button->hide();
    ui->messaging_button->hide();
    ui->rates_button->hide();
    ui->acctmgmt_button->hide();
    ui->configsettings_button->hide();
    ui->connectionstatus_button->hide();
    ui->historylogs_button->hide();
    ui->survivor_button->hide();
    ui->line_separator->hide();
    ui->logo_upperleft->hide();
    ui->username_label->hide();
    ui->logoutbutton->hide();

    ui->logout_frame->show();
    ui->userhome_frame->hide();

    openbts->close();
    smqueue->close();
    sipauthserve->close();
    cli->write("quit\n");

    MainWindow mw;
    mw.connect_to_db();
    mw.addHistory("User has logged-out.");
    mw.deleteactiveuser();
}
