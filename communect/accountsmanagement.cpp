#include "accountsmanagement.h"
#include "ui_accountsmanagement.h"

AccountsManagement::AccountsManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountsManagement)
{
    ui->setupUi(this);
}

AccountsManagement::~AccountsManagement()
{
    delete ui;
}
