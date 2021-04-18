
cmake_minimum_required(VERSION 3.13)  # Automatically generated syntax

# project(Sandbox) --> When CLion project is created, it is automatically created if it is created as c project,
# Because of this, the C++ gtest is not built.
# Therefore, remove c as below.
project(Sandbox)

set(CMAKE_C_STANDARD 11) # Automatic generation syntax when creating a C project
file(GLOB SANDBOX "source/inc/*.h" "source/src/*.c")
file(GLOB OOC "ooc/inc/*.h" "ooc/src/*.c")
file(GLOB DATASTRUCT "Data_Struct/inc/*.h" "Data_Struct/src/*.c")
file(GLOB CSTL "cstl/inc/*.h" "cstl/src/*.c" "cstl/test/*.c")
file(GLOB CSPTR "csptr/inc/*.h" "csptr/src/*.c")
# Build my library to support the Sandbox function (C code)
add_library(libSandbox SHARED ${SANDBOX})
add_library(libOOC SHARED ${OOC})
add_library(libDataStruct SHARED ${DATASTRUCT})
add_library(libCSTL SHARED ${CSTL})
add_library(libCSPTR SHARED ${CSPTR})

# Build an executable program using the plus library (C code)
# It is not used when performing only tests, so there is no need to build.
include_directories(source/inc)
include_directories(Data_Struct/inc)
include_directories(ooc/inc)
include_directories(cstl/inc)
include_directories(csptr/inc)
add_executable(Sandbox main.c)
target_link_libraries(Sandbox libSandbox libOOC libDataStruct libCSTL libCSPTR pthread)

# build gtest (C++ code)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
enable_testing()


# Build test program (C++ code)
#include_directories(source/inc)
#include_directories(Data_Struct/inc)
#include_directories(ooc/inc)
#include_directories(cstl/inc)
#include_directories(csptr/inc)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})
add_executable(SandboxTests test/SandboxTest.cpp)
target_link_libraries(SandboxTests gtest gtest_main libSandbox libOOC libDataStruct libCSTL libCSPTR pthread)

# Not used (written for testing in the middle stage)
##set(CMAKE_CXX_STANDARD 11)
##set(CMAKE_C_COMPILER g++)
##set(CMAKE_CXX_LINK_EXECUTABLE cxx)
#add_subdirectory(googletest-release-1.8.1)
#set(gtest_SRC_DIR googletest-release-1.8.1)
#include_directories(${gtest_SRC_DIR}/googletest/include ${gtest_SRC_DIR}/googletest)
#add_executable(runSumTests main.cc sum_test.cc)
##set_target_properties(runSumTests PROPERTIES LINKER_LANGUAGE CXX)
#target_link_libraries(runSumTests gtest gtest_main)
#target_link_libraries(runSumTests libsum)