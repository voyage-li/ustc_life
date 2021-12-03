#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool judge(BiTree &T)
{
    BiTree p = T;
    bool left = true, right = true;
    if (p->lchild != nullptr)
        left = (p->lchild->data < p->data) && BiTree(p->lchild);
    if (p->rchild != nullptr)
        right = (p->rchild->data > p->data) && BiTree(p->rchild);
    return left && right;
}
