cmake_minimum_required(VERSION 3.14)
project(UTPod)

set(CMAKE_CXX_STANDARD 11)

add_executable(UTPod UtPod.cpp
        UtPod.h
                        Song.cpp
                        Song.h
        UtPodDriver.cpp)