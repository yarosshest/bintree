cmake_minimum_required(VERSION 3.19)
project(tree)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Tests)
add_executable(tree main.cpp tree_el.cpp tree_el.h binary_tree.cpp binary_tree.h )