cmake_minimum_required(VERSION 3.14)
project(lab4)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)


add_executable(
    lab4
    lab4.cpp
    deposit.cpp
    casual.cpp
    app.cpp
)
target_link_libraries(lab4 -lfmt)
enable_testing()



