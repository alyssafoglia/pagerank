cmake_minimum_required(VERSION 3.17)
project(pagerank2)

set(CMAKE_CXX_STANDARD 11)

add_executable(pagerank2 main.cpp adjacencyList.cpp adjacencyList.h)