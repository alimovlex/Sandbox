//
// Created by alimovlex.
//
#include <gtest/gtest.h>
#include "Tutorial.h"
//Test of starting myStartupFun function before main
void myStartupFun (void) __attribute__ ((constructor));
/* Apply the destructor attribute to myCleanupFun() so that it is executed after main() */
void myCleanupFun (void) __attribute__ ((destructor));
/* implementation of myStartupFun */
void myStartupFun (void) //make it multithreaded
{
    printf ("startup testing function before main()\n");
    //SGLIB_Data_Structures_Test();
    //Multithreaded_Tutorial_Functions_Test();
    //Test_Animals_Class();
    //Exception_Test();
}
/* implementation of myCleanupFun */
void myCleanupFun (void)
{
    printf ("\ncleanup code after main()\n");
}

TEST(SANDBOX_TEST/*test case name*/, SANDBOX_TEST_1/*test name*/)
{
  EXPECT_EQ(0, sandbox());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
