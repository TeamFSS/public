#include "unitcommunication.h"
#include "ui_unitcommunication.h"

UnitCommunication::UnitCommunication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnitCommunication)
{
    ui->setupUi(this);
}

UnitCommunication::~UnitCommunication()
{
    delete ui;
}
