//二叉排序树 非递归查找算法
#include <bits/stdc++.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

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