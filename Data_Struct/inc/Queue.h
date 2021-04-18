//
// Created by alimovlex
//

//
#ifdef __cplusplus
extern "C" {
#endif
int queueTest();
//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};
