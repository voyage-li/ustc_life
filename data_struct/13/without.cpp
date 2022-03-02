//二叉排序树 非递归查找算法
#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//非递归查找
BiTree find(BiTree &T, int x)
{
    std::stack<BiTree> s;
    if (T == nullptr)
        return T;
    s.push(T);
    BiTree answer = nullptr;
    while (!s.empty())
    {
        BiTree p = s.top();
        s.pop();
        if (p->data == x)
        {
            answer = p;
            break;
        }
        else if (p->data > x)
        {
            if (p->lchild != nullptr)
                s.push(p->lchild);
        }
        else
        {
            if (p->rchild != nullptr)
                s.push(p->rchild);
        }
        if (p->lchild == nullptr && p->rchild == nullptr)
            break;
    }
    return answer;
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
    std::cout << find(T, 3)->data;
    return 0;
}