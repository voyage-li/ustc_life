#include <bits/stdc++.h>
#define TElemType int
typedef struct BiTNode
{
    TElemType val;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

bool find(BiTree root, BiTree p, std::vector<BiTree> &l)
{
    if (root)
    {
        l.push_back(root);
        if (root == p)
            return true;
        bool temp = (find(root->lchild, p, l) | find(root->rchild, p, l));
        if (temp)
            return true;
        else
        {
            l.pop_back();
            return false;
        }
    }
    else
        return false;
}

BiTree LCA(BiTree root, BiTree p, BiTree q)
{
    if (p == q)
        return p;
    if (root == NULL)
        return NULL;
    std::vector<BiTree> l1, l2;
    find(root, p, l1);
    find(root, q, l2);
    for (int i = 0;; i++)
        if (l1[i] != l2[i])
            return l1[i - 1];
}

int main()
{
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->val = 1;
    BiTree q = (BiTree)malloc(sizeof(BiTNode));
    q->val = 2;
    p->lchild = q;
    BiTree m = (BiTree)malloc(sizeof(BiTNode));
    m->val = 3;
    p->rchild = m;
    m->lchild = NULL;
    m->rchild = NULL;
    m = (BiTree)malloc(sizeof(BiTNode));
    m->val = 4;
    q->lchild = m;
    m->lchild = NULL;
    m->rchild = NULL;
    m = (BiTree)malloc(sizeof(BiTNode));
    m->val = 5;
    q->rchild = m;
    m->lchild = NULL;
    m->rchild = NULL;
    std::cout << LCA(p, p->lchild->rchild, p->lchild->rchild)->val << std::endl;
}