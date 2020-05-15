cmake_minimum_required(VERSION 3.14)
project(Sandbox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
include_directories(source/inc)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(Sandbox
        source/inc/Array.h
        source/inc/Circuit_List.h
        source/inc/DuoList.h
        source/inc/Dynamic_queue.h
        source/inc/Inet.h
        source/inc/List.h
        source/inc/Multithread.h
        source/inc/Queue.h
        source/inc/Stack.h
        source/inc/Tutorial.h
        source/inc/OOBase.h
        source/inc/OOCfg.h
        source/inc/OOCore.h
        source/inc/OODbg.h
        source/inc/OOStd.h
        source/src/Array.c
        source/src/Circuit_List.c
        source/src/DuoList.c
        source/src/Dynamic_queue.c
        source/src/Inet.c
        source/src/List.c
        source/src/Multithread.c
        source/src/Queue.c
        source/src/Stack.c
        source/src/Tutorial.c
        source/src/OODbg.c
        main.c source/src/Object.c source/inc/Object.h)
target_link_libraries(Sandbox ${GTEST_LIBRARIES} pthread)