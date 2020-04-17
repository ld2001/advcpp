cmake_minimum_required(VERSION 3.15)
project(advcpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(maze)

add_executable(advcpp
        maze/Makefile
        maze/maze
        maze/maze.cpp
        maze/maze.h
        maze/maze.pdf
        maze/path.h
        maze/solve.cpp
        maze/square.h)
