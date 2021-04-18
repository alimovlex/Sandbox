//
// Created by alimovlex.
//
#include <gtest/gtest.h>
#include "Tutorial.h"
#include "Multithread.h"
#include "Inet.h"
#include "Object.h"
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

TEST(MULTITHREADING_TEST/*test case name*/, MULTITHREADING_TEST_1/*test name*/)
{
    EXPECT_EQ(0, Multithreaded_Tutorial_Functions_Test());
    EXPECT_EQ(0, Multithreaded_Data_Structures_Test());
}

TEST(INTERNET_TEST/*test case name*/, INTERNET_TEST_1/*test name*/)
{
    EXPECT_EQ(0, serverTest());
    EXPECT_EQ(0, clientTest());
}

TEST(OOC_TEST/*test case name*/, OOC_TEST_1/*test name*/)
{
    EXPECT_EQ(0, test_Animals_Class());
    EXPECT_EQ(0, exception_Test());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
