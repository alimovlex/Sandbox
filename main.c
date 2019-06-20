// Test.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include "unistd.h"
#include "Multithread.h"
#include "dirent.h"
#include "MyMathDll.h"
#include "DataStruct.h"

int main()
{
	except(50,0);
	massiv(3);
	matrix(3, 3);
	//while(1)
	list();
	system("pause");
	return 0;
}
//-----
//switch((int)(n1 > n2))  
//case 1 ... 5: