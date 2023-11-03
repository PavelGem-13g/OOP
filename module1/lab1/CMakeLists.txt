cmake_minimum_required(VERSION 3.23)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        lab1
        main.cpp
        Vector3.cpp Vector3.h
        Cabinet.cpp Cabinet.h
        Appliance.cpp Appliance.h
        Entity.cpp Entity.h EntityType.cpp EntityType.h Plan.cpp Plan.h)
