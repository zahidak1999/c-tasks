cmake_minimum_required(VERSION 3.5)

project(oop-task)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(solution3 commodity.cpp testklient.cpp commodity.hpp)
add_executable(solution3.1 circle.cpp circle.hpp)
add_executable(solution3.4 oppgave4.cpp)
