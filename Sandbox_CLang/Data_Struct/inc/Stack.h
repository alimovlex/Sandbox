//
// Created by alimovlex
//

//
#define _STACK_ARRAY_H_
#define SIZE_STACK_ARRAY 100
#ifdef __cplusplus
extern "C" {
#endif
int stackTest();
//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
typedef struct
{
    int buf[SIZE_STACK_ARRAY];
    unsigned uk;
} StackArray;
static const int okStackArray = 0;
static const int fullStackArray = 1;
static const int emptyStackArray = 2;
static int errorStackArray;
