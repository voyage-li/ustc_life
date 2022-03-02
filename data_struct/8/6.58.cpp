#include <bits/stdc++.h>

//6.58
#define TElemType int
typedef struct ThreadNode
{
    TElemType val;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void insert(ThreadTree p, ThreadTree x)
{
    if (p->ltag == 1)
    {
        p->ltag = 0;
        x->rchild = p;
        ThreadTree temp = p->lchild;
        p->lchild = x;
        if (temp != NULL)
        {
            ThreadTree q = x;
            while (q->lchild != NULL)
                q = q->lchild;
            temp->rchild = q;
            q->ltag = 1;
            q->lchild = temp;
        }
    }
    else
    {
        x->rchild = p->rchild;
        p->rtag = 0;
        p->rchild = x;
        ThreadTree q = x;
        while (q->lchild != NULL)
            q = q->lchild;
        q->ltag = 1;
        q->lchild = p;
    }
}