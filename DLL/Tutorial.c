#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include "unistd.h"
#include "dirent.h"
#include "Tutorial.h"
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x

#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

#define B(x) S_to_binary_(#x)
unsigned long long S_to_binary_(const char *s)
{
	unsigned long long i = 0;
	while (*s)
	{
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

typedef char string;

struct Data
{
	int i; //4 bytes
	int8_t k; //1 byte
	int16_t l; //2 byte
	int32_t m; //4 byte
	int64_t n; //8 byte
	long int j; //8 byte
	float f; //4 byte
	double g; //8 byte
	long double h; //8 byte
	string str[0]; //1 byte
}infa;

void test()
{
	srand((unsigned)time(NULL));
	int hex = rand() % 0xFFF;
	int dec = rand() % 20;
	int bin = rand() % B(111);
	int oct = rand() % 020;
	int i = 0;
	printf("\nHexadecimal number:0x%02X \n", hex); //hexadecimal output
	printf("Decimal RND number: %d\n", dec);
	printf("Binary RND number: %d\n", bin);
	printf("Octal RND number: %o\n", oct);
	printf("Oct and Hex numbers: %o 0x%02X\n", oct, hex);
	printf("~hex = 0x%02X\n", ~hex);
	printf("bin<<1 = %d\n", bin << 1);
	printf("bin>>1 = %d\n", bin >> 1);
	printf("postfix = %i\n", i++);//i=1
	printf("prefix = %i\n", ++i);
	printf("In C programming All graphic "
		"characters are: \n");
	for (i = 0; i <= 127; ++i)
		if (isgraph(i) != 0)
			printf("%c ", i);
	printf("\n");

	//Fn();
	//free(sizeof(struct numbers));
}

void foo()
{
	int a = 10;
	static int sa = 10; //example of static variable (it saves its value over each function calling)

	a += 5;
	sa += 5;

	printf("a = %d, sa = %d\n", a, sa);
}

void pointers()
{
	int j = 63, x = 4, i = 0,a=10;
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
	void(*ls_ptr)();  //pointer to function
	ls_ptr = &foo;
	for (i = 0; i < 10; ++i)
	(*ls_ptr)(&a);
}

void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void swap_str(char *str1, char *str2)
{
	char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	free(temp);
}
void error()
{
	float k = -5;
	float num = 1000;
	double result;
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

void memory()
{
	float x = 0.1;
	long int a = 1;
	int8_t z = 2;
	char b = 'G';
	long double c = 3.14;
	struct Data;
	//-------------------------------printing the variables defined above along with their sizes 
	printf("Size of char %d\n",sizeof(b));
	printf("Size of long int %d\n",sizeof(a));
	printf("Size of long double %d\n", sizeof(c));
	printf("Size of float %d\n", sizeof(x));
	printf("Size of int %d\n", sizeof(z));
	printf("Size of union %d\n", sizeof(infa));
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
	//return vremya();
}

void vremya()
{
	clock_t t;
	t = clock();
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("function took %f seconds to execute \n", time_taken);
}

void sigintHandler(int sig_num)
{
		/* Reset handler to catch SIGINT next time.
		Refer http://en.cppreference.com/w/c/program/signal */
		signal(SIGINT, sigintHandler);
		printf("\n Cannot be terminated using Ctrl+C \n");
		fflush(stdout);
}

void except(int x,int y)
{
	double z = 0;
	TRY
	{
		if (y == 0)
	THROW;
	printf("No exception caught \n");
	z = x / y;
	//printf("Z= %d\n", z);
	}
		CATCH
	{
		printf("Division by zero\n");
	}
	ETRY;
}

int assembler()
{
	int joe = 1234, fred;
	__asm
	{
		mov eax, joe; eax = joe(1234)
		add eax, 2; eax += 2 (1236)
		mov fred, eax; fred = eax(1236)
	};
	return fred;
}

