#include <bits/stdc++.h>

struct PolyNode
{
    /* data */
    int a, e;
    struct PolyNode *next;
};

struct PolyNode *mul(struct PolyNode *a, struct PolyNode *b)
{
    struct PolyNode *pa = a, *pb = b, *head, *pc, *tail, *c;
    head = NULL, tail = NULL;
    while (pa)
    {
        pb = b;
        while (pb)
        {
            pc = (struct PolyNode *)malloc(sizeof(struct PolyNode));
            pc->a = pa->a * pb->a, pc->e = pa->e + pb->e;
            pc->next = head;
            head = pc;
            pb = pb->next;
        }
        pa = pa->next;
    }
    c = pc;
    while (pc != tail)
    {
        while (pc->next != tail)
        {
            if (pc->e < pc->next->e)
            {
                int temp = pc->a;
                pc->a = pc->next->a;
                pc->next->a = temp;
                int temp2 = pc->e;
                pc->e = pc->next->e;
                pc->next->e = temp2;
            }
            pc = pc->next;
        }
        tail = pc;
        pc = c;
    }
    c = pc;
    while (pc != tail)
    {
        while (pc->next != tail)
        {
            if (pc->e == pc->next->e)
            {
                pc->next->a += pc->a;
                c->next = pc->next;
            }
            pc = pc->next;
        }
    }
    return c;
}