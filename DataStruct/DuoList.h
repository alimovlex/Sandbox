#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void push_double(struct Node** head_ref, int new_data);
DLL void insertAfter(struct Node* prev_node, int new_data);
DLL void append(struct Node** head_ref, int new_data);
DLL void print_double(struct Node* node);
DLL void dual_list();
DLL void eraseNode(struct Node** head_ref, struct Node* del);
DLL void reverse_double(struct Node **head_ref);