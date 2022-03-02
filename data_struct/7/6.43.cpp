#include <bits/stdc++.h>
#define TElemType int
typedef struct BiTNode
{
    TElemType val;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree reverse_lr(BiTree l)
{
    if (!l)
        return NULL;
    else
    {
        BiTree temp;
        temp = l->lchild;
        l->lchild = reverse_lr(l->rchild);
        l->rchild = reverse_lr(temp);
    }
    return l;
}
