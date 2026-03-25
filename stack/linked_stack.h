#ifndef DSA_NOTEBOOK_LINKED_STACK_H
#define DSA_NOTEBOOK_LINKED_STACK_H
#include <stdbool.h>

typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

bool IsEmpty(Stack s);
Stack CreateStack(void);
void push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);

#endif //DSA_NOTEBOOK_LINKED_STACK_H