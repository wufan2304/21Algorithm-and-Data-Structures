cmake_minimum_required(VERSION 3.6)
project(test01)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        student.h SortTestHelper.h)

add_executable(test01 ${SOURCE_FILES})