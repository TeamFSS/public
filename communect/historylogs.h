#ifndef HISTORYLOGS_H
#define HISTORYLOGS_H

#include <QDialog>

namespace Ui {
class HistoryLogs;
}

class HistoryLogs : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryLogs(QWidget *parent = 0);
    ~HistoryLogs();

private:
    Ui::HistoryLogs *ui;
};

#endif // HISTORYLOGS_H
