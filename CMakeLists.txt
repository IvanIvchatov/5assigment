cmake_minimum_required(VERSION 4.2)
project(untitled5)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled5 main.cpp
        splitter.h
        Splitter.cpp
        Piece.h
        Memory.h
        Node.h
        Treebuilder.h
        TreeBuilder.cpp)
