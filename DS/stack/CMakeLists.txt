cmake_minimum_required(VERSION 3.29)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack
    "implementation in cpp/stack_arrayBased.cpp"
    "implementation in cpp/stack_singleLinkedListBased.cpp")
