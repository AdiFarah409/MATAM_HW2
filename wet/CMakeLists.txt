cmake_minimum_required(VERSION 3.28)
project(wet)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wet
        MataMvidia.cpp
        MataMvidia.h
        Matrix.cpp
        Matrix.h
        tests.cpp
        Utilities.cpp
        Utilities.h)
