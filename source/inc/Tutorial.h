void testingPointers(int *p, void *ptr);
void listFiles();
void fileTest();
void preprocessingTest();
void dataTypeSizeTest();
clock_t localTimeCheck();
clock_t timerFunction(void(*func)());
void pointersTest();
unsigned long long StringToBinary_(const char *s);
void characterSetTest();
void argumentsTest(int args,...);
void sandbox();


typedef char string;

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
    string str[0]; //1 byte
}TypeSize;
