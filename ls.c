// Test.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include "Task.h"
#include "dirent.h"
#include <string.h>
void __pragma((constructor)) premain()
{
	puts("premain()\n");
}

int main(int argc, char *argv[])
{
	opt = 0;
	//file();
	test();
	system("pause");
	return 0;
}
//-----
