cmake_minimum_required(VERSION 3.17)
project(lab2Eu)

set(CMAKE_CXX_STANDARD 14)

include_directories(MultiMap)

add_executable(lab2Eu
        MultiMap/App.cpp
        MultiMap/ExtendedTest.cpp
        MultiMap/ExtendedTest.h
        MultiMap/MultiMap.cpp
        MultiMap/MultiMap.h
        MultiMap/MultiMapIterator.cpp
        MultiMap/MultiMapIterator.h
        MultiMap/ShortTest.cpp
        MultiMap/ShortTest.h)
