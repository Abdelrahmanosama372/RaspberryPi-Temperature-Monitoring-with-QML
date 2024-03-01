#include <chrono>
#include <fstream>
#include <stdexcept>
#include <thread>
#include <iostream>

#define LED_PATH            "/sys/class/leds/test/brightness"
#define SENSOR_TEMP_PATH    "/sys/bus/iio/devices/iio:device0/in_temp_input"
#define SENSOR_HUMID_PATH   "/sys/bus/iio/devices/iio:device0/in_humidityrelative_input"


      
namespace msys {
    class MonitoringSystem {
        private:
            int temperature;
            int humidity;
            std::thread blinkThr;

            MonitoringSystem();
        public:
            static MonitoringSystem& get_MonitoringSystem();
            void readSensorData();
            void blinkLed();
            void saveSensorData();

            void printdata(){
                std::cout << temperature << " " << humidity << std::endl;
            }

            ~MonitoringSystem();
    };
}