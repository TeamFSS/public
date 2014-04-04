#include "messages.h"
#include "ui_messages.h"

Messages::Messages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messages)
{
    ui->setupUi(this);
}

Messages::~Messages()
{
    delete ui;
}
