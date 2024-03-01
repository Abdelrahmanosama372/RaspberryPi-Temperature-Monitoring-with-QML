#ifndef MONITORSYSTEMDISPLAY_H
#define MONITORSYSTEMDISPLAY_H


#include <iostream>
#include <QObject>
#include <QFile>
#include <QTimer>
#include <QTextStream>

class MonitorSystemDisplay : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentTemp READ getTemperatureStr NOTIFY CurrentTempChanged)
    Q_PROPERTY(QString currentHumid READ getHumidityStr NOTIFY CurrentHumidChanged)
public:
    explicit MonitorSystemDisplay(QObject *parent = nullptr);

private:
    void processData(QVector<QString> &values);
    void setTemperature(qint32 temp);
    void setHumidity(qint32 humid);
    QString getTemperatureStr();
    QString getHumidityStr();

signals:
    void CurrentTempChanged();
    void CurrentHumidChanged();

private slots:
    void readSensorData();

private:
    qint32 Temperature;
    qint32 Humidity;
};

#endif // MONITORSYSTEMDISPLAY_H
