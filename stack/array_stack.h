#ifndef DSA_NOTEBOOK_ARRAY_STACK_H
#define DSA_NOTEBOOK_ARRAY_STACK_H
#include <stdbool.h>
typedef int ElementType;
struct StackRecord;
typedef struct StackRecord* Stack;

Stack CreateStack(int max_elements);
void DisposeStack(Stack s);
bool IsEmpty(Stack s);
void MakeEmpty(Stack s);
bool IsFull(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);

#endif //DSA_NOTEBOOK_ARRAY_STACK_H