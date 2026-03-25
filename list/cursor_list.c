#include <stdbool.h>
#include "cursor_list.h"
#include "fatal.h"
static Position CursorAlloc(void);
static void CursorFree(Position p);
struct Node {
    ElementType element;
    Position next;
};

struct Node cursor_space[100];

static Position CursorAlloc(void) {
    Position p;

    p = cursor_space[0].next;
    cursor_space[0].next = cursor_space[p].next;

    return p;
}

static void CursorFree(Position p) {
    cursor_space[p].next = cursor_space[0].next;
    cursor_space[0].next = p;
}

bool IsEmpty(List l) {
    return cursor_space[l].next == 0;
}

bool IsLast(Position p, List l) {
    return cursor_space[p].next == 0;
}

Position Find(ElementType x, List l) {
    Position p;

    p = cursor_space[l].next;
    while (p && cursor_space[p].element != x) {
        p = cursor_space[p].next;
    }

    return p;
}

void Insert(ElementType x, List l, Position p) {
    Position tem_p = CursorAlloc();

    if (tem_p == 0) {
        FatalError("Out of space!!!");
    }
    cursor_space[tem_p].next = cursor_space[p].next;
    cursor_space[tem_p].element = x;
    cursor_space[p].next = tem_p;
}