cmake_minimum_required(VERSION 3.13)
project(Runner)

set(CMAKE_CXX_STANDARD 14)

add_executable(Runner main.cpp Run/Point.cpp Run/Point.h Run/Surfaces/Planar.h Search.h Run/Surfaces/Tor.h Run/Surfaces/Cylinder.h Surface.h Run/Surface_Points.cpp Run/Surface_Points.h Read/Surface_Words.cpp Read/Surface_Words.h)
add_executable(unittest test.cpp Run/Point.cpp Run/Point.h Run/Surfaces/Planar.h Search.h Run/Surfaces/Tor.h Run/Surfaces/Cylinder.h Surface.h Run/Surface_Points.cpp Run/Surface_Points.h Read/Surface_Words.cpp Read/Surface_Words.h)
