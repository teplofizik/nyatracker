cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set (CMAKE_CXX_STANDARD 11)
include_directories(/usr/local/include/opencv4)

include_directories(tracker)

add_subdirectory (tracker)
add_subdirectory (test)