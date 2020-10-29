cmake_minimum_required(VERSION 3.17)
project(a3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a3
        DataSequence.cpp
        DataSequence.h
        FiveNumberSummary.cpp
        FiveNumberSummary.h
        Histogram.cpp
        Histogram.h
        main.cpp)
