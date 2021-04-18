//
// Created by alimovlex
//

//
#define QMAX 100
#ifdef __cplusplus
extern "C" {
#endif
int sequenceTest();
//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
struct Sequence
{
    int qu[QMAX];
    int rear, frnt;
};