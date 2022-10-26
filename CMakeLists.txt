cmake_minimum_required(VERSION 2.8.12)

project(GuZhi LANGUAGES CXX)

# 添加Eigen头文件
include_directories("C:/Users/dell/Desktop/eigen-3.4.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" "TransObj.h" "TransObj.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
