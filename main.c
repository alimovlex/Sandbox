/*
    main.c
    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include <unistd.h>
#include <Block.h> //lambda functions Apple extension
#include "Object.h"
#include "Tutorial.h"
#include "List.h"
#include "Circuit_List.h"
#include "DuoList.h"
#include "Matrix.h"
#include "Stack.h"
#include "Queue.h"
#include "Dynamic_Queue.h"
#include "Inet.h"
#include "Multithread.h"
#include "Data_Test.h"
#include "t_clib.h"
#include "c_lib.h"
//Test of starting myStartupFun function before main
void myStartupFun (void) __attribute__ ((constructor));
/* Apply the destructor attribute to myCleanupFun() so that it is executed after main() */
void myCleanupFun (void) __attribute__ ((destructor));
/* implementation of myStartupFun */
void myStartupFun (void) //make it multithreaded
{
    printf ("startup testing function before main()\n");
    massiv(3);
    matrix(3, 3);
    queue(6);
    massiv(4);
    SGLIB_Data_Structures_Test();
}
/* implementation of myCleanupFun */
void myCleanupFun (void)
{
    printf ("\ncleanup code after main()\n");
}


int main(int argc, char *argv[])
{
    //Multithreaded_Data_Structures_Test();
    void(*func)()=Multithreaded_Tutorial_Functions_Test;
    func();
    //stl_int_array();
    //stl_dynamic_array();
    //stl_strings_array();
    return 0;
}
//-----
//switch((int)(n1 > n2))  
//case 1 ... 5:
//while(1)
//void(*functions[])() = {listFiles, file, preprocessor, memory, zeit, vremya, ptr_test, test, func_ptr};
/*

*/