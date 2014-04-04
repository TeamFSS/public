#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_userhome.h"
#include "userhome.h"
#include "Qt"
#include "QDebug"
#include "processes.h"
#include <iostream>
#include <string>
#include "QMessageBox"

// Define module ids as according to DB
#define ADD_USER_ID 1
#define MOD_PRIV_ID 2
#define RATES_ID 3
#define SHORTCODES_ID 4
#define SURVIVOR_ID 5
#define CONFIGSET_ID 6
#define HISTORY_ID 7
#define MODIFY_USER_ID 8
#define COMMALERTS_ID 9

using namespace CryptoPP;
using namespace std;

string global_login = "temp";
int global_userid = 1;
string global_lastsucc = "temp";
string global_lasterror = "temp";

QSqlDatabase db;
QSqlDatabase TMSIdb;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Communect: Community Connect!");

    connect_to_TMSIdb();
    stringstream labeltext;
    int popu = this->getnumberofusers();
    if(popu != 0) {
        if (popu == 1)
            labeltext << popu << " user is currently connected.";
        else
            labeltext << popu << " users are currently connected.";

        ui->label->setText(QString::fromStdString(labeltext.str()));
    } else {
        ui->label->setText("");
    }
    ui->passwordline->setEchoMode(QLineEdit::Password);
    ui->loginbutton->setText("Login");
    ui->usernameline->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// For Logging-In
void MainWindow::on_loginbutton_clicked()
{
    connect_to_db();
    QString username = ui->usernameline->text();
    QString password = ui->passwordline->text();

    stringstream user;
    stringstream pass;

    user << username.toUtf8().constData() << "\n";
    pass << password.toUtf8().constData() << "\n";

    cli->write(user.str().c_str());
    cli->write(pass.str().c_str());

    int authsuccess = authenticateUser(username, password);

    // authentication successful
    if(authsuccess == 1) {
        ui->usernameline->setDisabled(true);
        ui->passwordline->setDisabled(true);

        QMessageBox messageBox;
        messageBox.critical(0,"Authentication successful.","Initializing Processes. Please wait...");

        sleep(5);

        UserHome *auserhome = new UserHome();
        auserhome->setWindowFlags(Qt::Widget);
        this->setCentralWidget(auserhome);
    }
    // authentication failed
    else if (authsuccess == 3){
        ui->passwordline->text();
        ui->main_notiflabel->setStyleSheet("QLabel { background-color : #FF8080; color : black;}");
        ui->main_notiflabel->setText("<center>Authentication Failed. Try again.</center>");
    }
    db.close();
}

// Connects to openbtsusers.db
void MainWindow::connect_to_db() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Users_DB);
    db.open();
}

// Connects to OpenBTSTMSITable.db
void MainWindow::connect_to_TMSIdb() {
    TMSIdb = QSqlDatabase::addDatabase("QSQLITE");
    TMSIdb.setDatabaseName(TMSI_DB);
    TMSIdb.open();
}

// Checks the login credentials
int MainWindow::authenticateUser(QString login, QString password)
{
    string uname = login.toUtf8().constData();
    string pass = password.toUtf8().constData();
    bool check;

    pass = passcheck(pass);
    check = logincheck(uname);

    // if username has special characters, authentication failed
    if(!check)
        return 3;

    // access db to check if user exists
    QSqlQuery query;
    query.prepare("select * from users where login= :loginval");
    query.bindValue(":loginval", QString::fromStdString(uname));
    query.exec();

    int userid_index = query.record().indexOf("userid");
    int insertedon_index = query.record().indexOf("insertedon");
    int systempass_index = query.record().indexOf("password");
    int failcnt_index = query.record().indexOf("failcounter");
    int faillogin_index = query.record().indexOf("lastfailedlogin");
    int succlogin_index = query.record().indexOf("lastsuccessfullogin");
    query.next();

    // if username does not exist
    if(!query.isValid()) {
        char* err = "<center>User does not exist. Please try again.</center>";
        ui->passwordline->setText("");
        ui->main_notiflabel->setStyleSheet("QLabel { background-color : #FF8080; color : black;}");
        ui->main_notiflabel->setText(err);
        return 2;
    }
    // user exists
    else {
        int userid = query.value(userid_index).toInt();
        string insertedon = query.value(insertedon_index).toString().toUtf8().constData();
        string hashedpass = sha256hash(sha256hash(pass) + insertedon);
        string systempass = query.value(systempass_index).toString().toUtf8().constData();
        int failcnt = query.value(failcnt_index).toInt();
        string faillogin = query.value(faillogin_index).toString().toUtf8().constData();
        string succlogin = query.value(succlogin_index).toString().toUtf8().constData();

        //************************************************************
        //CHECK IF n secs has passed after lastfaillogin START
        //if yes, reset: resetcounter
        time_t now;
        time(&now);
        int timedifference = now - atoi(faillogin.c_str());

        if(timedifference >= LOCKOUTPERIOD) {
            resetcounter(uname);
            failcnt = 0;
        }
        // END CHECK

        if(failcnt < 3) {
            if (systempass == hashedpass) {
                global_login = uname;
                global_userid = userid;
                global_lasterror = getStringDate(faillogin);
                global_lastsucc = getStringDate(succlogin);

                int shortcode_index = query.record().indexOf("shortcode");
                string shortcode = query.value(shortcode_index).toString().toUtf8().constData();
                deleteactiveuser();
                insertactiveuser(userid, shortcode);
            }
            else {
                return 3;
            }
        }
        else {
            stringstream err;
            err << "<center>Account has been locked. You may try again after " << (LOCKOUTPERIOD - timedifference) << " seconds.</center>";
            ui->passwordline->text();
            ui->main_notiflabel->setStyleSheet("QLabel { background-color : #FF8080; color : black;}");
            ui->main_notiflabel->setText(err.str().c_str());
            return 2;
        }
    }
    return 1;
}

// Removes invalid characters from the password input of user
string MainWindow::passcheck(string input)
{
    int ctr = 0;
    while(ctr < input.length())
    {
        if(input[ctr] == '\'')
        {
            input.insert(ctr, "'");
            ctr++;
        }
        ctr++;
    }
    return input;
}

// Checks if username is alphanumeric or the '.' or '_' characters
bool MainWindow::logincheck(string input)
{
    int ctr;
    for(ctr = 0; ctr < input.length(); ctr++)
    {
        if(isalnum(input[ctr]) == false)
        {
            if(input[ctr] != '.' && input[ctr] != '_')
            {
                return false;
            }
        }
    }
    return true;
}

// For password encryption
string MainWindow::sha256hash(string data)
{
    byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[SHA256::DIGESTSIZE];

    SHA256().CalculateDigest(abDigest, pbData, nDataLen);

    string encoded;
    HexEncoder encoder;
    encoder.Put(abDigest, sizeof(abDigest));
    encoder.MessageEnd();
    word64 size = encoder.MaxRetrievable();
    if(size)
    {
        encoded.resize(size);
        encoder.Get((byte*)encoded.data(), encoded.size());
    }

    return encoded;
}

// Resets the failcounter for lock-out
int MainWindow::resetcounter(string login)
{
    stringstream strm;
    strm << "update users set failcounter = 0 where login = '"  << login << "'";
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);

    return 0;
}

int MainWindow::deleteactiveuser()
{
    stringstream strm;
    strm << "DELETE FROM activeuser";
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);

    return 0;
}

int MainWindow::insertactiveuser(int userid, string shortcode)
{
    stringstream strm;

    if(shortcode == " ") {
        strm << "insert into activeuser(userid) values(" << userid << ")";
    } else {
        strm << "insert into activeuser(userid, shortcode) values(" << userid << ", '" << shortcode << "')";
    }

    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);

    return 0;
}

// For history logging
void MainWindow::addHistory (string desc)
{
    stringstream strm;
    strm << "insert into historylogs(userid, description) values(" << global_userid << ", '" << desc << "')";

    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
}

// Checks if username is already in use
bool MainWindow::userexists(string login)
{
    stringstream strm;
    strm << "select * from users where login = '" << login << "'";
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

// For adding new users
int MainWindow::insertnewuseropenbts(string login, string password)
{
    //Insert dummy row.
    stringstream strm;
    strm << "insert into users(login) values('" << login << "')";
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);

    //Update row with real password
    updateuseropenbts(login, password, false);

    return 0;
}

// For updating of the user's password
int MainWindow::updateuseropenbts(string login, string password, bool tag)
{
    stringstream strm;
    string insertedon = getinsertedon(login);
    string hashedpass = sha256hash(sha256hash(password) + insertedon);

    strm << "update users set password='" << hashedpass << "' where login='" << login << "'";

    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);

    return 0;
}

// Gets the timestamp for the salt
string MainWindow::getinsertedon(string login) {
    stringstream strm;
    strm << "select * from users where login = '" << login << "'";
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    int insertedon_index = query.record().indexOf("insertedon");
    query.next();
    string insertedon = query.value(insertedon_index).toString().toUtf8().constData();

    return insertedon;
}

// Changes the timestamp if password is updated
int MainWindow::pseudoupdate(QString logintomodify)
{
    stringstream strm;
    strm << "update users set insertedon = current_timestamp || (strftime('%f', 'now')) || random() where login = '"  << logintomodify.toUtf8().constData() << "';";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);
    return 0;
}

// For updating the user's attributes
bool MainWindow::updateuser_database(QString logintomodify, bool changepassword, bool changeshortcode, bool changepriv, bool grantrates, bool grantmodpriv, bool grantadduser, bool grantshortcodes, bool granthist, bool grantconfig, bool grantmodifuser, bool grantsendalerts, bool grantsurvrecord, QString newpassword, QString newshortcode) {

    if(changepassword) {
        newpassword = QString::fromStdString(passcheck(newpassword.toUtf8().constData()));
        pseudoupdate(logintomodify);
        updateuseropenbts(logintomodify.toUtf8().constData(), newpassword.toUtf8().constData(), true);
        stringstream desc;
        desc <<  "The password of account " << logintomodify.toUtf8().constData() << " has been updated!";
        addHistory(desc.str());
    }

    if(changeshortcode) {
        updateshortcode_actual(logintomodify.toUtf8().constData(), newshortcode.toUtf8().constData());
        stringstream desc;
        desc << "Shortcode for " << logintomodify.toUtf8().constData() << " has been updated to " << newshortcode.toUtf8().constData() << ".";
        addHistory(desc.str());
    }

    if(changepriv) {
        stringstream strm_new;
        strm_new << "select * from users where login = '" << logintomodify.toUtf8().constData() << "'";
        string s_new = strm_new.str();

        QSqlQuery query(QString::fromStdString(s_new), db);
        int index_target = query.record().indexOf("userid");
        query.next();
        int userid =  query.value(index_target).toInt();

        bool add_usermod = hasadduser(logintomodify);
        bool mod_privmod = hasmodpriv(logintomodify);
        bool ratesmod = hasrates(logintomodify);
        bool shortcodesmod = hasshortcodes(logintomodify);
        bool hist = hashistorylogs(logintomodify);
        bool configset = hasconfigsettings(logintomodify);
        bool modifyuser = hasmodifyuser(logintomodify);
        bool sendalerts = hassendalerts(logintomodify);
        bool survrecord = hassurvrecord(logintomodify);

        if(grantadduser && !add_usermod) {
            adduserpermission(ADD_USER_ID, userid);
        } else if(!grantadduser && add_usermod) {
            deleteuserpermission(ADD_USER_ID, userid);
        }

        if(grantmodpriv && !mod_privmod) {
            adduserpermission(MOD_PRIV_ID, userid);
        } else if(!grantmodpriv && mod_privmod) {
            deleteuserpermission(MOD_PRIV_ID, userid);
        }

        if(grantrates && !ratesmod) {
            adduserpermission(RATES_ID, userid);
        } else if(!grantrates && ratesmod) {
            deleteuserpermission(RATES_ID, userid);
        }

        if (grantshortcodes && !shortcodesmod) {
            adduserpermission(SHORTCODES_ID, userid);
        } else if(!grantshortcodes && shortcodesmod) {
            deleteuserpermission(SHORTCODES_ID, userid);
        }

        if (granthist && !hist) {
            adduserpermission(HISTORY_ID, userid);
        } else if(!granthist && hist) {
            deleteuserpermission(HISTORY_ID, userid);
        }
        if (grantconfig && !configset) {
            adduserpermission(CONFIGSET_ID, userid);
        } else if(!grantconfig && configset) {
            deleteuserpermission(CONFIGSET_ID, userid);
        }
        if (grantmodifuser && !modifyuser) {
            adduserpermission(MODIFY_USER_ID, userid);
        } else if(!grantmodifuser && modifyuser) {
            deleteuserpermission(MODIFY_USER_ID, userid);
        }
        if (grantsendalerts && !sendalerts) {
            adduserpermission(COMMALERTS_ID, userid);
        } else if(!grantsendalerts && sendalerts) {
            deleteuserpermission(COMMALERTS_ID, userid);
        }
        if (grantsurvrecord && !survrecord) {
            adduserpermission(SURVIVOR_ID, userid);
        } else if(!grantsurvrecord && survrecord) {
            deleteuserpermission(SURVIVOR_ID, userid);
        }
    }
}

// Updates the shortcode of the user
int MainWindow::updateshortcode_actual(string login, string newshortcode)
{
    stringstream strm;
    strm << "update users set shortcode = '" << newshortcode << "' where login = '"  << login << "';";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);
    return 0;
}

// Deletes user permission to a specific module
void MainWindow::deleteuserpermission(int moduleid, int userid) {
    qDebug() << moduleid;
    stringstream strm;
    strm << "delete from userpermissions where userid = " << userid << " and moduleid = " << moduleid;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);

    // get username of user
    strm.str("");
    strm.clear();
    strm << "select * from users where userid = '" << userid << "'";
    s = strm.str();
    QSqlQuery query2(QString::fromStdString(s), db);
    int login_index = query2.record().indexOf("login");
    query2.next();
    string login = query2.value(login_index).toString().toUtf8().constData();

    // get module name of module
    strm.str("");
    strm.clear();
    strm << "select * from modules where moduleid = '" << moduleid << "'";
    s = strm.str();
    QSqlQuery query3(QString::fromStdString(s), db);
    int module_index = query3.record().indexOf("modulename");
    query3.next();
    string module = query3.value(module_index).toString().toUtf8().constData();

    // Updates history logs
    stringstream desc;
    desc <<  "Access to module: " << module << " has been denied to user: " << login << ".";
    addHistory(desc.str());
}

// Gives the user permission to a certain module
void MainWindow::adduserpermission(int moduleid, int userid) {
    qDebug() << moduleid;
    stringstream strm;
    strm << "insert into userpermissions(userid, moduleid) values(" << userid << "," << moduleid << ")";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);

     stringstream desc;

    // get username of user
    strm.str("");
    strm.clear();
    strm << "select * from users where userid = '" << userid << "'";
    s = strm.str();
    QSqlQuery query2(QString::fromStdString(s), db);
    int login_index = query2.record().indexOf("login");
    query2.next();
    string login = query2.value(login_index).toString().toUtf8().constData();

    // get module name of module
    strm.str("");
    strm.clear();
    strm << "select * from modules where moduleid = '" << moduleid << "'";
    s = strm.str();
    QSqlQuery query3(QString::fromStdString(s), db);
    int module_index = query3.record().indexOf("modulename");
    query3.next();
    string module = query3.value(module_index).toString().toUtf8().constData();

    desc <<  "Access to module: " << module << " has been granted to user: " << login << ".";
    addHistory(desc.str());
}

string MainWindow::getshortcodeofuser(QString login) {
    stringstream strm;
    strm << "select * from users where login = '" << login.toUtf8().constData() << "'";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);
    int shortcode_index = query.record().indexOf("shortcode");
    query.next();
    string shortcode = query.value(shortcode_index).toString().toUtf8().constData();

    return shortcode;
}

// CHECKS IF THE USER HAS PRIVILEGES TO THE FOLLOWING MODULES
bool MainWindow::hasadduser(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << ADD_USER_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hasmodpriv(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << MOD_PRIV_ID;
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hasrates(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << RATES_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hasshortcodes(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << SHORTCODES_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hashistorylogs(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << HISTORY_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hasconfigsettings(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << CONFIGSET_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hasmodifyuser(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << MODIFY_USER_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hassendalerts(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << COMMALERTS_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

bool MainWindow::hassurvrecord(QString login) {
    stringstream strm;
    strm << "select * from userpermissions join users using (userid) where login = '" << login.toUtf8().constData() << "' and moduleid = " << SURVIVOR_ID;
    string s = strm.str();

    QSqlQuery query(QString::fromStdString(s), db);
    query.next();

    if(query.isValid()) {
        return true;
    }
    return false;
}

// If user clicks on the return/enter button on their keyboard, the button on the GUI is clicked as well
void MainWindow::on_passwordline_returnPressed()
{
    ui->loginbutton->click();
}

void MainWindow::on_usernameline_returnPressed()
{
    ui->loginbutton->click();
}

// Gets the number of users currently connected to the network
int MainWindow::getnumberofusers() {
    stringstream strm;
    strm << "select count(*) as counter from TMSI_TABLE";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), TMSIdb);
    int counter_index = query.record().indexOf("counter");
    query.next();
    int counterdata = query.value(counter_index).toInt();

    return counterdata;
}

// Gets the Date in String format
string MainWindow::getStringDate(string unixTimestamp)
{
    string q = "select datetime(" + unixTimestamp + ", 'unixepoch', 'localtime') as dateresult;";
    QSqlQuery query(QString::fromStdString(q), db);
    query.next();
    int counter_index = query.record().indexOf("dateresult");
    QString tempcounterdata = query.value(counter_index).toString();
    string tempdata = tempcounterdata.toUtf8().constData();
    return tempdata;
}

// Gets the password of the user
string MainWindow::getpasswordofuser(QString login) {
    stringstream strm;
    strm << "select password from users where login = '" << login.toUtf8().constData() <<"'";
    string s = strm.str();
    QSqlQuery query(QString::fromStdString(s), TMSIdb);
    int counter_index = query.record().indexOf("password");
    query.next();
    string password = query.value(counter_index).toString().toUtf8().constData();
    return password;
}
