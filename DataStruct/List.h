#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif
DLL void printList(struct Node *n);
DLL void list();
DLL void push(struct Node** head_ref, int new_data);
DLL void deleteNode(struct Node **head_ref, int position);
DLL void deleteList(struct Node** head_ref);
DLL int getCount(struct Node* head);
DLL void swapNodes(struct Node **head_ref, int x, int y);
DLL void reverse(struct Node** head_ref);
DLL struct Node *rewerse(struct Node *head, int k);
DLL int detectloop(struct Node* list);
DLL struct Node* addTwoLists(struct Node* first, struct Node* second);
DLL void rotate(struct Node **head_ref, int k);
DLL void push_circle(struct Node **head_ref, int data);
DLL void druekenList(struct Node *head);
DLL void circuitList();
DLL void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);