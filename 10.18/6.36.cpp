#include <bits/stdc++.h>
#define TElemType int
typedef struct BiTNode
{
    TElemType val;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool similar(BiTree l1, BiTree l2)
{
    if (!l1 && !l2)
        return true;
    else if (!l1 || !l2)
        return false;
    else
        return (similar(l1->lchild, l2->lchild) && similar(l1->rchild, l2->rchild));
}

int main()
{
}