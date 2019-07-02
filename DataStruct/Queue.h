#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void queue(int size);
DLL int removex(struct queue *q);
DLL int remove(struct queue *q);
DLL void print(struct queue *q);
DLL int isempty(struct queue *q);
DLL void insert(struct queue *q, int x);
DLL void init(struct queue *q);