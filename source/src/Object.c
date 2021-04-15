/*
    Object.c
    The module represents my demo functions from OC-GCC C Library.
    For more, please see the OOStd.h file

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <math.h>
#include <tgmath.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <float.h>
#include <pthread.h>
#include <Block.h>
#include "OOStd.h"
//--------------------------------------------------------FIRST TUTORIAL----------------------------------------
CLASS(Animal)
{
        char *name;
        STATIC(Animal);
        vFn talk;
};
static int Animal_Load(Animal *THIS,void *name)
{
    THIS->name = name;
    return 0;
}
ASM(Animal, Animal_Load, NULL, NULL, NULL)

CLASS_EX(Cat,Animal)
{
STATIC_EX(Cat, Animal);
};
static void Meow(Animal *THIS)
{
    printf("Meow!My name is %s!\n", THIS->name);
}

static int Cat_loadSt(StAnimal *THIS, void *PARAM)
{
    THIS->talk = (void *)Meow;
    return 0;
}
ASM_EX(Cat,Animal, NULL, NULL, Cat_loadSt, NULL)


CLASS_EX(Dog,Animal)
{
STATIC_EX(Dog, Animal);
};

static void Woof(Animal *THIS)
{
    printf("Woof!My name is %s!\n", THIS->name);
}

static int Dog_loadSt(StAnimal *THIS, void *PARAM)
{
    THIS->talk = (void *)Woof;
    return 0;
}
ASM_EX(Dog, Animal, NULL, NULL, Dog_loadSt, NULL)


void Test_Animals_Class()
{
    Animal *animals[4];
    StAnimal *f;
    int i = 0;
    for (i=0; i<4; i++)
    {
        if(i%2==0)
            animals[i] = NEW(Dog,"Jack");
        else
            animals[i] = NEW(Cat,"Lily");
    };
    f = ST(animals[0]);
    for(i=0; i<4; ++i) {
        f->talk(animals[i]);
    }
    for (i=0; i<4; ++i) {
        DELETE0(animals[i]);
    }
}
//--------------------------------------------------------SECOND TUTORIAL----------------------------------------
void Exception_Test2()
{
    Exception *e=GET_EXCEPTION(1);
    TRY
    THROW(e);
    END_TRY
}
void Exception_Test1()
{
    Exception e={"exception test2 has been changed!"};
    SET_EXCEPTION(1,&e);
    TRY
    Exception_Test2();
    CATCH(&e)
    fprintf(stderr,"!!! exception : %s\n",e.reason);
    END_TRY
}
void Exception_Test()
{
    Exception excp[32]={
            {"test1"},
            {"test2"},
            {"test3"},
    };

    SET_EXCEPTIONS(&excp,32);
    TRY
    Exception_Test1();
    FINALLY
    fprintf(stderr,"final process\n");
    END_TRY
}

//----------------------------------------------------------------------ENDING-----------------------------------