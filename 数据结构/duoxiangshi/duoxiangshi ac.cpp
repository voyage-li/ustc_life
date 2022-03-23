#include <bits/stdc++.h>
struct ListNode
{
    float num;
    int deg;
    struct ListNode *next;
};

struct ListNode *insert();
struct ListNode *plus(struct ListNode *l1, struct ListNode *l2);
struct ListNode *minus(struct ListNode *l1, struct ListNode *l2);
void print_l(struct ListNode *head);

int main()
{
    struct ListNode *head1 = NULL, *head2 = NULL;
    head1 = insert();
    head2 = insert();
    int key;
    std::cin >> key;
    if (key)
        print_l(minus(head1, head2));
    else
        print_l(plus(head1, head2));
    return 0;
}
struct ListNode *insert()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q, *last = NULL;
    float a;
    char c;
    int b = 0;
    std::cin >> a;
    if (a != 0)
        std::cin >> b;
    head->num = a;
    head->deg = b;
    head->next = NULL; //初始化表头
    if (head->num == 0 && head->next == 0)
        return head;
    c = getchar();
    if (c == '\n')
        return head;
    while (1)
    {
        std::cin >> a >> b;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = head;
        p->num = a;
        p->deg = b;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            c = getchar();
            if (c == '\n')
                break;
            continue;
        }
        while (q && p->deg < q->deg)
        {
            last = q;
            q = q->next;
        }
        if (q == head) //插入节点在表头
        {
            if (q->deg == p->deg) //输入的节点幂次已经存在直接加上
            {
                q->num += p->num;
                free(p);
                if (q->num == 0) //相加为0直接删除节点
                {
                    head = q->next;
                    free(q);
                }
                c = getchar();
                if (c == '\n')
                    break;
                continue;
            }
            p->next = head;
            head = p;
        }
        else if (q) //在q之前插入p节点
        {
            if (q->deg == p->deg)
            {
                q->num += p->num;
                free(p);
                if (q->num == 0)
                {
                    last->next = q->next;
                    free(q);
                }
                c = getchar();
                if (c == '\n')
                    break;
                continue;
            }
            last->next = p;
            p->next = q;
        }
        else //在表尾插入p结点
            last->next = p;
        c = getchar();
        if (c == '\n')
            break;
    }
    return head;
}
struct ListNode *plus(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head, *last;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    last = head;
    while (l1 || l2)
    {
        //双指针依次相加
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        if (l1 && !l2)
        {
            p->num = l1->num;
            p->deg = l1->deg;
            l1 = l1->next;
        }
        else if (l2 && !l1)
        {
            p->num = l2->num;
            p->deg = l2->deg;
            l2 = l2->next;
        }
        else if (l1->deg > l2->deg)
        {
            p->num = l1->num;
            p->deg = l1->deg;
            l1 = l1->next;
        }
        else if (l1->deg == l2->deg)
        {
            if (l1->num + l2->num == 0)
            {
                free(p);
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            p->num = l1->num + l2->num;
            p->deg = l1->deg;
            l1 = l1->next;
            l2 = l2->next;
        }
        else
        {
            p->num = l2->num;
            p->deg = l2->deg;
            l2 = l2->next;
        }
        if (p->num == 0)
        {
            free(p);
            continue;
        }
        last->next = p;
        last = p;
    }
    last = head->next;
    free(head);
    return last;
}
struct ListNode *minus(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head, *last;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->num = 0;
    head->deg = 0;
    head->next = NULL;
    last = head;
    while (l1 || l2)
    {
        //双指针依次相减
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        if (l1 && !l2)
        {
            p->num = l1->num;
            p->deg = l1->deg;
            l1 = l1->next;
        }
        else if (l2 && !l1)
        {
            p->num = -l2->num;
            p->deg = l2->deg;
            l2 = l2->next;
        }
        else if (l1->deg > l2->deg)
        {
            p->num = l1->num;
            p->deg = l1->deg;
            l1 = l1->next;
        }
        else if (l1->deg == l2->deg)
        {
            if (l1->num - l2->num == 0)
            {
                free(p);
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            p->num = l1->num - l2->num;
            p->deg = l1->deg;
            l1 = l1->next;
            l2 = l2->next;
        }
        else
        {
            p->num = -l2->num;
            p->deg = l2->deg;
            l2 = l2->next;
        }
        if (p->num == 0)
        {
            free(p);
            continue;
        }
        last->next = p;
        last = p;
    }
    if (head->next)
    {
        last = head->next;
        free(head);
    }
    else
        last = head;
    return last;
}
void print_l(struct ListNode *head)
{
    if (head == NULL || (head->deg == 0 && head->num == 0))
    {
        std::cout << "0.0" << std::endl;
        return;
    }
    while (head)
    {
        printf("%.1f %d", head->num, head->deg);
        head = head->next;
        if (head)
            putchar(' ');
        else
            putchar('\n');
    }
}