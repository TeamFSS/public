#ifndef SEARCHUSER_H
#define SEARCHUSER_H

#include <QDialog>

namespace Ui {
class searchuser;
}

class searchuser : public QDialog
{
    Q_OBJECT

public:
    explicit searchuser(QWidget *parent = 0);
    ~searchuser();

private:
    Ui::searchuser *ui;
};

#endif // SEARCHUSER_H
