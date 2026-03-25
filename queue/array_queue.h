#ifndef DSA_NOTEBOOK_ARRAY_QUEUE_H
#define DSA_NOTEBOOK_ARRAY_QUEUE_H
#include <stdbool.h>
typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord* Queue;

bool IsEmpty(Queue q);
void MakeEmpty(Queue q);
bool IsFull(Queue q);
void Enqueue(ElementType x, Queue q);
Queue CreateQueue(int max_elements);
ElementType Dequeue(Queue q);

#endif //DSA_NOTEBOOK_ARRAY_QUEUE_H