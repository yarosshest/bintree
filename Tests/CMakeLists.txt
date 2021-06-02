cmake_minimum_required(VERSION 3.19)
project(Tests)

add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(Tests binaryTreeTests.cpp)
target_link_libraries(Tests gtest gtest_main)