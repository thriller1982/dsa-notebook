#include <stdlib.h>
#include "array_queue.h"
#include "fatal.h"

static int Succ(int value, Queue q);

struct QueueRecord {
    int size;
    int capacity;
    int rear;
    int front;
    ElementType* array;
};

bool IsEmpty(Queue q) {
    return q->size == 0;
}

void MakeEmpty(Queue q) {
    q->size = 0;
    q->front = 1;
    q->rear = 0;
}

static int Succ(int value, Queue q) {
    if (++value == q->capacity) {
        value = 0;
    }
    return value;
}

bool IsFull(Queue q) {
    return q->size == q->capacity;
}

void Enqueue(ElementType x, Queue q) {
    if (IsFull(q)) {
        Error("Full queue");
    } else {
        q->size++;
        q->rear = Succ(q->rear, q);
        q->array[q->rear] = x;
    }
}

ElementType Dequeue(Queue q) {
    if (IsEmpty(q)) {
        Error("Empty queue");
    }
    ElementType temp = q->array[q->front];
    q->front = Succ(q->front, q);
    --q->size;
    return temp;
}

Queue CreateQueue(int max_elements) {
    Queue q = malloc(sizeof(struct QueueRecord));
    if (q == NULL) {
        FatalError("Out of space!!!");
    }
    q->array = malloc(sizeof(ElementType) * max_elements);
    if (q->array == NULL) {
        FatalError("Out of space!!!");
    }
    q->size = 0;
    q->rear = 0;
    q->front = 1;
    q->capacity = max_elements;
    return q;
}