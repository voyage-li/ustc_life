#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void insert(BiTree &T, int x)
{
    if (T == nullptr)
    {
        BiTree p = new BiTNode;
        p->data = x;
        p->lchild = nullptr;
        p->rchild = nullptr;
        T = p;
    }
    else
    {
        if (T->data == x)
            return;
        if (x < T->data)
            insert(T->lchild, x);
        else
            insert(T->rchild, x);
    }
}

void above_x(BiTree &T, int x)
{
    if (T == nullptr)
        return;
    if (x <= T->data)
    {
        if (T->rchild != nullptr)
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

int main()
{
    BiTree T = nullptr;
    int c = 1;
    std::cin >> c;
    while (c != 0)
    {
        insert(T, c);
        std::cin >> c;
    }
    above_x(T, 3);
    return 0;
}