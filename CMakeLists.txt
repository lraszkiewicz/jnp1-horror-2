cmake_minimum_required(VERSION 3.6)
project(horror_2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        citizen.cc
        citizen.h
        helper.cc
        helper.h
        horror_example.cc
        monster.cc
        monster.h
        smalltown.h)

add_executable(horror_2 ${SOURCE_FILES})