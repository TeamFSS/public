#include "communityalerts.h"
#include "ui_communityalerts.h"

CommunityAlerts::CommunityAlerts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommunityAlerts)
{
    ui->setupUi(this);
}

CommunityAlerts::~CommunityAlerts()
{
    delete ui;
}
