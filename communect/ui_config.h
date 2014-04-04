/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Fri Mar 28 11:36:32 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QFrame *addconfig_frame;
    QLabel *configsettings_create_name_label;
    QLabel *configsettings_value_name_label;
    QLabel *configsettings_comment_name_label;
    QLineEdit *configsettings_name_line;
    QLineEdit *configsettings_value_line;
    QLineEdit *configsettings_comment_line;
    QPushButton *configsettings_createcancel_button;
    QPushButton *configsettings_createsave_button;
    QFrame *modifyconfig_frame_2;
    QCheckBox *configsettings_create_checkBox;
    QLabel *configsettings_create_name_label_2;
    QLabel *configsettings_value_name_label_2;
    QLabel *configsettings_comment_name_label_2;
    QLineEdit *configsettings_name_line_2;
    QLineEdit *configsettings_value_line_2;
    QLineEdit *configsettings_comment_line_2;
    QComboBox *configsettings_comboBox;
    QLabel *configsettings_oldvalue_label;
    QLabel *configsettings_newvalue_label;
    QLineEdit *configsettings_oldvalue_line;
    QLineEdit *configsettings_newvalue_line;
    QPushButton *configsettings_cancel_button;
    QFrame *confisettings_separatingline;
    QPushButton *configsettings_save_button;
    QRadioButton *configsettings_edit_radiobutton;
    QRadioButton *configsettings_delete_radiobutton;
    QFrame *modifyconfig_frame_3;
    QComboBox *configsettings_comboBox_4;
    QLabel *configsettings_oldvalue_label_4;
    QLabel *configsettings_newvalue_label_4;
    QLineEdit *configsettings_oldvalue_line_4;
    QLineEdit *configsettings_newvalue_line_4;
    QPushButton *configsettings_cancel_button_4;
    QPushButton *configsettings_save_button_4;
    QRadioButton *configsettings_edit_radiobutton_4;
    QRadioButton *configsettings_delete_radiobutton_4;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(762, 511);
        addconfig_frame = new QFrame(Config);
        addconfig_frame->setObjectName(QString::fromUtf8("addconfig_frame"));
        addconfig_frame->setGeometry(QRect(40, 130, 461, 361));
        addconfig_frame->setFrameShape(QFrame::StyledPanel);
        addconfig_frame->setFrameShadow(QFrame::Raised);
        configsettings_create_name_label = new QLabel(addconfig_frame);
        configsettings_create_name_label->setObjectName(QString::fromUtf8("configsettings_create_name_label"));
        configsettings_create_name_label->setGeometry(QRect(60, 115, 57, 15));
        configsettings_value_name_label = new QLabel(addconfig_frame);
        configsettings_value_name_label->setObjectName(QString::fromUtf8("configsettings_value_name_label"));
        configsettings_value_name_label->setGeometry(QRect(60, 165, 57, 15));
        configsettings_comment_name_label = new QLabel(addconfig_frame);
        configsettings_comment_name_label->setObjectName(QString::fromUtf8("configsettings_comment_name_label"));
        configsettings_comment_name_label->setGeometry(QRect(60, 215, 71, 16));
        configsettings_name_line = new QLineEdit(addconfig_frame);
        configsettings_name_line->setObjectName(QString::fromUtf8("configsettings_name_line"));
        configsettings_name_line->setGeometry(QRect(140, 110, 251, 23));
        configsettings_value_line = new QLineEdit(addconfig_frame);
        configsettings_value_line->setObjectName(QString::fromUtf8("configsettings_value_line"));
        configsettings_value_line->setGeometry(QRect(140, 160, 251, 23));
        configsettings_comment_line = new QLineEdit(addconfig_frame);
        configsettings_comment_line->setObjectName(QString::fromUtf8("configsettings_comment_line"));
        configsettings_comment_line->setGeometry(QRect(140, 210, 251, 23));
        configsettings_createcancel_button = new QPushButton(addconfig_frame);
        configsettings_createcancel_button->setObjectName(QString::fromUtf8("configsettings_createcancel_button"));
        configsettings_createcancel_button->setGeometry(QRect(140, 290, 80, 23));
        configsettings_createsave_button = new QPushButton(addconfig_frame);
        configsettings_createsave_button->setObjectName(QString::fromUtf8("configsettings_createsave_button"));
        configsettings_createsave_button->setGeometry(QRect(310, 290, 80, 23));
        modifyconfig_frame_2 = new QFrame(Config);
        modifyconfig_frame_2->setObjectName(QString::fromUtf8("modifyconfig_frame_2"));
        modifyconfig_frame_2->setGeometry(QRect(60, 20, 461, 361));
        modifyconfig_frame_2->setFrameShape(QFrame::StyledPanel);
        modifyconfig_frame_2->setFrameShadow(QFrame::Raised);
        configsettings_create_checkBox = new QCheckBox(modifyconfig_frame_2);
        configsettings_create_checkBox->setObjectName(QString::fromUtf8("configsettings_create_checkBox"));
        configsettings_create_checkBox->setGeometry(QRect(60, 15, 85, 21));
        configsettings_create_name_label_2 = new QLabel(modifyconfig_frame_2);
        configsettings_create_name_label_2->setObjectName(QString::fromUtf8("configsettings_create_name_label_2"));
        configsettings_create_name_label_2->setGeometry(QRect(60, 50, 57, 15));
        configsettings_value_name_label_2 = new QLabel(modifyconfig_frame_2);
        configsettings_value_name_label_2->setObjectName(QString::fromUtf8("configsettings_value_name_label_2"));
        configsettings_value_name_label_2->setGeometry(QRect(60, 80, 57, 15));
        configsettings_comment_name_label_2 = new QLabel(modifyconfig_frame_2);
        configsettings_comment_name_label_2->setObjectName(QString::fromUtf8("configsettings_comment_name_label_2"));
        configsettings_comment_name_label_2->setGeometry(QRect(60, 110, 71, 16));
        configsettings_name_line_2 = new QLineEdit(modifyconfig_frame_2);
        configsettings_name_line_2->setObjectName(QString::fromUtf8("configsettings_name_line_2"));
        configsettings_name_line_2->setGeometry(QRect(140, 45, 251, 23));
        configsettings_value_line_2 = new QLineEdit(modifyconfig_frame_2);
        configsettings_value_line_2->setObjectName(QString::fromUtf8("configsettings_value_line_2"));
        configsettings_value_line_2->setGeometry(QRect(140, 75, 251, 23));
        configsettings_comment_line_2 = new QLineEdit(modifyconfig_frame_2);
        configsettings_comment_line_2->setObjectName(QString::fromUtf8("configsettings_comment_line_2"));
        configsettings_comment_line_2->setGeometry(QRect(140, 105, 251, 23));
        configsettings_comboBox = new QComboBox(modifyconfig_frame_2);
        configsettings_comboBox->setObjectName(QString::fromUtf8("configsettings_comboBox"));
        configsettings_comboBox->setGeometry(QRect(60, 165, 331, 23));
        configsettings_oldvalue_label = new QLabel(modifyconfig_frame_2);
        configsettings_oldvalue_label->setObjectName(QString::fromUtf8("configsettings_oldvalue_label"));
        configsettings_oldvalue_label->setGeometry(QRect(60, 237, 81, 16));
        configsettings_newvalue_label = new QLabel(modifyconfig_frame_2);
        configsettings_newvalue_label->setObjectName(QString::fromUtf8("configsettings_newvalue_label"));
        configsettings_newvalue_label->setGeometry(QRect(60, 267, 81, 16));
        configsettings_oldvalue_line = new QLineEdit(modifyconfig_frame_2);
        configsettings_oldvalue_line->setObjectName(QString::fromUtf8("configsettings_oldvalue_line"));
        configsettings_oldvalue_line->setEnabled(false);
        configsettings_oldvalue_line->setGeometry(QRect(140, 235, 251, 23));
        configsettings_newvalue_line = new QLineEdit(modifyconfig_frame_2);
        configsettings_newvalue_line->setObjectName(QString::fromUtf8("configsettings_newvalue_line"));
        configsettings_newvalue_line->setGeometry(QRect(140, 265, 251, 23));
        configsettings_cancel_button = new QPushButton(modifyconfig_frame_2);
        configsettings_cancel_button->setObjectName(QString::fromUtf8("configsettings_cancel_button"));
        configsettings_cancel_button->setGeometry(QRect(140, 320, 80, 23));
        confisettings_separatingline = new QFrame(modifyconfig_frame_2);
        confisettings_separatingline->setObjectName(QString::fromUtf8("confisettings_separatingline"));
        confisettings_separatingline->setGeometry(QRect(0, 140, 461, 16));
        confisettings_separatingline->setFrameShape(QFrame::HLine);
        confisettings_separatingline->setFrameShadow(QFrame::Sunken);
        configsettings_save_button = new QPushButton(modifyconfig_frame_2);
        configsettings_save_button->setObjectName(QString::fromUtf8("configsettings_save_button"));
        configsettings_save_button->setGeometry(QRect(310, 320, 80, 23));
        configsettings_edit_radiobutton = new QRadioButton(modifyconfig_frame_2);
        configsettings_edit_radiobutton->setObjectName(QString::fromUtf8("configsettings_edit_radiobutton"));
        configsettings_edit_radiobutton->setGeometry(QRect(60, 200, 100, 21));
        configsettings_delete_radiobutton = new QRadioButton(modifyconfig_frame_2);
        configsettings_delete_radiobutton->setObjectName(QString::fromUtf8("configsettings_delete_radiobutton"));
        configsettings_delete_radiobutton->setGeometry(QRect(220, 200, 100, 21));
        configsettings_create_checkBox->raise();
        configsettings_create_name_label_2->raise();
        configsettings_value_name_label_2->raise();
        configsettings_comment_name_label_2->raise();
        configsettings_name_line_2->raise();
        configsettings_value_line_2->raise();
        configsettings_comment_line_2->raise();
        configsettings_comboBox->raise();
        configsettings_oldvalue_label->raise();
        configsettings_newvalue_label->raise();
        configsettings_oldvalue_line->raise();
        configsettings_newvalue_line->raise();
        configsettings_cancel_button->raise();
        confisettings_separatingline->raise();
        configsettings_save_button->raise();
        configsettings_edit_radiobutton->raise();
        configsettings_delete_radiobutton->raise();
        modifyconfig_frame_3 = new QFrame(Config);
        modifyconfig_frame_3->setObjectName(QString::fromUtf8("modifyconfig_frame_3"));
        modifyconfig_frame_3->setGeometry(QRect(210, 120, 461, 361));
        modifyconfig_frame_3->setFrameShape(QFrame::StyledPanel);
        modifyconfig_frame_3->setFrameShadow(QFrame::Raised);
        configsettings_comboBox_4 = new QComboBox(modifyconfig_frame_3);
        configsettings_comboBox_4->setObjectName(QString::fromUtf8("configsettings_comboBox_4"));
        configsettings_comboBox_4->setGeometry(QRect(60, 60, 331, 23));
        configsettings_oldvalue_label_4 = new QLabel(modifyconfig_frame_3);
        configsettings_oldvalue_label_4->setObjectName(QString::fromUtf8("configsettings_oldvalue_label_4"));
        configsettings_oldvalue_label_4->setGeometry(QRect(60, 165, 81, 16));
        configsettings_newvalue_label_4 = new QLabel(modifyconfig_frame_3);
        configsettings_newvalue_label_4->setObjectName(QString::fromUtf8("configsettings_newvalue_label_4"));
        configsettings_newvalue_label_4->setGeometry(QRect(60, 215, 81, 16));
        configsettings_oldvalue_line_4 = new QLineEdit(modifyconfig_frame_3);
        configsettings_oldvalue_line_4->setObjectName(QString::fromUtf8("configsettings_oldvalue_line_4"));
        configsettings_oldvalue_line_4->setEnabled(false);
        configsettings_oldvalue_line_4->setGeometry(QRect(140, 160, 251, 23));
        configsettings_newvalue_line_4 = new QLineEdit(modifyconfig_frame_3);
        configsettings_newvalue_line_4->setObjectName(QString::fromUtf8("configsettings_newvalue_line_4"));
        configsettings_newvalue_line_4->setGeometry(QRect(140, 210, 251, 23));
        configsettings_cancel_button_4 = new QPushButton(modifyconfig_frame_3);
        configsettings_cancel_button_4->setObjectName(QString::fromUtf8("configsettings_cancel_button_4"));
        configsettings_cancel_button_4->setGeometry(QRect(140, 290, 80, 23));
        configsettings_save_button_4 = new QPushButton(modifyconfig_frame_3);
        configsettings_save_button_4->setObjectName(QString::fromUtf8("configsettings_save_button_4"));
        configsettings_save_button_4->setGeometry(QRect(310, 290, 80, 23));
        configsettings_edit_radiobutton_4 = new QRadioButton(modifyconfig_frame_3);
        configsettings_edit_radiobutton_4->setObjectName(QString::fromUtf8("configsettings_edit_radiobutton_4"));
        configsettings_edit_radiobutton_4->setGeometry(QRect(60, 110, 100, 21));
        configsettings_delete_radiobutton_4 = new QRadioButton(modifyconfig_frame_3);
        configsettings_delete_radiobutton_4->setObjectName(QString::fromUtf8("configsettings_delete_radiobutton_4"));
        configsettings_delete_radiobutton_4->setGeometry(QRect(220, 100, 100, 21));

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Dialog", 0));
        configsettings_create_name_label->setText(QApplication::translate("Config", "Name:", 0));
        configsettings_value_name_label->setText(QApplication::translate("Config", "Value:", 0));
        configsettings_comment_name_label->setText(QApplication::translate("Config", "Comment:", 0));
        configsettings_createcancel_button->setText(QApplication::translate("Config", "Cancel", 0));
        configsettings_createsave_button->setText(QApplication::translate("Config", "Save", 0));
        configsettings_create_checkBox->setText(QApplication::translate("Config", "Create ", 0));
        configsettings_create_name_label_2->setText(QApplication::translate("Config", "Name:", 0));
        configsettings_value_name_label_2->setText(QApplication::translate("Config", "Value:", 0));
        configsettings_comment_name_label_2->setText(QApplication::translate("Config", "Comment:", 0));
        configsettings_oldvalue_label->setText(QApplication::translate("Config", "Old Value:", 0));
        configsettings_newvalue_label->setText(QApplication::translate("Config", "New value:", 0));
        configsettings_cancel_button->setText(QApplication::translate("Config", "Cancel", 0));
        configsettings_save_button->setText(QApplication::translate("Config", "Save", 0));
        configsettings_edit_radiobutton->setText(QApplication::translate("Config", "Edit", 0));
        configsettings_delete_radiobutton->setText(QApplication::translate("Config", "Delete", 0));
        configsettings_oldvalue_label_4->setText(QApplication::translate("Config", "Old Value:", 0));
        configsettings_newvalue_label_4->setText(QApplication::translate("Config", "New value:", 0));
        configsettings_cancel_button_4->setText(QApplication::translate("Config", "Cancel", 0));
        configsettings_save_button_4->setText(QApplication::translate("Config", "Save", 0));
        configsettings_edit_radiobutton_4->setText(QApplication::translate("Config", "Edit", 0));
        configsettings_delete_radiobutton_4->setText(QApplication::translate("Config", "Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
