/*
    SandboxCLangTest.cpp

    This file contains tests on GRE Vocabulary game that uses google test framework.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <gtest/gtest.h>
#include "Tutorial.h"
#include "Multithread.h"
#include "tcp_server.h"
#include "Object.h"
#include "STLArray.h"
#include "STLTest.h"
#include "CircuitList.h"
#include "ForwardList.h"
#include "List.h"
#include "Matrix.h"
#include "Queue.h"
#include "Sequence.h"
#include "Stack.h"
TEST(TUTORIAL_TEST/*test case name*/, TUTORIAL_TEST_1/*test name*/)
{
    EXPECT_EQ(0, listFiles());
    EXPECT_EQ(0, fileTest());
    EXPECT_EQ(0, preprocessingTest());
    EXPECT_EQ(0, dataTypeSizeTest());
    EXPECT_EQ(0, localTimeCheck());
    EXPECT_EQ(0, pointersTest());
    EXPECT_EQ(0,characterSetTest());
    EXPECT_EQ(5,argumentsTest(0,5));
    EXPECT_EQ(0, sandbox());
}

TEST(OOC_TEST/*test case name*/, OOC_TEST_1/*test name*/)
{
    EXPECT_EQ(0, test_Animals_Class());
    EXPECT_EQ(0, exception_Test());
}

TEST(CSTL_TEST/*test case name*/, CSTL_TEST_1/*test name*/)
{
    EXPECT_EQ(0, SGLIB_Data_Structures_Test());
    EXPECT_EQ(0, stl_dynamic_array());
    EXPECT_EQ(0, stl_strings_array());
    EXPECT_EQ(0, stl_int_array());
}

TEST(DATASTRUCT_TEST/*test case name*/, DATASTRUCT_TEST_1/*test name*/)
{
    EXPECT_EQ(0, forwardListTest());
    EXPECT_EQ(0, listTest());
    EXPECT_EQ(0, circuitListTest());
    EXPECT_EQ(0, arrayTest());
    EXPECT_EQ(0, matrixTest());
    EXPECT_EQ(0, queueTest());
    EXPECT_EQ(0, sequenceTest());
    EXPECT_EQ(0, stackTest());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
TEST(MULTITHREADING_TEST, MULTITHREADING_TEST_1)
{
EXPECT_EQ(0, Multithreaded_Tutorial_Functions_Test());
EXPECT_EQ(0, Multithreaded_Data_Structures_Test());
}
*/

/*
TEST(INTERNET_TEST, INTERNET_TEST_1)
{
    EXPECT_EQ(0, serverTest());
    EXPECT_EQ(0, clientTest());
}
*/