cmake_minimum_required(VERSION 3.20)
project(program13)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(program13
        list.h
        listnode.cpp
        listnode.h
        main.cpp
        main.h
        node.cpp
        node.h linearsearch.cpp linearsearch.h)
