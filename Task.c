#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
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
enum Gender
{
	MALE,
	FEMALE
};
struct numbers 
{
	int   hex;
	int   dec;
	int   bin;
	int   oct;
};

void test()
{
	srand((unsigned)time(NULL));
	enum Gender x, y;
	x = MALE;
	y = FEMALE;
	struct numbers *a;
	a = malloc(sizeof(struct numbers));
	int sixteen = rand() % 0xFFF;
	int ten = rand() % 20;
	int bin = rand() % B(111);
	int oct = rand() % 020;
	int i = 0;
	a->hex = sixteen;
	a->dec = ten;
	a->bin = bin;
	a->oct = oct;
	printf(ErrorNames[STACK_OVERFLOW], "\n");
	printf("\nHexadecimal number:0x%02X \n", a->hex); //hexadecimal output
	printf("Decimal RND number: %d\n", a->dec);
	printf("Binary RND number: %d\n", a->bin);
	printf("Octal RND number: %o\n", a->oct);
	printf("Oct and Hex numbers: %o 0x%02X\n", a->oct, a->hex);
	printf("~hex = 0x%02X\n", ~a->hex);
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

