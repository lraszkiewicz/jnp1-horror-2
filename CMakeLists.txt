cmake_minimum_required(VERSION 3.5.1)
project(horror_2)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        citizen.cc
        citizen.h
        helper.cc
        helper.h
        monster.cc
        monster.h
        smalltown.h
        smalltown.cc)

add_executable(horror_example ${SOURCE_FILES} horror_example.cc)
add_executable(attacking_test ${SOURCE_FILES} attacking_test.cc)
add_executable(citizen_test ${SOURCE_FILES} citizen_test.cc)
add_executable(groupofmonsters_test ${SOURCE_FILES} groupofmonsters_test.cc)