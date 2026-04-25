/**
 * @file avl_tree.c
 * @brief AVL 树的旋转平衡操作，包含单旋转和双旋转
 * @author lqy
 * @date 2026-4-25
 */

#include "avl_tree.h"
#include <stddef.h>
#include "fatal.h"
#define Max(a, b) ((a) > (b) ? (a) : (b))
struct AvlNode {
    ElementType element;
    AvlTree left;
    AvlTree right;
    int height;
};

/**
 * @brief 取得 Avl 树节点高度
 * @param p 需要求高度的节点
 * @return 输入节点的高度
 */
static int Height(Position p) {
    if (p == NULL)
        return -1;
    return p->height;
}

/**
 * @brief LL 情况，即执行右旋转
 * @param k2 失衡点，即平衡因子大于一
 * @return Position 旋转后的新根节点
 */
static Position SingleRotateWithLeft(Position k2) {
    // k1 将称为新的根节点
    Position k1 = k2->left;

    // 将 k1 的右节点转移到 k2 的左节点
    k2->left = k1->right;
    // 将 k1 的右节点设置为 k2
    k1->right = k2;

    // k2 是 k1 子节点，k1 高度依赖 k2 高度，故先更新 k2的高度
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;

    // 返回新的根节点
    return k1;
}

static Position SingleRotateWithRight(Position k1) {
    Position k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;

    return k2;
}

/**
 * @brief LR 情况的平衡修正
 * @param k3 LR 情况的节点
 * @return 平衡修正后的新根节点
 */
static Position DoubleRotateWithLeft(Position k3) {
    // 对 k3 子树进行左旋转修正
    k3->left = SingleRotateWithRight(k3->left);

    // 对 k3 进行右旋转并返回新根节点
    return SingleRotateWithLeft(k3);
}

static Position DoubleRotateWithRight(Position k1) {
    k1->right = SingleRotateWithLeft(k1->right);

    return SingleRotateWithRight(k1);
}


/**
 * @brief 向 Avl 树插入一个数据
 * @param x 要插入的数据
 * @param t 插入数据的 Avl 树
 * @return Avl 树插入数据并旋转平衡后的新根节点
 */
AvlTree Insert(ElementType x, AvlTree t) {
    // 若找到插入位置则插入
    if (t == NULL) {
        t = malloc(sizeof(struct AvlNode));
        if (t == NULL) {
            FatalError("Out of space!!!");
        } else {
            t->left = t->right = NULL;
            t->element = x;
            t->height = 0;
        }
    }
    // 向左子树插入
    else if (x < t->element) {
        // 注意要接收新的左子树
        t->left = Insert(x, t->left);
        // 因为是插入到左子树，只有可能是左子树高度更高，所以直接写成左子树高度减右子树高度
        if (Height(t->left) - Height(t->right) > 1) {
            // 判断插入到了左子树的哪个子树
            if (x < t->left->element)
                // 插入到了左子树的左子树，LL 情况, 注意接收
                t = SingleRotateWithLeft(t);
            else
                // 插入到了左子树的右子树，LR 情况，注意接收
                t = DoubleRotateWithLeft(t);
        }
    } else if (x > t->element) {
        t->right = Insert(x, t->right);
        if (Height(t->right) - Height(t->left) > 1) {
            if (x > t->right->element)
                t = SingleRotateWithRight(t);
            else
                t = DoubleRotateWithRight(t);
        }
    }
    t->height = Max(Height(t->left), Height(t->right)) + 1;
    return t;
}