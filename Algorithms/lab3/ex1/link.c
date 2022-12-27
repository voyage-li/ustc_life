#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};

struct Node *Insert1(struct Node *head, int val)
{
    //头插法
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->val = val;
    p->next = NULL;
    if (head == NULL)
        return p;
    else
    {
        p->next = head;
        head = p;
    }
    return head;
}

struct Node *Insert2(struct Node *head, int val)
{
    //尾插法
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->val = val;
    p->next = NULL;
    if (head == NULL)
        return p;
    else
    {
        struct Node *q = head;
        while (q->next)
            q = q->next;
        q->next = p;
    }
    return head;
}

struct Node *Insert(struct Node *head, int val)
{
    //在有序链表中插入
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->val = val;
    p->next = NULL;
    if (head == NULL)
        return p;
    else
    {
        struct Node *q = head, *last;
        while (q && q->val < p->val)
        {
            last = q;
            q = q->next;
        }
        if (head == q)
        {
            head->next = p;
            head = p;
        }
        else
        {
            p->next = last->next;
            last->next = p;
        }
    }
    return head;
}

struct Node *Delete(struct Node *head, int val)
{
    //删除制定值的节点
    if (head == NULL)
        return head;
    struct Node *p = head, *last;
    while (p && p->val != val)
    {
        last = p;
        p = p->next;
    }
    if (p == NULL)
        return head;
    if (head == p)
        return p->next;
    else
        last->next = p->next;
    return head;
}

void print(struct Node *head)
{
    //输出
    while (head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = Insert1(NULL, 5);
    head = Insert1(head, 3);
    head = Insert1(head, 2);
    head = Insert1(head, 1);
    head = Insert2(head, 6);
    head = Insert2(head, 7);
    print(head);
    head = Insert(head, 4);
    print(head);
    head = Delete(head, 4);
    print(head);
    return 0;
}