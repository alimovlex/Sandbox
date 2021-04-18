/*
    tests.cpp

    This file contains tests on GRE Vocabulary game that uses google test framework.

    Sandbox2

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <gtest/gtest.h>
#include "GRE.hpp"
#include "TOEFL.hpp"
#include "Tutorial.hpp"
#include "STLTest.hpp"
#include "Algorithms.hpp"
#include "Internet.hpp"
#include "STLTest.hpp"

TEST(JSON_Test, JSON_JS_Test) {
    ASSERT_EQ(0, jsonRequest());
}

TEST(STL_Test, STL_Containers_Test) {
    ASSERT_EQ(0, containersTest());
}
TEST(Algorithms_Test, Algorithms_General_Test) {
    ASSERT_EQ(0, algorithmsTest());
}
/*
TEST(GRE_Game_Test, GRE_Game_Exit_Status) {
    ASSERT_EQ(51, gre_vocabulary());
}

TEST(TOEFL_Game_Test, TOEFL_Game_Exit_Status) {
    ASSERT_EQ(52, toefl_vocabulary());
}
*/


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}