/********************************************************************************
** Form generated from reading UI file 'historylogs.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYLOGS_H
#define UI_HISTORYLOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_HistoryLogs
{
public:
    QFrame *hstrylog_frame;
    QLabel *label;
    QTableView *tableView;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QFrame *line;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *HistoryLogs)
    {
        if (HistoryLogs->objectName().isEmpty())
            HistoryLogs->setObjectName(QStringLiteral("HistoryLogs"));
        HistoryLogs->resize(773, 698);
        hstrylog_frame = new QFrame(HistoryLogs);
        hstrylog_frame->setObjectName(QStringLiteral("hstrylog_frame"));
        hstrylog_frame->setGeometry(QRect(270, 140, 461, 361));
        hstrylog_frame->setFrameShape(QFrame::StyledPanel);
        hstrylog_frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(hstrylog_frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 57, 15));
        tableView = new QTableView(hstrylog_frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 60, 401, 271));
        label_2 = new QLabel(HistoryLogs);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 201, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_2->setScaledContents(true);
        pushButton_5 = new QPushButton(HistoryLogs);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 270, 181, 41));
        pushButton_6 = new QPushButton(HistoryLogs);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 310, 181, 41));
        pushButton_3 = new QPushButton(HistoryLogs);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 190, 181, 41));
        pushButton_4 = new QPushButton(HistoryLogs);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 230, 181, 41));
        pushButton_2 = new QPushButton(HistoryLogs);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 150, 181, 41));
        pushButton_7 = new QPushButton(HistoryLogs);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 350, 181, 41));
        line = new QFrame(HistoryLogs);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 90, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(HistoryLogs);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(380, 70, 271, 20));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        pushButton = new QPushButton(HistoryLogs);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(669, 70, 61, 23));

        retranslateUi(HistoryLogs);

        QMetaObject::connectSlotsByName(HistoryLogs);
    } // setupUi

    void retranslateUi(QDialog *HistoryLogs)
    {
        HistoryLogs->setWindowTitle(QApplication::translate("HistoryLogs", "Dialog", 0));
        label->setText(QApplication::translate("HistoryLogs", "Date", 0));
        label_2->setText(QString());
        pushButton_5->setText(QApplication::translate("HistoryLogs", "Rates Management", 0));
        pushButton_6->setText(QApplication::translate("HistoryLogs", "Connection Status", 0));
        pushButton_3->setText(QApplication::translate("HistoryLogs", "Messaging", 0));
        pushButton_4->setText(QApplication::translate("HistoryLogs", "Accounts Management", 0));
        pushButton_2->setText(QApplication::translate("HistoryLogs", "Home", 0));
        pushButton_7->setText(QApplication::translate("HistoryLogs", "History Logs", 0));
        label_3->setText(QApplication::translate("HistoryLogs", "You are logged in as ____________", 0));
        pushButton->setText(QApplication::translate("HistoryLogs", "Logout", 0));
    } // retranslateUi

};

namespace Ui {
    class HistoryLogs: public Ui_HistoryLogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYLOGS_H
