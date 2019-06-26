#ifdef DLL_EXPORTS
#define DLL __declspec(dllexport) 
#else
#define DLL __declspec(dllimport) 
#endif

DLL struct StackNode* neueNode(int data);
DLL int isEmpty(struct StackNode* root);
DLL void pusch(struct StackNode** root, int data);
DLL int pop(struct StackNode** root);
DLL int peek(struct StackNode* root);
DLL void stack();
