#ifndef MESSAGES_H
#define MESSAGES_H

#include <QDialog>

namespace Ui {
class messages;
}

class Messages : public QDialog
{
    Q_OBJECT

public:
    explicit Messages(QWidget *parent = 0);
    ~Messages();

private:
    Ui::messages *ui;
};

#endif // MESSAGES_H
