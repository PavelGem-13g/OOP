cmake_minimum_required(VERSION 3.23)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Project.cpp Project.h Task.cpp Task.h Actor.cpp Actor.h Subtask.cpp Subtask.h TaskType.cpp TaskType.h TaskProgressType.cpp TaskProgressType.h ComplexTask.cpp ComplexTask.h)
