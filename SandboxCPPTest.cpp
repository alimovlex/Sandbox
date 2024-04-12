/*
    SandboxCPPTest.cpp

    This file contains tests on GRE Vocabulary game that uses google test framework.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <gtest/gtest.h>
#include "GRE.hpp"
#include "TOEFL.hpp"
#include "Tutorial.hpp"
#include "STLTest.hpp"
#include "Algorithms.hpp"
#include "IP_Address_Info.hpp"
#include "STLTest.hpp"
#include "Object.hpp"
#include "DataStruct.hpp"

TEST(JSON_Test, JSON_JS_Test)
{
    ASSERT_EQ(0, ip_address_info());
}

TEST(STL_Test, STL_Containers_Test)
{
    ASSERT_EQ(0, containersTest());
}
TEST(Algorithms_Test, Algorithms_General_Test)
{
    ASSERT_EQ(0, algorithmsTest());
}

TEST(TUTORIAL_TEST, TUTORIAL_TEST_1)
{
    ASSERT_EQ(0, fileTest());
    ASSERT_EQ(0, testingPointers());
    ASSERT_EQ(5, argumentsTest(0,5));
    ASSERT_EQ(0,localTimeCheck());
    ASSERT_EQ(0,dataTypeSizeTest());
    ASSERT_EQ(0,preprocessingTest());
}

TEST(OBJECT_TEST, OBJECT_TEST_1)
{
    ASSERT_EQ(0,polymorphismTest());
    ASSERT_EQ(0,templateClassTest());
    ASSERT_EQ(0,templateFunctionTest());
}
TEST(DATASTRUCT_TEST, DATASTRUCT_TEST_1)
{
    ASSERT_EQ(0,STLCombinedArrayTest());
    ASSERT_EQ(0,matrixTest());
    ASSERT_EQ(0,summVectorTest());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
TEST(GRE_Game_Test, GRE_Game_Exit_Status) {
    ASSERT_EQ(51, gre_vocabulary());
}

TEST(TOEFL_Game_Test, TOEFL_Game_Exit_Status) {
    ASSERT_EQ(52, toefl_vocabulary());
}
*/