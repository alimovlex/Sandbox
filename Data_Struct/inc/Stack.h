#define _STACK_ARRAY_H_
#define SIZE_STACK_ARRAY 100
void stackTest();
typedef struct
{
    int buf[SIZE_STACK_ARRAY];
    unsigned uk;
} StackArray;
static const int okStackArray = 0;
static const int fullStackArray = 1;
static const int emptyStackArray = 2;
static int errorStackArray;
