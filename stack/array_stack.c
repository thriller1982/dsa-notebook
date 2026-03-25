#include <stdlib.h>
#include "array_stack.h"
#include "fatal.h"

#define EmptyTOS (-1)

struct StackRecord {
    int capacity;
    int top_of_stack;
    ElementType* array;
};

Stack CreateStack(int max_elements) {
    Stack s = malloc(sizeof(struct StackRecord));
    if (s == NULL) {
        FatalError("Out of space!!!");
    }
    s->capacity = max_elements;
    s->top_of_stack = EmptyTOS;
    s->array = malloc(sizeof(ElementType) * max_elements);
    if (s->array == NULL) {
        FatalError("Out of space!!!");
    }
    return s;
}

void DisposeStack(Stack s) {
    if (s != NULL) {
        free(s->array);
        free(s);
    }
}

bool IsEmpty(Stack s) {
    return s->top_of_stack == EmptyTOS;
}

void MakeEmpty(Stack s) {
    s->top_of_stack = EmptyTOS;
}

bool IsFull(Stack s) {
    return s->top_of_stack == s->capacity - 1;
}

void Push(ElementType x, Stack s) {
    if (IsFull(s)) {
        Error("Full stack");
    } else {
        s->array[++(s->top_of_stack)] = x;
    }
}

ElementType Top(Stack s) {
    if (!IsEmpty(s)) {
        return s->array[s->top_of_stack];
    }
    Error("Empty stack");
    return 0;
}

void Pop(Stack s) {
    if (IsEmpty(s)) {
        Error("Empty stack");
    } else {
        s->top_of_stack--;
    }
}

ElementType TopAndPop(Stack s) {
    if (IsEmpty(s)) {
        Error("Empty stack");
        return 0;
    } else {
        return s->array[s->top_of_stack--];
    }
}