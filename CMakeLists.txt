cmake_minimum_required(VERSION 3.12)
project(pa1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cs221util)
include_directories(cs221util/lodepng)

add_executable(pa1
        cs221util/lodepng/lodepng.cpp
        cs221util/lodepng/lodepng.h
        cs221util/HSLAPixel.cpp
        cs221util/HSLAPixel.h
        cs221util/PNG.cpp
        cs221util/PNG.h
        cs221util/RGB_HSL.h
        block.cpp
        block.h
        chain.cpp
        chain.h
        main.cpp)
