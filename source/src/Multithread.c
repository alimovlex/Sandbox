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

//WORK ON THREADS IS IN PROGRESS
void Multithreaded_Tutorial_Functions_Test()
{
    pthread_t t0, t1, t2, t3, t4, t5, t6, t7;
    if(pthread_create(&t0,NULL,ListFiles,NULL)==-1)
        perror("Unable to create a thread for ListFiles function\n");
    else if(pthread_create(&t1,NULL,FileTest,NULL)==-1)
        perror("Unable to create a thread for FileTest function\n");
    else if(pthread_create(&t2,NULL,PreprocessingTest,NULL)==-1)
        perror("Unable to create a thread for Preprocessing function\n");
    else if(pthread_create(&t3,NULL,DataTypeSizeTest,NULL)==-1)
        perror("Unable to create a thread for DataTypeSizeTest function\n");
    else if(pthread_create(&t4,NULL,LocalTimeCheck,NULL)==-1)
        perror("Unable to create a thread for LocalTimeChech function\n");
    else if(pthread_create(&t5,NULL,TimerFunction,NULL)==-1)
        perror("Unable to create a thread for TimerFunction function\n");
    else if(pthread_create(&t6,NULL,CharacterSetTest,NULL)==-1)
        perror("Unable to create a thread for CharacterSetTest function\n");
    else if(pthread_create(&t7,NULL,PointersTest,NULL)==-1)
        perror("Unable to create a thread for PointerTest function\n");
    else
        printf("Error creating threads.");

    void *result;
    if(pthread_join(t0,&result)==-1)
        perror("Can't join thread t0\n");
    if(pthread_create(&t0,NULL,ListFiles,NULL)==-1)
        perror("Unable to create a thread for ListFiles function\n");
    else if(pthread_create(&t1,NULL,FileTest,NULL)==-1)
        perror("Unable to create a thread for FileTest function\n");
    else if(pthread_create(&t2,NULL,PreprocessingTest,NULL)==-1)
        perror("Unable to create a thread for Preprocessing function\n");
    else if(pthread_create(&t3,NULL,DataTypeSizeTest,NULL)==-1)
        perror("Unable to create a thread for DataTypeSizeTest function\n");
    else if(pthread_create(&t4,NULL,LocalTimeCheck,NULL)==-1)
        perror("Unable to create a thread for LocalTimeCheck function\n");
    else if(pthread_create(&t5,NULL,TimerFunction,NULL)==-1)
        perror("Unable to create a thread for TimerFunction function\n");
    else if(pthread_create(&t6,NULL,CharacterSetTest,NULL)==-1)
        perror("Unable to create a thread for CharacterSetTest function\n");
    else if(pthread_create(&t7,NULL,PointersTest,NULL)==-1)
        perror("Unable to create a thread for PointersTest function\n");
    else
        printf("Error creating threads.");
    pthread_exit(NULL);
}

void Multithreaded_Data_Structures_Test()
{
    pthread_t t0, t1, t2, t3, t4, t5, t6;
    if(pthread_create(&t0,NULL,circuitList,NULL)==-1)
        perror("Unable to create a thread for circuitList function\n");
    else if(pthread_create(&t1,NULL,list,NULL)==-1)
        perror("Unable to create a thread for list function\n");
    else if(pthread_create(&t2,NULL,dual_list,NULL)==-1)
        perror("Unable to create a thread for dual_list function\n");
    else if(pthread_create(&t3,NULL,stack,NULL)==-1)
        perror("Unable to create a thread for stack function\n");
    else if(pthread_create(&t4,NULL,STL_Test,NULL)==-1)
        perror("Unable to create a thread for STL_Test function\n");
    else if(pthread_create(&t5,NULL,warteschlange,NULL)==-1)
        perror("Unable to create a thread for warteschlange function\n");
    else
        printf("Error creating threads.");

    void *result;
    if(pthread_join(t0,&result)==-1)
        perror("Can't join thread t0\n");
    if(pthread_create(&t0,NULL,circuitList,NULL)==-1)
        perror("Unable to create a thread for circuitList function\n");
    else if(pthread_create(&t1,NULL,list,NULL)==-1)
        perror("Unable to create a thread for list function\n");
    else if(pthread_create(&t2,NULL,dual_list,NULL)==-1)
        perror("Unable to create a thread for dual_list function\n");
    else if(pthread_create(&t3,NULL,stack,NULL)==-1)
        perror("Unable to create a thread for stack function\n");
    else if(pthread_create(&t4,NULL,STL_Test,NULL)==-1)
        perror("Unable to create a thread for STL_Test function\n");
    else if(pthread_create(&t5,NULL,warteschlange,NULL)==-1)
        perror("Unable to create a thread for warteschlange function\n");
    else
        printf("Error creating threads.");
    pthread_exit(NULL);
}