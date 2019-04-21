typedef struct Node
{
	void *data;
	struct Node *next;
} Node;
Node *add(Node *head, void *data, int bytes);
void *get(Node *head, int index);
int size(Node *head);
void freeList(Node *head);
void list();