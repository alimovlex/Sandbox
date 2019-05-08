#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void pointers();
DLL void swap(int *num1, int *num2);
DLL void error();
DLL void listFiles();
DLL void file();
DLL void preprocessor();
DLL void memory();
DLL void zeit();
DLL void sigintHandler(int sig_num);
DLL void freeze();
DLL void vremya();
DLL void foo();
DLL void *myThreadFun(void *vargp);
DLL void potock();
DLL void except();
DLL void massiv();
DLL void swap2(char *str1, char *str2);
DLL void dynamic_array_print(int **A, size_t N, size_t M);
DLL int ** dynamic_array_alloc(size_t N, size_t M);
DLL void dynamic_array_free(int **A, size_t N);
DLL void dynamic_array_test(size_t N, size_t M);