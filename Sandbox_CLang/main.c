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
#include "ForwardList.h"
#include "CircuitList.h"
#include "List.h"
#include "Matrix.h"
#include "Stack.h"
#include "Sequence.h"
#include "Queue.h"
#include "tcp_server.h"
#include "tcp_client.h"
#include "bluetooth-test.h"
#include "Multithread.h"
#include "STLTest.h"
#include "t_clib.h"
#include "c_lib.h"
#include "STLArray.h"


int main(int argc, char *argv[])
{   /*
    int(*func)() = Multithreaded_Data_Structures_Test;
    timerFunction(func);
    func = Multithreaded_Tutorial_Functions_Test;
    timerFunction(func);
    */
    //system("systemctl status bluetooth | grep -oh \"active\"");
    list_bluetooth_devices();
    //STL_Test();
    return 0;
}
//switch((int)(n1 > n2))  
//case 1 ... 5:

/*
 //Test of starting myStartupFun function before main
void myStartupFun (void) __attribute__ ((constructor));
void myCleanupFun (void) __attribute__ ((destructor));
void myStartupFun (void) //make it multithreaded
{
    printf ("startup testing function before main()\n");
    timerFunction(SGLIB_Data_Structures_Test);
    //clientTest();
}
void myCleanupFun (void)
{
    printf ("\ncleanup code after main()\n");
}
 */