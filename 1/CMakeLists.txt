cmake_minimum_required(VERSION 3.5.1)
project(lab1 VERSION 1.0 LANGUAGES CXX)
#set(NAME_L lab1)
set(CMAKE_CXX_STANDARD 11)
#s#et(HEADERS ./*.hpp)

#add_library(matrix STATIC $(SOURCE_LIB))
#file(GLOB SOURCES ./*.cpp)

add_executable(lab1 lab1.cpp matrix.cpp)