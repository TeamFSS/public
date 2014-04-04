#ifndef ACCOUNTSMANAGEMENT_H
#define ACCOUNTSMANAGEMENT_H

#include <QDialog>

namespace Ui {
class AccountsManagement;
}

class AccountsManagement : public QDialog
{
    Q_OBJECT

public:
    explicit AccountsManagement(QWidget *parent = 0);
    ~AccountsManagement();

private:
    Ui::AccountsManagement *ui;
};

#endif // ACCOUNTSMANAGEMENT_H
