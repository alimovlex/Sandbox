cmake_minimum_required(VERSION 3.14)
project(Sandbox C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
include_directories(source/inc)
include_directories(Data_Struct/inc)
include_directories(ooc/inc)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(Sandbox
        main.c
        Data_Struct/inc/Array.h
        Data_Struct/inc/Circuit_List.h
        Data_Struct/inc/DuoList.h
        Data_Struct/inc/Dynamic_queue.h
        source/inc/Inet.h
        Data_Struct/inc/List.h
        source/inc/Multithread.h
        Data_Struct/inc/Queue.h
        Data_Struct/inc/Stack.h
        source/inc/Tutorial.h
        ooc/inc/OOBase.h
        ooc/inc/OOCfg.h
        ooc/inc/OOCore.h
        ooc/inc/OODbg.h
        ooc/inc/OOStd.h
        Data_Struct/src/Array.c
        Data_Struct/src/Circuit_List.c
        Data_Struct/src/DuoList.c
        Data_Struct/src/Dynamic_queue.c
        source/src/Inet.c
        Data_Struct/src/List.c
        source/src/Multithread.c
        Data_Struct/src/Queue.c
        Data_Struct/src/Stack.c
        Data_Struct/inc/sglib.h
        source/src/Tutorial.c
        ooc/src/OODbg.c
        source/src/Object.c
        source/inc/Object.h)
target_link_libraries(Sandbox ${GTEST_LIBRARIES} pthread)