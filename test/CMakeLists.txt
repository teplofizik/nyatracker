cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(test_all)

set (CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)
add_executable(${PROJECT_NAME} main.cpp argparser.cpp trackerdata.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tracker ${OpenCV_LIBS})
