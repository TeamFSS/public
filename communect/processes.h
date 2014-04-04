#ifndef PROCESSES_H
#define PROCESSES_H

#include <QObject>
#include "QProcess"

extern QProcess *sipauthserve, *smqueue, *openbts, *cli;

namespace Ui {
    class Processes;
}

class Processes : public QObject
{
    Q_OBJECT
public:
    explicit Processes(QObject *parent = 0);
    ~Processes();
    void startProcesses();

signals:

public slots:

private:
    Ui::Processes *ui;
};

#endif // PROCESSES_H
