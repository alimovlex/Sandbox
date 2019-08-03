#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL void circuitList();
DLL void druekenList(struct Node *head);
DLL void push_circle(struct Node **head_ref, int data);
DLL void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
DLL struct Node *exchangeNodes(struct Node *head);