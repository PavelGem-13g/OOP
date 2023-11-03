cmake_minimum_required(VERSION 3.23)
project(rita_lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(rita_lab
        main.cpp
        car.h car.cpp)
