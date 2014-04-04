#include "QProcess"
#include <processes.h>
#include <QDebug>
#include <iostream>
#include <sstream>

#define WORKINGDIRECTORY "/home/fss/public/"

using namespace std;

QProcess *sipauthserve = new QProcess();
QProcess *smqueue = new QProcess();
QProcess *openbts = new QProcess();
QProcess *cli = new QProcess();

Processes::Processes(QObject *parent) :
    QObject(parent)
{
}

Processes::~Processes()
{
    delete ui;
}

void Processes::startProcesses()
{
    /***************************************
     * OPEN PROCESSES USING SEVERAL XTERMS *
     ***************************************/

    QString xterm = "xterm";

    stringstream ss;
    ss << WORKINGDIRECTORY << "/subscriberRegistry/trunk/";
    string sip_path = ss.str();
    QStringList sip_args;
    sip_args << "-e" << "./sipauthserve";
    sipauthserve->setWorkingDirectory(QString::fromStdString(sip_path));
    sipauthserve->start(xterm, sip_args);

    ss.str("");
    ss.clear();
    ss << WORKINGDIRECTORY << "/smqueue/trunk/smqueue/";
    string sm_path = ss.str();
    QStringList smq_args;
    smq_args << "-e" << "./smqueue";
    smqueue->setWorkingDirectory(QString::fromStdString(sm_path));
    smqueue->start(xterm, smq_args);

    ss.str("");
    ss.clear();
    ss << WORKINGDIRECTORY << "/openbts/trunk/apps/";
    string openbts_path = ss.str();
    QStringList openbts_args;
    openbts_args << "-e" << "./OpenBTS";
    openbts->setWorkingDirectory(QString::fromStdString(openbts_path));
    openbts->start(xterm, openbts_args);

    string cli_path = ss.str();
    cli->setWorkingDirectory(QString::fromStdString(cli_path));
    cli->start("./OpenBTSCLI");
    cli->waitForStarted();
}
