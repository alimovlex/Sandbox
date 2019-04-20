#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "dirent.h"
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x
#define B(x) S_to_binary_(#x)
static inline unsigned long long S_to_binary_(const char *s)
{
	unsigned long long i = 0;
	while (*s) {
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

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
	int   oct;
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
	return (a->dec + a->hex);
}


void test()
{
	srand((unsigned)time(NULL));
	enum Gender x, y;
	x = MALE;
	y = FEMALE;
	struct numbers *a;
	a = malloc(sizeof(struct numbers));
	int sixteen = rand()%0xFFF;
	int ten = rand()%20;
	int bin = rand()%B(111);
	int oct = rand() % 020;
	int i = 0;
	a->hex = sixteen;
	a->dec = ten;
	a->bin = bin;
	a->oct = oct;
	printf(ErrorNames[STACK_OVERFLOW],"\n");
	printf("\nHexadecimal number:0x%02X \n", a->hex); //hexadecimal output
	printf("Decimal RND number: %d\n", a->dec);
	printf("Binary RND number: %d\n", a->bin);
	printf("Octal RND number: %o\n", a->oct);
	printf("Oct and Hex numbers: %o 0x%02X\n", a->oct,a->hex);
	printf("~hex = 0x%02X\n",~a->hex);  
	printf("bin<<1 = %d\n", a->bin << 1);  
	printf("bin>>1 = %d\n", a->bin >> 1);
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
#pragma endregion

#pragma region Sololearn
void pointers()
{
	int j = 63;
	int *p = NULL;
	p = &j;
	int **x = &p;
	**x = 70;
	printf("The address of j is 0x%02X\n", &j);
	printf("p contains address 0x%02X\n", p);
	printf("The value of j is %d\n", j);
	printf("p is pointing to the value %d\n", *p);
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
	FILE *fp;
	char buff[255];
	fp = fopen("test.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
	//reading the file
	fp = fopen("test.txt", "r");
	while (fgets(buff, sizeof buff, fp))
	{
		printf("%s\n", buff);
	}
	
	fclose(fp);
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
#pragma endregion