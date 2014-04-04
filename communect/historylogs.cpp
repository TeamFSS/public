#include <QStandardItemModel>

#include "historylogs.h"
#include "ui_historylogs.h"

HistoryLogs::HistoryLogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryLogs)
{

    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Time")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Action Made")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("User")));
    ui->tableView->setModel(model);

    //ui->tableView->resizeRowsToContents(); // Adjust the row height.
    //ui->tableView->resizeColumnsToContents(); // Adjust the column width.
    ui->tableView->setColumnWidth( 0, 75 );
    ui->tableView->setColumnWidth( 1, 232 );
    ui->tableView->setColumnWidth( 2, 75 );
    ui->tableView->setWordWrap(true);
    ui->tableView->setSortingEnabled(true);
}

HistoryLogs::~HistoryLogs()
{
    delete ui;
}
