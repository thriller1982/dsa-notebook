#include "binary_search_tree.h"
#include <stdlib.h>
#include "fatal.h"

struct AvlNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree MakeEmpty(SearchTree t) {
    if (t != NULL) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return NULL;
}

Position Find(ElementType x, SearchTree t) {
    if (t == NULL)
        return NULL;
    if (x == t->element)
        return t;
    else if (x < t->element)
        return Find(x, t->left);
    else
        return Find(x, t->right);
}

Position FindMin(SearchTree t) {
    if (t == NULL)
        return NULL;
    if (t->left == NULL)
        return t;
    else
        return FindMin(t->left);
}

Position FindMax(SearchTree t) {
    if (t == NULL)
        return NULL;
    if (t->right == NULL)
        return t;
    else
        return FindMax(t->right);
}

SearchTree Insert(ElementType x, SearchTree t) {
    if (t == NULL) {
        t = malloc(sizeof(struct AvlNode));
        if (t == NULL) {
            FatalError("Out of space!!!");
        } else {
            t->element = x;
            t->left = t->right = NULL;
        }
    } else if (x < t->element) {
        t->left = Insert(x, t->left);
    } else {
        t->right = Insert(x, t->right);
    }
    return t;
}

SearchTree Delete(ElementType x, SearchTree t) {
    if (t == NULL)
        Error("Element not found");
    if (x < t->element)
        t->left = Delete(x, t->left);
    else if (x > t->element)
        t->right = Delete(x, t->right);
    else if (t->right && t->left) {
        Position tmp_cell = FindMin(t->right);
        t->element = tmp_cell->element;
        t->right = Delete(t->element, t->right);
    } else {
        Position tmp_cell = t;
        if (t->left == NULL) {
            t = t->right;
        } else {
            t = t->left;
        }
        free(tmp_cell);
    }
    return t;
}