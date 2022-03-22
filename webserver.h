#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QDataStream>
#include <QSettings>
#include <QApplication>
#include <QMessageBox>
#include <QFile>

#include "rodcheck.h"

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class MainWindow : public QObject
{
    Q_OBJECT
public:
    explicit MainWindow(quint16 port, bool debug = false, QObject *parent = nullptr);
    ~MainWindow();



Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();

    void processTestTextMessage(QString message);
//    void processGetConfigBinaryMessage(QByteArray message);
    void socketDisconnected();

private slots:
    // Log
//    void writeMainLog(QString);

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    bool m_debug;


//    Presets_Struct *PresetMainWindow;
    Presets_Struct PresetMainWindow;

//    Rebar_Config_Struct *RebarConfigStruct;
    Rebar_Config_Struct RebarConfigStruct;


    void getConfig();
    /// Set in ini file
    /// For comment
    QString configVersion;

    QString csv_separation_char_str, csv_decimal_char_str;

    /// 0. ini - ATON_SETTING
    unsigned int AxisNum = 0;
    unsigned int MonitorSize = 19;
    int materialType = 0;
    int traffic_light_reset_time=0;
    QString config_language="ENGLISH";
    QString metric_or_imperial="metric";
    int productionTemp = 300;
    QString billet_or_coil="BILLET";
    int roundingDigit = 3;
    bool no_hdd = false;
    qreal maxDiameter;

    /// 1. ini - CALIB_SETTING
    qreal calib_small = 5;
    qreal calib_big = 10;

    /// 3. ini - OPTIONAL_SETTING
    int lv1update = 1;
//    External_signal* lv1_signal;
    int webUpdateRate = 1000;

    /// 4. ini - ERROR_LOG_SETTING
    QString warningDiff = "";
    bool BUILT_IN_PYROMETER;
    double airflowLimit;

    /// 6. ini - DISPLAY_SETTING
    int histClassNum = 100;
    double histRange = 0.05;
    qreal Uarea = 20.0;
    qreal Carea = 10.0;
    qreal Larea = 40.0;
    double polarMagnify = 1; // Deprecated
    bool show_diameter_average=false;
    bool show_temperature_value=false;
    bool billetTrendFlag = true;

    /// 7. ini - FILTER
    // Spike filter
    bool SpikeFilterSwitch = 0;
    int MovAvgWindowSize = 15;
    int SpikeMaxFilterCnt = 1;
    qreal SpikeFilTrgOnTh = 0.0;
    qreal SpikeFilTrgOffTh = 0.0;

    // Ovality filter
    bool OvalityFilterSwitch = false;
    bool ovality_filter_logged=false;
    qreal ovality_filter_threshold = 0.5;
    QString defect_axis="Y";

    // Minimum filter
    bool MinimumFilterSwitch2=false;
    int MinimumFilterWindowSize2=0;

    // Median filter
    int medianSize = 1;

    // AVG filter
    bool avgFilterSwitch = false;
    int avgFilterSize = 1;
    qreal avgFilterDeltaX = 0.0;
    qreal avgFilterDeltaY = 0.0;

    // Product diameter

    int sensorSequen[6] = {0};
};

#endif //WEBSERVER_H
