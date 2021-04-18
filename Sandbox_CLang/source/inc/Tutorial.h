//
// Created by alimovlex
//

//
#ifdef __cplusplus
extern "C" {
#endif
int listFiles();
int fileTest();
int preprocessingTest();
int dataTypeSizeTest();
int localTimeCheck();
void timerFunction(int(func)());
int pointersTest();
int characterSetTest();
int argumentsTest(int args,...);
int sandbox();

//C++ Syntax added to be referenced/built in gtest,
#ifdef __cplusplus
}
#endif

typedef struct Blank
{
    float total;
    int count;
    int tax_percent;
}Box;

typedef struct SizeOfTypes
{
    int i; //4 bytes
    __int8_t k; //1 byte
    __int16_t l; //2 byte
    __int32_t m; //4 byte
    __int64_t n; //8 byte
    long int j; //8 byte
    float f; //4 byte
    double g; //8 byte
    long double h; //8 byte
    char str[0]; //1 byte
}TypeSize;
