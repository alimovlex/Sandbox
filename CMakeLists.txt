cmake_minimum_required(VERSION 3.14)
project(Sandbox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
include_directories(source/inc)

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
        main.c)
