#include <stdlib.h>
#include "linked_stack.h"
#include "fatal.h"

struct Node {
    ElementType element;
    PtrToNode next;
};

bool IsEmpty(Stack s) {
    return s->next == NULL;
}

Stack CreateStack(void) {
    Stack s;

    s = malloc(sizeof(struct Node));
    if (s == NULL) {
        FatalError("Out of space!!!");
    }
    s->next = NULL;
    return s;
}

void push(ElementType x, Stack s) {
    PtrToNode tmp_cell = malloc(sizeof(struct Node));
    if (tmp_cell == NULL) {
        FatalError("Out of space!!!");
    }
    tmp_cell->element = x;
    tmp_cell->next = s->next;
    s->next = tmp_cell;
}

ElementType Top(Stack s) {
    if (!IsEmpty(s)) {
        return s->next->element;
    }
    Error("Empty stack");
    return 0;
}

void Pop(Stack s) {
    if (IsEmpty(s)) {
        Error("Empty stack");
    } else {
        PtrToNode first_cell = s->next;
        s->next = s->next->next;
        free(first_cell);
    }
}