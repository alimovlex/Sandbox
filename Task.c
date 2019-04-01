#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include "dirent.h"
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x
volatile int opt = 1;
typedef char string;
#pragma region My Learning
enum Gender 
{
	MALE,
	FEMALE
};
struct numbers {
	int   hex;
	int   dec;
	int   bin;
};
union Data
{
	int i;
	float f;
	char str[20];
};
typedef struct
{
	int x;
	int y;
} point;

typedef struct
{
	float radius;
	point center;
} circle;
static char *ErrorNames[] = 
{
	"Index Out Of Bounds",
	"Stack Overflow",
	"Stack Underflow",
	"Out of Memory"
};

enum Errors {
	INDEX_OUT_OF_BOUNDS = 1,
	STACK_OVERFLOW,
	STACK_UNDERFLOW,
	OUT_OF_MEMORY
};
int number(struct numbers *a)
{
	return (a->dec + a->bin);
}
inline int square(int x)
{
	return x*x;
}
void Fn(void) {
start:
	if (opt == 1)
		goto start;
	else
		opt = 0;
}
void test()
{
	enum Gender x, y;
	x = MALE;
	y = FEMALE;
	struct numbers *a;
	a = malloc(sizeof(struct numbers));
	int sixteen = 0xFFF;
	int ten = 0;
	int bin = 1;
	ten = square(16);
	a->hex = sixteen;
	a->dec = ten;
	a->bin = bin;
	number(&a);
	printf(ErrorNames[STACK_OVERFLOW],"\n");
	//Fn();
	//free(sizeof(struct numbers));
}
#pragma endregion

#pragma region Sololearn
void pointers()
{
	char *trip[] = 
	{
		"suitcase",
		"passport",
		"ticket"
	};
	int j = 63;
	int *p = NULL;
	p = &j;
	printf("The address of j is %x\n", &j);
	printf("p contains address %x\n", p);
	printf("The value of j is %d\n", j);
	printf("p is pointing to the value %d\n", *p);
	printf("Please bring the following:\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", trip[i]);
	}
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
//add proposals
void file()
{
	string str[16] = "Hello ";
	strcat(str,"World\n");
	printf("%s",str);
}

void preprocessor()
{
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
	printf("\a");
}
#pragma endregion