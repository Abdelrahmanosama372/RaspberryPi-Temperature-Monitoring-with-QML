#include "../inc/monitoring_system.hpp"
#include <fstream>

msys::MonitoringSystem::MonitoringSystem() = default;

msys::MonitoringSystem& msys::MonitoringSystem::get_MonitoringSystem(){
        static MonitoringSystem monitorSys;
        return monitorSys;
}

void msys::MonitoringSystem::readSensorData(){
    // read temperature
    std::ifstream ifst;
    ifst.open(SENSOR_TEMP_PATH);
    if (!ifst.is_open())
        throw std::runtime_error("Error reading temperature value");
    ifst >> temperature;
    ifst.close();

    temperature /= 1000; //convert to deg

        // read humidity
    ifst.open(SENSOR_HUMID_PATH);
    if (!ifst.is_open())
        throw std::runtime_error("Error reading humidity value");
    ifst >> humidity;
    ifst.close();

    humidity /= 1000;
}

void msys::MonitoringSystem::blinkLed(){
    if(blinkThr.joinable())
        blinkThr.join();
    blinkThr = std::thread([](){
        std::ofstream ofst;
        ofst.open(LED_PATH);
        if (!ofst.is_open())
            throw std::runtime_error("Error in blinking the led");
        ofst << 1 << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ofst << 0 << std::endl;
        ofst.close();
    });
}
 
void msys::MonitoringSystem::saveSensorData(){
    std::ofstream ofst;
    ofst.open("sensorData.csv",std::ios::app);
    if (!ofst.is_open())
        throw std::runtime_error("Error saving data");
    ofst << temperature << ',' << humidity << std::endl;
    ofst.close();
}

msys::MonitoringSystem::~MonitoringSystem(){
    if(blinkThr.joinable())
        blinkThr.join();
}