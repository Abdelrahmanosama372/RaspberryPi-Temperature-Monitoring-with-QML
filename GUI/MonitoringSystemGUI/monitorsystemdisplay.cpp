#include "monitorsystemdisplay.h"

MonitorSystemDisplay::MonitorSystemDisplay(QObject *parent)
    : QObject{parent}, Temperature(0), Humidity(0)
{
    // Update the temperature and humidity every 6 seconds
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MonitorSystemDisplay::readSensorData);
    timer->start(6000);
    readSensorData(); // Initial read
}

void MonitorSystemDisplay::readSensorData(){
    QFile file("/home/abdelrahman/sensorData.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "cannot open the file" << std::endl;
        return;
    }else {
        std::cout << "file is opened" << std::endl;
    }

    QTextStream in(&file);
    QVector<QString> values;

    while(!in.atEnd()){
        values.push_back(in.readLine());
    }
    processData(values);

}

void MonitorSystemDisplay::processData(QVector<QString> &values){
    qint32 sumtemp = 0, sumhumid = 0;
    for(QString &value : values){
        QStringList splittedVals = value.split(',');
        sumtemp += splittedVals[0].toInt();
        sumhumid += splittedVals[1].toInt();
    }
    setTemperature(sumtemp/values.size());
    setHumidity(sumhumid/values.size());
    emit CurrentTempChanged();
    emit CurrentHumidChanged();
}

void MonitorSystemDisplay::setTemperature(qint32 temp){
    this->Temperature = temp;
}

void MonitorSystemDisplay::setHumidity(qint32 humid){
    this->Humidity = humid;
}

QString MonitorSystemDisplay::getTemperatureStr(){
    return QString::number(Temperature);
}

QString MonitorSystemDisplay::getHumidityStr(){
    return QString::number(Humidity);
}

#include "monitorsystemdisplay.moc"
