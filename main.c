#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include <unistd.h>
#include "Object.h"
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



int main(int argc, char *argv[])
{
    //void(*functions[])() = {listFiles, file, preprocessor, memory, zeit, vremya, foo, test, func_ptr, pythonScript};
    void(*func)()=test_animals;
    func();
    func=exception;
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