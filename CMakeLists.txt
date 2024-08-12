cmake_minimum_required(VERSION 3.28)
project(WorkerManagerSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(WorkerManagerSystem main.cpp
        WorkerClass.h
        context.cpp
        WorkerClass.cpp
        Functions.cpp
        Functions.h
        Context.h)
