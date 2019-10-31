cmake_minimum_required(VERSION 3.14)
project(UTPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(UTPod UTPod.cpp
                        UTPod.h
                        Song.cpp
                        Song.h
                        UTPod_Driver.cpp)