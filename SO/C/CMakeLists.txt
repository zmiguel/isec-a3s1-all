cmake_minimum_required(VERSION 3.6)
project(SO_Aulas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(SO_Aulas ${SOURCE_FILES})