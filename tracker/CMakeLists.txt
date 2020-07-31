cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(tracker)

set (CMAKE_CXX_STANDARD 14)

set(TRACKER_LIB tracker.cpp 
                object.cpp
				map.cpp
				simpletracker/simpletracker.cpp
				)
add_library(${PROJECT_NAME} STATIC ${TRACKER_LIB})

