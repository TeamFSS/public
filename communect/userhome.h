#ifndef USERHOME_H
#define USERHOME_H

#include <QDialog>
#include <QComboBox>
#include <QAbstractButton>

namespace Ui {
class UserHome;
}

class UserHome : public QDialog
{
    Q_OBJECT

public:
    explicit UserHome(QWidget *parent = 0);
    ~UserHome();

private slots:
    void on_home_button_clicked();
    void on_logoutbutton_clicked();

    void on_rates_button_clicked();
    void on_rates_savebutton_clicked();
    void rates_service_changed();
    void on_rates_cancelbutton_clicked();

    void on_historylogs_button_clicked();
    void historylogs_day_changed();
    void historylogs_datefixer();

    void on_acctmgmt_button_clicked();
    void on_saveacctbutton_clicked();
    void on_changepass_checkbox_toggled(bool checked);
    void on_changeshortcode_checkbox_toggled(bool checked);
    void on_modifypriv_checkbox_toggled(bool checked);
    void on_acctmgmt_cancelbutton_clicked();
    void on_adduser_button_clicked();
    void on_addusercancel_button_clicked();
    void on_addusersave_button_clicked();
    void on_modifyuser_button_clicked();
    void on_searchuser_button_clicked();
    void on_searchuserline_returnPressed();
    void on_searchuserline_editingFinished();

    void on_messaging_button_clicked();
    void on_communityalerts_button_clicked();
    void on_commalertscancel_button_clicked();
    void on_commalertssend_button_clicked();
    void on_unitcommunication_button_clicked();
    void on_unitcommcancel_button_clicked();
    void on_unitcommsend_button_clicked();

    void on_configsettings_button_clicked();
    void configsettings_changed();
    void on_configsettings_save_button_clicked();
    void on_configsettings_cancel_button_clicked();
    void configsettings_delete_clicked();
    void configsettings_edit_clicked();
    void on_addconfig_button_clicked();
    void on_configsettings_createsave_button_clicked();
    void on_configsettings_createcancel_button_clicked();
    void on_modifyconfig_button_clicked();

    void on_survivor_button_clicked();
    void survivor_datefixer();
    void survivor_day_changed();
    void generate_days(QComboBox *, QComboBox *, QComboBox *);
    QString get_date(QComboBox *, QComboBox *, QComboBox *);

    void on_connectionstatus_button_clicked();

    void checkpermissions();

    void hideallframes();

private:
    Ui::UserHome *ui;
};

#endif // USERHOME_H
