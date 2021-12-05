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
    std::cout << judge(T);
    return 0;
}