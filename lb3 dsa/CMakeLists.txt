cmake_minimum_required(VERSION 3.16)
project(Iterated_Listrar)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Iterated_Listrar
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
