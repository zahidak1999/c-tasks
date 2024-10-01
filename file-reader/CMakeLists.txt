cmake_minimum_required(VERSION 3.5)

project(file-reader)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(oving1a temperature.cpp)
add_executable(oving1b temperature_reader.cpp)
