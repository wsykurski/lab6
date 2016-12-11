cmake_minimum_required(VERSION 3.6)
project(lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp zad25.h zad25.cpp zad26.h zad26.cpp)
add_executable(lab6 ${SOURCE_FILES})