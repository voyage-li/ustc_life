#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 9.38
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
void together(BiTree &T1, BiTree &T2)
{
    if (T2 == nullptr)
        return;
    std::queue<BiTree> s;
    s.push(T1);
    while (!s.empty())
    {
        BiTree now = s.front();
        s.pop();
        insert(T1, now->data);
        if (now->lchild != nullptr)
            s.push(now->lchild);
        if (now->rchild != nullptr)
            s.push(now->rchild);
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
    return 0;
}