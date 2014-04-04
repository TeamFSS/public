#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// for streams
#include <iostream>
#include <sstream>
#include <algorithm>

// for crypto++
#include "hex.h"
#include "sha.h"
#include "cryptlib.h"
#include <termios.h>
#include <unistd.h>

// for DB access
#define Users_DB "/home/fss/public/openbts/trunk/apps/openbtsusers.db"
#define TMSI_DB "/var/run/OpenBTSTMSITable.db"
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>

// for time
#include <time.h>

// for lock-out
#define LOCKOUTPERIOD 3600

using namespace std;

extern int global_userid;
extern string global_login;
extern string global_lastsucc;
extern string global_lasterror;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void connect_to_db();
    void connect_to_TMSIdb();

    int authenticateUser(QString, QString);
    bool logincheck(string);
    string passcheck(string);
    string sha256hash(string);
    int resetcounter(string);
    int deleteactiveuser();
    int insertactiveuser(int, string);

    void addHistory (string);

    int insertnewuseropenbts(string, string);
    int updateuseropenbts(string, string, bool);
    string getinsertedon(string);
    bool userexists(string);
    int pseudoupdate(QString);
    bool updateuser_database(QString, bool, bool, bool, bool, bool, bool, bool,bool,bool,bool,bool,bool, QString, QString);
    int updateshortcode_actual(string, string);
    void deleteuserpermission(int, int);
    void adduserpermission(int, int);
    string getshortcodeofuser(QString);
    int getnumberofusers();
    string getStringDate(string);
    string getpasswordofuser(QString);

    bool hasadduser(QString);
    bool hasmodpriv(QString);
    bool hasrates(QString);
    bool hasshortcodes(QString);
    bool hashistorylogs(QString);
    bool hasconfigsettings(QString);
    bool hasmodifyuser(QString);
    bool hassendalerts(QString);
    bool hassurvrecord(QString);

private slots:
    void on_loginbutton_clicked();
    void on_passwordline_returnPressed();
    void on_usernameline_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
