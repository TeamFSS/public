#ifndef UNITCOMMUNICATION_H
#define UNITCOMMUNICATION_H

#include <QDialog>

namespace Ui {
class UnitCommunication;
}

class UnitCommunication : public QDialog
{
    Q_OBJECT

public:
    explicit UnitCommunication(QWidget *parent = 0);
    ~UnitCommunication();

private:
    Ui::UnitCommunication *ui;
};

#endif // UNITCOMMUNICATION_H
