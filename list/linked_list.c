#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"
#include "fatal.h"

struct Node {
    ElementType element;
    PtrToNode next;
};

bool IsEmpty(List l) {
    return l->next == NULL;
}

bool IsLast(Position p, List l) {
    return p->next == NULL;
}

Position Find(ElementType x, List l) {
    Position p = l->next;

    while (p != NULL && p->element != x) {
        p = p->next;
    }
    return p;
}

Position FindPrevious(ElementType x, List l) {
    Position p = l;

    while (p->next != NULL && p->next->element != x) {
        p = p->next;
    }
    return p;
}

void Delete(ElementType x, List l) {
    Position p = FindPrevious(x, l);

    if (!IsLast(p, l)) {
        Position temp_p = p->next;
        p->next = temp_p->next;
        free(temp_p);
    }
}

void Insert(ElementType x, List l, Position p) {
    Position temp_p = malloc(sizeof(struct Node));
    if (temp_p == NULL) {
        FatalError("Out of space!!!");
    }

    temp_p->element = x;
    temp_p->next = p->next;
    p->next = temp_p;
}