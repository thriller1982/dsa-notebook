#ifndef DSA_NOTEBOOK_AVL_TREE_H
#define DSA_NOTEBOOK_AVL_TREE_H

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;
AvlTree Insert(ElementType x, AvlTree t);

#endif //DSA_NOTEBOOK_AVL_TREE_H