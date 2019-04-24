#include "MyMathDll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "dirent.h"
#include "MyMathDll.h"
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x
typedef char string;
#pragma region My Learning
union Data
{
	int i;
	float f;
	char str[20];
};

#pragma endregion


void pointers()
{
	int j = 63, x = 4;
	float y = 5.5;
	int *p = NULL;
	p = &j;
	int **z = &p;
	**z = 70;
	void *ptr; //the type of this pointer in the printf function
	ptr = &x;
	printf("The address of j is 0x%02X\n", &j);
	printf("p contains address 0x%02X\n", p);
	printf("The value of j is %d\n", j);
	printf("p is pointing to the value %d\n", *p);
	// (int*)ptr - does type casting of void  
	// *((int*)ptr) dereferences the typecasted  
	// void pointer variable. 
	printf("Integer variable is = %d\n", *((int*)ptr));

	// void pointer is now float 
	ptr = &y;
	printf("Float variable is= %.2f\n", *((float*)ptr));
	void(*ls_ptr)(void);  //pointer to function
	ls_ptr = &listFiles;
	// Invoking fun() using fun_ptr 
	(*ls_ptr)();
}

void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void error()
{
	float k = -5;
	float num = 1000;
	float result;
	errno = 0;
	result = sqrt(k);
	if (errno == 0)
		printf("%f ", result);
	else if (errno == EDOM) //the domain is out of range
		fprintf(stderr, "%s\n", strerror(errno));
	errno = 0;
	result = exp(num);
	if (errno == 0)
		printf("%f ", result);
	else if (errno == ERANGE) // Result too large
		fprintf(stderr, "%s\n", strerror(errno));
}

void listFiles()
{
	DIR *dp;
	struct dirent *ep;

	dp = opendir("./");
	if (dp != NULL)
	{
		while (ep = readdir(dp))
			puts(ep->d_name);
		(void)closedir(dp);
	}
	else
		perror("Couldn't open the directory");
}

void file()
{
	//writing to file
	FILE *fp = tmpfile();
	char buff[255];
	fp = fopen("test.txt", "w+");
	if (fp == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		fclose(fp);
	}
	else
	{
		fprintf(fp, "This is testing for fprintf...\n");
		fputs("This is testing for fputs...\n", fp);
		fclose(fp);
	}
	//reading the file
	fp = fopen("test.txt", "r");
	while (fgets(buff, sizeof buff, fp))
	{
		printf("%s\n", buff);
	}
	fclose(fp);
	if (remove("test.txt") == 0)
		printf("Deleted successfully\n");
	else
		printf("Unable to delete the file\n");
	/*while (!feof(fp))
	{
	fgets(buff, 255, (FILE*)fp);
	//fscanf(fp, "%s", buff);
	printf("%s\n", buff);
	}
	*/
}

void preprocessor()
{
	printf("%s\n", __func__);//print the name of the function
	printf("Minimum of 20 and 30 = %d\n", MIN(20, 30));
	printf("Maximum of 20 and 30 = %d\n", MAX(20, 30));
	printf(MKSTR(HELLO C++));
	printf("\nValue of __LINE__ : %d\n", __LINE__);
	printf("Value of __FILE__ : %s\n", __FILE__);
	printf("\nValue of __DATE__ : %s\n", __DATE__);
	printf("\nValue of __TIME__ : %s\n", __TIME__);
	printf("Multiplication = %d\n", MULTIPLY(20, 30));
	printf(merge("Hello ", "World\n"));
	printf("%s\n", get(GeeksQuiz));
	//printf("\a"); signal exclamation
}

void floatcomp()
{
	float x = 0.1;
	int a = 1;
	char b = 'G';
	double c = 3.14;
	a = (int)x + (int)c; //type casting in C
	if (x == 0.1)
		printf("IF\n");
	else if (x == 0.1f)
		printf("ELSE IF\n");
	else
		printf("ELSE\n");
	//printing the variables defined above along with their sizes 
	printf("Hello! I am a character. My value is %c and "
		"my size is %lu byte.\n", b, sizeof(char));
	//can use sizeof(b) above as well 

	printf("Hello! I am an long int. My value is %d and "
		"my size is %lu  bytes.\n", a, sizeof(long int));
	//can use sizeof(a) above as well 

	printf("Hello! I am a double floating point variable."
		" My value is %lf and my size is %lu bytes.\n", c, sizeof(long double));
}

void zeit()
{
	time_t t;
	struct tm *tmp;
	char MY_TIME[50];
	time(&t);

	//localtime() uses the time pointed by t , 
	// to fill a tm structure with the  
	// values that represent the  
	// corresponding local time. 

	tmp = localtime(&t);

	// using strftime to display time 
	strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", tmp);

	printf("Formatted date & time : %s\n", MY_TIME);
}
