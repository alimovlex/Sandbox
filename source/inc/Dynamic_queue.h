void warteschlange();
int rear(struct Queue* queue);
int front(struct Queue* queue);
int dequeue(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int isEmpty(struct Queue* queue);
int isFull(struct Queue* queue);
struct Queue* createQueue(unsigned capacity);
