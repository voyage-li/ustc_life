#include <bits/stdc++.h>
typedef struct BBTNode
{
    int BF;
    int data;
    struct BBTNode *lchild, *rchild;
    int lsize;
} BBTNode, *AVL;

AVL find_k_small(AVL &T, int k)
{
    if (T->lsize > k)
    {
        if (T->lchild != nullptr)
            return find_k_small(T->lchild, k);
    }
    else if (T->lsize == k)
        return T;
    else
    {
        if (T->rchild != nullptr)
            return find_k_small(T->rchild, k - T->lsize);
    }
    return nullptr;
}