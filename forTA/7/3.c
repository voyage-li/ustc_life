#include <stdio.h>
#include <stdlib.h>
struct PolyNode
{
    int a;
    int e;
    struct PolyNode *next;
};

struct PolyNode *input();
struct PolyNode *mul(struct PolyNode *a, struct PolyNode *b);
void print(struct PolyNode *ans);

int main()
{
    struct PolyNode *a = input();
    struct PolyNode *b = input();
    print(mul(a, b));
    return 0;
}

struct PolyNode *input()
{
    int n;
    scanf("%d", &n);
    struct PolyNode *head, *p, *last;
    head = NULL;
    while (n--)
    {
        p = (struct PolyNode *)malloc(sizeof(struct PolyNode));
        scanf("%d %d", &p->a, &p->e);
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            last = head;
            continue;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
    return head;
}

struct PolyNode *mul(struct PolyNode *a, struct PolyNode *b)
{
    struct PolyNode *head, *p, *q, *last;
    head = NULL;
    struct PolyNode *m, *n, *tmp;
    m = a;
    n = b;
    while (m != NULL)
    {
        n = b;
        while (n != NULL)
        {
            p = (struct PolyNode *)malloc(sizeof(struct PolyNode));
            p->a = m->a * n->a;
            p->e = m->e + n->e;
            p->next = NULL;
            if (head == NULL)
            {
                head = p;
                last = p;
            }
            else
            {
                tmp = head;
                while (tmp != NULL)
                {
                    if (tmp->e == p->e)
                    {
                        tmp->a += p->a;
                        free(p);
                        break;
                    }
                    tmp = tmp->next;
                }
                if (tmp == NULL)
                {
                    last->next = p;
                    last = p;
                }
            }
            n = n->next;
        }
        m = m->next;
    }
    // sort
    p = head;
    last = NULL;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        q = head;
        while (q->next != NULL)
        {
            tmp = q->next;
            if (q->e < tmp->e)
            {
                flag = 1;
                if (last == NULL)
                {
                    q->next = tmp->next;
                    tmp->next = q;
                    head = tmp;
                }
                else
                {
                    q->next = tmp->next;
                    last->next = tmp;
                    tmp->next = q;
                }
                last = tmp;
            }
            else
            {
                last = q;
                q = tmp;
                tmp = tmp->next;
            }
        }
        last = NULL;
    }
    return head;
}

void print(struct PolyNode *ans)
{
    while (ans != NULL)
    {
        printf("%d %d ", ans->a, ans->e);
        ans = ans->next;
    }
}