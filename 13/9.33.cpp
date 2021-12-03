#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void above_x(BiTree &T, int x)
{
    if (T == nullptr)
        return;
    if (x < T->data && T->rchild != nullptr)
    {
        above_x(T->rchild, x);
        std::cout << T->data << " ";
        if (T->lchild != nullptr)
            above_x(T->lchild, x);
    }
    else
    {
        if (T->rchild != nullptr)
            above_x(T->rchild, x);
    }
}
