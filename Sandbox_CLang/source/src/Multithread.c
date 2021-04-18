/*
    Multithread.c
    The module represents my demo functions in parallel multithreaded programming method.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
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
#include "STLArray.h"
#include "STLTest.h"
#include "t_clib.h"

//WORK ON THREADS IS IN PROGRESS
int Multithreaded_Tutorial_Functions_Test()
{
    pthread_t t0, t1, t2, t3, t4, t5, t6, t7;
    if(pthread_create(&t0,NULL,listFiles,NULL)==-1)
        perror("Unable to create a thread for ListFiles function\n");
    else if(pthread_create(&t1,NULL,fileTest,NULL)==-1)
        perror("Unable to create a thread for FileTest function\n");
    else if(pthread_create(&t2,NULL,preprocessingTest,NULL)==-1)
        perror("Unable to create a thread for Preprocessing function\n");
    else if(pthread_create(&t3,NULL,dataTypeSizeTest,NULL)==-1)
        perror("Unable to create a thread for DataTypeSizeTest function\n");
    else if(pthread_create(&t4,NULL,localTimeCheck,NULL)==-1)
        perror("Unable to create a thread for localTimeCheck function\n");
    else if(pthread_create(&t5,NULL,sandbox,NULL)==-1)
        perror("Unable to create a thread for Sandbox function\n");
    else if(pthread_create(&t6,NULL,characterSetTest,NULL)==-1)
        perror("Unable to create a thread for CharacterSetTest function\n");
    else if(pthread_create(&t7,NULL,pointersTest,NULL)==-1)
        perror("Unable to create a thread for PointerTest function\n");
    else
        printf("Error creating threads for Tutorial functions.");

    void *result;
    if(pthread_join(t0,&result)==-1) {
        perror("Can't join thread listFiles\n");
        return -1;
    }
    else
    return 0;
    //pthread_exit(NULL);
}

int Multithreaded_Data_Structures_Test()
{
    pthread_t t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    if(pthread_create(&t0,NULL,circuitListTest,NULL)==-1)
        perror("Unable to create a thread for circuitListTest function\n");
    else if(pthread_create(&t1,NULL,forwardListTest,NULL)==-1)
        perror("Unable to create a thread for forwardListTest function\n");
    else if(pthread_create(&t2,NULL,listTest,NULL)==-1)
        perror("Unable to create a thread for listTest function\n");
    else if(pthread_create(&t3,NULL,stackTest,NULL)==-1)
        perror("Unable to create a thread for stackTest function\n");
    else if(pthread_create(&t4,NULL,sequenceTest,NULL)==-1)
        perror("Unable to create a thread for sequenceTest function\n");
    else if(pthread_create(&t5,NULL,queueTest,NULL)==-1)
        perror("Unable to create a thread for queueTest function\n");
    else if(pthread_create(&t6,NULL,arrayTest,NULL)==-1)
        perror("Unable to create a thread for arrayTest function\n");
    else if(pthread_create(&t7,NULL,matrixTest,NULL)==-1)
        perror("Unable to create a thread for matrixTest function\n");
    else if(pthread_create(&t8,NULL,stl_strings_array,NULL)==-1)
        perror("Unable to create a thread for stl_strings_array function\n");
    else if(pthread_create(&t9,NULL,stl_dynamic_array,NULL)==-1)
        perror("Unable to create a thread for stl_dynamic_array function\n");
    else if(pthread_create(&t10,NULL,stl_int_array,NULL)==-1)
        perror("Unable to create a thread for stl_int_array function\n");
    else
        printf("Error creating threads for Data Structures Test.");

    void *result;
    if(pthread_join(t0,&result)==-1) {
        perror("Can't join thread circuitListTest\n");
        return -1;
    }
    else
        return 0;
}