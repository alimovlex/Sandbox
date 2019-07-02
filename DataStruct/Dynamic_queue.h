#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void warteschlange();
DLL int rear(struct Queue* queue);
DLL int front(struct Queue* queue);
DLL int dequeue(struct Queue* queue);
DLL void enqueue(struct Queue* queue, int item);
DLL int isEmpty(struct Queue* queue);
DLL int isFull(struct Queue* queue);
DLL struct Queue* createQueue(unsigned capacity);
