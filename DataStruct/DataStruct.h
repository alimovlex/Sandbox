#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif
DLL void printList(struct Node *n);
DLL void list();
DLL void push(struct Node** head_ref, int new_data);
DLL void deleteNode(struct Node **head_ref, int position);