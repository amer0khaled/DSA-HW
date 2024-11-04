cmake_minimum_required(VERSION 3.29)
project(AVL)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AVL
        AVLTree.cpp
    AVLTree.h
        main.cpp)
