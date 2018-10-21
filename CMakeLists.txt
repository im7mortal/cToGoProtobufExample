cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_library(untitled library.cpp library.h params.pb.cc params.pb.h)