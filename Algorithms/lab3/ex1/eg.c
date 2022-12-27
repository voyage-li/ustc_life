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
    struct PolyNode *head, *p;
    int a, e, n, i;
    head = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p = (struct PolyNode *)malloc(sizeof(struct PolyNode));
        scanf("%d%d", &a, &e);
        p->a = a, p->e = e;
        p->next = head;
        head = p;
    }
    return head;
}

struct PolyNode *mul(struct PolyNode *a, struct PolyNode *b)
{
}

void print(struct PolyNode *ans)
{
    struct PolyNode *p = ans;
    while (p)
    {
        printf("%d %d ", p->a, p->e);
        p = p->next;
    }
}