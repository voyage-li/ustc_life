#include <bits/stdc++.h>
#define size 5
struct HString
{
    char arr[size];
    struct HString *next;
};
struct LString
{
    struct HString *head, *tail;
    int length;
};

void insert(struct LString &l1, struct LString &l2, char c);

void out(struct LString &l1)
{
    struct HString *p = l1.head;
    while (p)
    {
        for (int i = 0; i < size; i++)
        {
            if (p->arr[i] == '#')
                continue;
            else
                std::cout << p->arr[i] << '|';
        }
        p = p->next;
    }
    putchar('\n');
}

int main()
{
    LString l1, l2;
    struct HString *last;
    for (int i = 0; i < 3; i++)
    {
        struct HString *p = (struct HString *)malloc(sizeof(struct HString));
        p->arr[0] = '+';
        p->arr[1] = '-';
        p->arr[2] = '*';
        p->arr[3] = '/';
        p->arr[4] = 'o';
        if (i == 0)
            l1.head = p;
        else
            last->next = p;
        last = p;
        if (i == 2)
        {
            p->next = NULL;
        }
    }
    l1.tail = last;
    for (int i = 0; i < 2; i++)
    {
        struct HString *p = (struct HString *)malloc(sizeof(struct HString));
        p->arr[0] = '0';
        p->arr[1] = '1';
        p->arr[2] = '2';
        p->arr[3] = '3';
        p->arr[4] = '4';
        if (i == 0)
            l2.head = p;
        else
            last->next = p;
        last = p;
        if (i == 1)
            p->next = NULL;
    }
    l2.tail = last;
    insert(l1, l2, 'o');
    out(l1);
}
void insert(struct LString &l1, struct LString &l2, char c)
{
    struct HString *head1 = l1.head;
    struct HString *head2 = l2.head;
    int flag = 0;
    while (head1)
    {
        for (int i = 0; i < size; i++)
        {
            if (head1->arr[i] == '#')
                continue;
            if (head1->arr[i] == c)
            {
                flag = i;
                break;
            }
        }
        if (flag != 0)
            break;
        else
            head1 = head1->next;
    }
    if (flag == 0)
    {
        l1.tail->next = l2.head;
        l1.tail = l2.tail;
    }
    else if (flag == size - 1)
    {
        l2.tail->next = head1->next;
        head1->next = l2.head;
        if (l2.tail->next == NULL)
            l1.tail = l2.tail;
    }
    else
    {
        struct HString *p = (struct HString *)malloc(sizeof(struct HString));
        for (int i = flag + 1; i < size; i++)
        {
            p->arr[i - flag - 1] = head1->arr[i];
            head1->arr[i] = '#';
        }
        for (int i = size - flag - 1; i < size; i++)
            p->arr[i] = '#';
        p->next = head1->next;
        head1->next = head2;
        l2.tail->next = p;
        if (p->next == NULL)
            l1.tail = p;
    }
}