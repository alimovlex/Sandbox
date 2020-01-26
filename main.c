#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include <unistd.h>
#include "Tutorial.h"
#include "List.h"
#include "Circuit_List.h"
#include "DuoList.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Dynamic_queue.h"
#include "Inet.h"
#include "Multithread.h"
void myStartupFun (void) __attribute__ ((constructor)); 
/* Apply the destructor attribute to myCleanupFun() so that it is executed after main() */
void myCleanupFun (void) __attribute__ ((destructor)); 
/* implementation of myStartupFun */
void myStartupFun (void) 
{ 
    printf ("startup code before main()\n"); 
    unsigned int i = 1; 
    char *c = (char*)&i; 
    if (*c)     
       printf("Little endian\n"); 
    else
       printf("Big endian\n"); 
} 
/* implementation of myCleanupFun */
void myCleanupFun (void) 
{ 
    printf ("cleanup code after main()\n"); 
} 


int main(int argc, char *argv[])
{
    void(*functions[])() = {listFiles, file, preprocessor, memory, zeit, vremya, foo, test, func_ptr, pythonScript};
    void(*func)()=sandbox;
    func();
    return 0;
}
//-----
//switch((int)(n1 > n2))  
//case 1 ... 5:

/*
except(50,0);
massiv(3);
matrix(3, 3);
//while(1)
circuitList();
list();
dual_list();
stack();
queue(6);
warteschlange();
*/