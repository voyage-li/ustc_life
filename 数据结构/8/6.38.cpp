#include <bits/stdc++.h>
#define TElemType int
typedef struct BiTNode
{
    TElemType val;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void preorderTraverse(BiTree T, void (*visit)(TElemType e))
{
    std::stack<BiTree> s;
    s.push(T);
    BiTree p;
    while (!s.empty())
    {
        p = s.top();
        while (p)
        {
            visit(p->val);
            s.push(p->lchild);
            p = s.top();
        }
        s.pop();
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            s.push(p->rchild);
        }
    }
}

void inorderTraverse(BiTree T, void (*visit)(TElemType e))
{
    std::stack<BiTree> s;
    s.push(T);
    BiTree p;
    while (!s.empty())
    {
        p = s.top();
        while (p)
        {
            s.push(p->lchild);
            p = s.top();
        }
        s.pop();
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            visit(p->val);
            s.push(p->rchild);
        }
    }
}
//6.38
void postorderTraverse(BiTree T, void (*visit)(TElemType e))
{
    std::stack<std::pair<BiTree, int>> s;
    s.push(std::make_pair(T, 0));
    BiTree p;
    while (!s.empty())
    {
        p = s.top().first;
        while (p && s.top().second == 0)
        {
            s.top().second = 1;
            s.push(std::make_pair(p->lchild, 0));
            p = s.top().first;
        }
        if (!s.top().first)
            s.pop();
        if (!s.empty())
        {
            if (s.top().second == 1)
            {
                p = s.top().first;
                s.top().second = 2;
                s.push(std::make_pair(p->rchild, 0));
            }
            else
            {
                p = s.top().first;
                s.pop();
                visit(p->val);
            }
        }
    }
}
//6.47
void floorTraverse(BiTree T, void (*visit)(TElemType e))
{
    std::queue<BiTree> s;
    if (T == NULL)
        return;
    s.push(T);
    while (!s.empty())
    {
        if (s.front()->lchild != NULL)
            s.push(s.front()->lchild);
        if (s.front()->rchild != NULL)
            s.push(s.front()->rchild);
        visit(s.front()->val);
        s.pop();
    }
}

void visit(TElemType e)
{
    std::cout << e << ' ';
}

int main()
{
    BiTree p = (BiTree)malloc(sizeof(BiTNode));
    p->val = 1;
    BiTree q = (BiTree)malloc(sizeof(BiTNode));
    q->val = 2;
    p->lchild = q;
    BiTree m = (BiTree)malloc(sizeof(BiTNode));
    BiTree temp = m;
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
    m = (BiTree)malloc(sizeof(BiTNode));
    temp->lchild = m;
    m->val = 6;
    m->lchild = NULL;
    m->rchild = NULL;
    m = (BiTree)malloc(sizeof(BiTNode));
    temp->rchild = m;
    m->val = 7;
    m->lchild = NULL;
    m->rchild = NULL;
    preorderTraverse(p, visit);
    putchar('\n');
    inorderTraverse(p, visit);
    putchar('\n');
    postorderTraverse(p, visit);
    putchar('\n');
    floorTraverse(p, visit);
    putchar('\n');
}