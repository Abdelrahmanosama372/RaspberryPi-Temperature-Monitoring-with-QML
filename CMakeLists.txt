cmake_minimum_required(VERSION 3.16.3)

project("monitorsys")

set(SRC_FILES
    src/main.cpp 
    src/monitoring_system.cpp)

add_executable(${PROJECT_NAME} 
                ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC inc/)
target_compile_options(${PROJECT_NAME} PUBLIC -static)

SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm)




