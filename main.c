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
#include "Inet.h"
#include "Multithread.h"
#include "STLTest.h"
#include "t_clib.h"
#include "c_lib.h"


int main(int argc, char *argv[])
{
    void(*func)() = Multithreaded_Data_Structures_Test;
    func();
    //STL_Test();
    return 0;
}
//switch((int)(n1 > n2))  
//case 1 ... 5: