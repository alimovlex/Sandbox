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
#include "OOStd.h"

CLASS(Animal) {
        char *name;
        STATIC(Animal);
        vFn talk;
};
static int Animal_load(Animal *THIS,void *name) {
    THIS->name = name;
    return 0;
}
ASM(Animal, Animal_load, NULL, NULL, NULL)

CLASS_EX(Cat,Animal) {
STATIC_EX(Cat, Animal);
};
static void Meow(Animal *THIS){
    printf("Meow!My name is %s!\n", THIS->name);
}

static int Cat_loadSt(StAnimal *THIS, void *PARAM){
    THIS->talk = (void *)Meow;
    return 0;
}
ASM_EX(Cat,Animal, NULL, NULL, Cat_loadSt, NULL)


CLASS_EX(Dog,Animal){
STATIC_EX(Dog, Animal);
};

static void Woof(Animal *THIS){
    printf("Woof!My name is %s!\n", THIS->name);
}

static int Dog_loadSt(StAnimal *THIS, void *PARAM) {
    THIS->talk = (void *)Woof;
    return 0;
}
ASM_EX(Dog, Animal, NULL, NULL, Dog_loadSt, NULL)



void objecting()
{
    Animal *animals[4000];
    StAnimal *f;
    int i = 0;
    for (i=0; i<4000; i++)
    {
        if(i%2==0)
            animals[i] = NEW(Dog,"Jack");
        else
            animals[i] = NEW(Cat,"Lily");
    };
    f = ST(animals[0]);
    for(i=0; i<4000; ++i) {
        f->talk(animals[i]);
    }
    for (i=0; i<4000; ++i) {
        DELETE0(animals[i]);
    }
}
