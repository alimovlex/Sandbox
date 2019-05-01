// Test.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "Task.h"
#include "dirent.h"
#include "DataStruct.h"
#include "Multi_thread.h"
#include "MyMathDll.h"
#define start main
void __pragma((constructor)) premain()
{
	puts("premain()\n");
}

int start()
{
	except();
	system("pause");
	return 0;
}
//-----
//switch((int)(n1 > n2))  
//case 1 ... 5: