/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
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

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QFrame *frame;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QStringLiteral("Config"));
        Config->resize(762, 511);
        frame = new QFrame(Config);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(90, 60, 461, 361));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 80, 271, 23));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(120, 150, 85, 21));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 190, 111, 16));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 230, 121, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 40, 57, 21));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 230, 131, 23));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 290, 80, 23));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 290, 80, 23));

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Config", "CLI.SocketPath", 0)
         << QApplication::translate("Config", "Control.Reporting.PhysStatusTable", 0)
         << QApplication::translate("Config", "Control.Reporting.TransactionTable", 0)
         << QApplication::translate("Config", "Control.Reporting.StatsTable", 0)
         << QApplication::translate("Config", "Control.Reporting.TMSITable", 0)
         << QApplication::translate("Config", "Control.Call.QueryRRLP.Early", 0)
         << QApplication::translate("Config", "Control.Call.QueryRRLP.Late", 0)
         << QApplication::translate("Config", "Control.GSMTAP.TargetIP", 0)
         << QApplication::translate("Config", "Control.LUR.AttachDetach", 0)
         << QApplication::translate("Config", "Control.LUR.FailedRegistration.Message", 0)
         << QApplication::translate("Config", "Control.LUR.FailedRegistration.ShortCode", 0)
         << QApplication::translate("Config", "Control.LUR.NormalRegistration.Message", 0)
         << QApplication::translate("Config", "Control.LUR.NormalRegistration.ShortCode", 0)
         << QApplication::translate("Config", "Control.LUR.OpenRegistration.Message", 0)
         << QApplication::translate("Config", "Control.LUR.OpenRegistration.ShortCode", 0)
         << QApplication::translate("Config", "Control.LUR.QueryClassmark", 0)
         << QApplication::translate("Config", "Control.LUR.QueryIMEI", 0)
         << QApplication::translate("Config", "Control.LUR.QueryRRLP", 0)
         << QApplication::translate("Config", "Control.LUR.SendTMSIs", 0)
         << QApplication::translate("Config", "Control.LUR.UnprovisionedRejectCause", 0)
         << QApplication::translate("Config", "Control.NumSQLTries", 0)
         << QApplication::translate("Config", "Control.SMS.QueryRRLP", 0)
         << QApplication::translate("Config", "Control.TMSITable.MaxAge", 0)
         << QApplication::translate("Config", "Control.TMSITable.MaxSize", 0)
         << QApplication::translate("Config", "Control.VEA", 0)
         << QApplication::translate("Config", "GSM.CCCH.AGCH.QMax", 0)
         << QApplication::translate("Config", "GSM.CCCH.CCCH-CONF", 0)
         << QApplication::translate("Config", "GSM.Channels.SDCCHReserve", 0)
         << QApplication::translate("Config", "GSM.CellSelection.CELL-RESELECT-HYSTERESIS", 0)
         << QApplication::translate("Config", "GSM.CellSelection.MS-TXPWR-MAX-CCH", 0)
         << QApplication::translate("Config", "GSM.CellSelection.NCCsPermitted", 0)
         << QApplication::translate("Config", "GSM.CellSelection.NECI", 0)
         << QApplication::translate("Config", "GSM.CellSelection.Neighbors", 0)
         << QApplication::translate("Config", "GSM.CellSelection.RXLEV-ACCESS-MIN", 0)
         << QApplication::translate("Config", "GSM.Channels.C1sFirst", 0)
         << QApplication::translate("Config", "GSM.Channels.NumC1s", 0)
         << QApplication::translate("Config", "GSM.Channels.NumC7s", 0)
         << QApplication::translate("Config", "GSM.Control.GPRSMaxIgnore", 0)
         << QApplication::translate("Config", "GSM.Identity.BSIC.BCC", 0)
         << QApplication::translate("Config", "GSM.Identity.BSIC.NCC", 0)
         << QApplication::translate("Config", "GSM.Identity.ShortName", 0)
         << QApplication::translate("Config", "GSM.Identity.ShowCountry", 0)
         << QApplication::translate("Config", "GSM.MS.Power.Damping", 0)
         << QApplication::translate("Config", "GSM.MS.Power.Max", 0)
         << QApplication::translate("Config", "GSM.MS.Power.Min", 0)
         << QApplication::translate("Config", "GSM.MS.TA.Damping", 0)
         << QApplication::translate("Config", "GSM.MS.TA.Max", 0)
         << QApplication::translate("Config", "GSM.MaxSpeechLatency", 0)
         << QApplication::translate("Config", "GSM.RACH.AC", 0)
         << QApplication::translate("Config", "GSM.RACH.MaxRetrans", 0)
         << QApplication::translate("Config", "GSM.RACH.TxInteger", 0)
         << QApplication::translate("Config", "GSM.Radio.ARFCNs", 0)
         << QApplication::translate("Config", "GSM.RADIO-LINK-TIMEOUT", 0)
         << QApplication::translate("Config", "GSM.RRLP.ACCURACY", 0)
         << QApplication::translate("Config", "GSM.RRLP.ALMANAC.REFRESH.TIME", 0)
         << QApplication::translate("Config", "GSM.RRLP.ALMANAC.URL", 0)
         << QApplication::translate("Config", "GSM.RRLP.EPHEMERIS.REFRESH.TIME", 0)
         << QApplication::translate("Config", "GSM.RRLP.EPHEMERIS.URL", 0)
         << QApplication::translate("Config", "GSM.RRLP.RESPONSETIME", 0)
         << QApplication::translate("Config", "GSM.RRLP.SEED.ALTITUDE", 0)
         << QApplication::translate("Config", "GSM.RRLP.SEED.LATITUDE", 0)
         << QApplication::translate("Config", "GSM.RRLP.SEED.LONGITUDE", 0)
         << QApplication::translate("Config", "GSM.RRLP.SERVER.URL", 0)
         << QApplication::translate("Config", "GSM.RRLP.ALMANAC.ASSIST.PRESENT", 0)
         << QApplication::translate("Config", "GSM.RRLP.EPHEMERIS.ASSIST.COUNT", 0)
         << QApplication::translate("Config", "GSM.Radio.Band", 0)
         << QApplication::translate("Config", "GSM.Radio.C0", 0)
         << QApplication::translate("Config", "GSM.Radio.MaxExpectedDelaySpread", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.MaxAttenDB", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.MinAttenDB", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.NumSamples", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.Period", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.SamplePeriod", 0)
         << QApplication::translate("Config", "GSM.Radio.PowerManager.TargetT3122", 0)
         << QApplication::translate("Config", "GSM.Radio.RSSITarget", 0)
         << QApplication::translate("Config", "GSM.Radio.NeedBSIC", 0)
         << QApplication::translate("Config", "GSM.Timer.T3113", 0)
         << QApplication::translate("Config", "GSM.Timer.T3122Max", 0)
         << QApplication::translate("Config", "GSM.Timer.T3122Min", 0)
         << QApplication::translate("Config", "GSM.Timer.T3212", 0)
         << QApplication::translate("Config", "Log.Alarms.Max", 0)
         << QApplication::translate("Config", "Log.Level.CallControl.cpp", 0)
         << QApplication::translate("Config", "Log.Level.MobilityManagement.cpp", 0)
         << QApplication::translate("Config", "Log.Level.RadioResource.cpp", 0)
         << QApplication::translate("Config", "Log.Level.SMSControl.cpp", 0)
         << QApplication::translate("Config", "NTP.Server", 0)
         << QApplication::translate("Config", "RTP.Range", 0)
         << QApplication::translate("Config", "RTP.Start", 0)
         << QApplication::translate("Config", "SIP.RFC3428.NoTrying", 0)
         << QApplication::translate("Config", "SIP.DTMF.RFC2833", 0)
         << QApplication::translate("Config", "SIP.DTMF.RFC2833.PayloadType", 0)
         << QApplication::translate("Config", "SIP.DTMF.RFC2967", 0)
         << QApplication::translate("Config", "SIP.Local.IP", 0)
         << QApplication::translate("Config", "SIP.Local.Port", 0)
         << QApplication::translate("Config", "SIP.MaxForwards", 0)
         << QApplication::translate("Config", "SIP.Proxy.Registration", 0)
         << QApplication::translate("Config", "SIP.Proxy.SMS", 0)
         << QApplication::translate("Config", "SIP.Proxy.Speech", 0)
         << QApplication::translate("Config", "SIP.RegistrationPeriod", 0)
         << QApplication::translate("Config", "SIP.SMSC", 0)
         << QApplication::translate("Config", "SIP.Timer.A", 0)
         << QApplication::translate("Config", "SIP.Timer.B", 0)
         << QApplication::translate("Config", "SIP.Timer.E", 0)
         << QApplication::translate("Config", "SIP.Timer.F", 0)
         << QApplication::translate("Config", "SIP.Timer.J", 0)
         << QApplication::translate("Config", "SIP.Timer.H", 0)
         << QApplication::translate("Config", "SIP.Timer.I", 0)
         << QApplication::translate("Config", "SMS.DefaultDestSMSC", 0)
         << QApplication::translate("Config", "SMS.FakeSrcSMSC", 0)
         << QApplication::translate("Config", "SMS.MIMEType", 0)
         << QApplication::translate("Config", "SubscriberRegistry.Manager.Title", 0)
         << QApplication::translate("Config", "SubscriberRegistry.Manager.Url", 0)
         << QApplication::translate("Config", "SubscriberRegistry.Manager.VisibleColumns", 0)
         << QApplication::translate("Config", "SubscriberRegistry.db", 0)
         << QApplication::translate("Config", "SubscriberRegistry.Port", 0)
         << QApplication::translate("Config", "TRX.IP", 0)
         << QApplication::translate("Config", "TRX.Port", 0)
         << QApplication::translate("Config", "TRX.RadioFrequencyOffset", 0)
         << QApplication::translate("Config", "TRX.Timeout.Clock", 0)
         << QApplication::translate("Config", "TRX.Timeout.Start", 0)
         << QApplication::translate("Config", "TRX.TxAttenOffset", 0)
         << QApplication::translate("Config", "Test.SIP.SimulatedPacketLoss", 0)
         << QApplication::translate("Config", "Control.LUR.OpenRegistration", 0)
         << QApplication::translate("Config", "GSM.Radio.RXGain", 0)
         << QApplication::translate("Config", "GSM.Radio.RxGain", 0)
         << QApplication::translate("Config", "GSM.Identity.MCC", 0)
         << QApplication::translate("Config", "GSM.Identity.MNC", 0)
         << QApplication::translate("Config", "GSM.Identity.LAC", 0)
         << QApplication::translate("Config", "GSM.Identity.CI", 0)
         << QApplication::translate("Config", "Log.Level", 0)
        );
        checkBox->setText(QApplication::translate("Config", "Enable", 0));
        label->setText(QApplication::translate("Config", "Old Value:", 0));
        label_2->setText(QApplication::translate("Config", "New Value:", 0));
        label_3->setText(QApplication::translate("Config", "Configs", 0));
        pushButton->setText(QApplication::translate("Config", "Save", 0));
        pushButton_2->setText(QApplication::translate("Config", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
