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
#include "Matrix.h"
#include "Stack.h"
#include "Queue.h"
#include "Dynamic_Queue.h"
#include "Inet.h"
#include "Multithread.h"
#include "Data_Test.h"
#include "t_clib.h"
#include "c_lib.h"
void testings();

int main(int argc, char *argv[])
{
    void(*func)()=ptr_test;
    func();
    //stl_int_array();
    //stl_dynamic_array();
    //stl_strings_array();
    //testings();
    return 0;
}

void testings()
{
    void(*functions[])() = {listFiles, file, preprocessor, memory, zeit, vremya, ptr_test, test, func_ptr, pythonScript};
    massiv(3);
    matrix(3, 3);
    circuitList();
    list();
    dual_list();
    stack();
    queue(6);
    warteschlange();
    massiv(4);
    data_test();
    stl_test();
}
//-----
//switch((int)(n1 > n2))  
//case 1 ... 5:
//while(1)
/*

*/