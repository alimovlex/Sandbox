//
// Created by alimovlex
//

//
#ifdef __cplusplus
extern "C" {
#endif
int listTest();
//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif
struct Node
{
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};


