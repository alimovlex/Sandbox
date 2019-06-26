#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void matrix_print(int **A, size_t N, size_t M);
DLL int ** matrix_alloc(size_t N, size_t M);
DLL void matrix_free(int **A, size_t N);
DLL void matrix(size_t N, size_t M);
DLL void massiv(int size);