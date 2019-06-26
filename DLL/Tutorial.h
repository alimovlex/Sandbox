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
DLL void vremya();
DLL void foo();
DLL void except(int x,int y);
DLL void swap_str(char *str1, char *str2);
DLL unsigned long long S_to_binary_(const char *s);
DLL void test();
DLL int assembler();