#ifndef DSA_NOTEBOOK_LINKED_LIST_H
#define DSA_NOTEBOOK_LINKED_LIST_H
#include <stdbool.h>
typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

bool IsEmpty(List l);
bool IsLast(Position p, List l);
Position Find(ElementType x, List l);
Position FindPrevious(ElementType x, List l);
void Delete(ElementType x, List l);
void Insert(ElementType x, List l, Position p);

#endif //DSA_NOTEBOOK_LINKED_LIST_H