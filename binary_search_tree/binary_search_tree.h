#ifndef DSA_NOTEBOOK_BINARY_SEARCH_TREE_H
#define DSA_NOTEBOOK_BINARY_SEARCH_TREE_H

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode* Position;
typedef Position SearchTree;

SearchTree MakeEmpty(SearchTree t);
Position Find(ElementType x, SearchTree t);
Position FindMin(SearchTree t);
Position FindMax(SearchTree t);
SearchTree Insert(ElementType x, SearchTree t);
SearchTree Delete(ElementType x, SearchTree t);

#endif //DSA_NOTEBOOK_BINARY_SEARCH_TREE_H