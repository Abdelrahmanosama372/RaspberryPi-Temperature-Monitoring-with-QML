#include "../inc/monitoring_system.hpp"
#include <chrono>
#include <thread>

int main() {
    msys::MonitoringSystem& monitorSys = msys::MonitoringSystem::get_MonitoringSystem();
    while (true) {
        monitorSys.readSensorData();
        monitorSys.blinkLed();
        monitorSys.printdata();
        monitorSys.saveSensorData();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}
