void TestingPointers(int *p, void *ptr);
void ListFiles();
void FileTest();
void PreprocessingTest();
void DataTypeSizeTest();
clock_t LocalTimeCheck();
void sigintHandler(int sig_num);
clock_t TimerFunction();
void PointersTest();
unsigned long long StringToBinary_(const char *s);
void CharacterSetTest();
void ArgumentsTest(int args,...);
void Sandbox();


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
