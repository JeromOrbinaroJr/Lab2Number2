cmake_minimum_required(VERSION 3.10)
project(Lab 2 Number 2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyExecutable Node.h Stack.h main.cpp Stack.cpp)
