cmake_minimum_required(VERSION 3.14)
project(lab4)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    lab4
    lab4.cpp
    deposit.cpp
    casual.cpp
    app.cpp
)
enable_testing()

add_executable(
  tests
  tests.cpp
  deposit.cpp
  app.cpp
  casual.cpp
)
target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
target_link_libraries(lab4 -lfmt)
target_link_libraries(tests -lfmt)



