#ifndef COMMUNITYALERTS_H
#define COMMUNITYALERTS_H

#include <QDialog>

namespace Ui {
class CommunityAlerts;
}

class CommunityAlerts : public QDialog
{
    Q_OBJECT

public:
    explicit CommunityAlerts(QWidget *parent = 0);
    ~CommunityAlerts();

private:
    Ui::CommunityAlerts *ui;
};

#endif // COMMUNITYALERTS_H
