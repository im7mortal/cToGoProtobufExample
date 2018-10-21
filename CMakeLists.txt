cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_library(untitled src/library.cpp include/library.h src/params.pb.cc src/params.pb.h)