cmake_minimum_required(VERSION 3.28)
project(Single_Linked_List)

set(CMAKE_CXX_STANDARD 14)

include_directories(singleLinkedList_Easy_HW)
include_directories("singleLinkedList_Med_HW/Med in cpp")

add_executable(Single_Linked_List
        singleLinkedList_cpp/singleLinkedList.cpp
        singleLinkedList_Easy_HW/singleLinkedList.h
        singleLinkedList_Easy_HW/SLL_Easy.cpp
        "singleLinkedList_Med_HW/Med in cpp/singleLinkedList.h"
        "singleLinkedList_Med_HW/Med in cpp/SLL_Med.cpp")
