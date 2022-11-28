#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
struct node *head = NULL;

struct node *CreatelistF()
{
    struct node *head, *p;
    int num;

    head = NULL;
    printf("Input a integer: ");
    scanf("%d", &num);
    while (num != 0)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->num = num;
        p->next = head;
        head = p;
        printf("Input a integer: ");
        scanf("%d", &num);
    }

    return head;
}
void PrintList(struct node *head)
{
    struct node *p = head;
    while (p)
    {
        printf("%d\n", p->num);
        p = p->next;
    }
}
struct node *InsertList(struct node *head, struct node *q)
{
    struct node *p;

    if (!head)
    {
        head = q;
        return head;
    }

    if (head->num > q->num)
    {
        q->next = head;

        head = q;

        return head;
    }

    p = head;

    while (p->next && p->next->num < q->num)
        p = p->next;

    q->next = p->next;
    p->next = q;

    return head;
}
struct node *DeLeteList(struct node *head, int num)
{

    struct node *p, *q;

    if (head && head->num == num)
    {

        p = head;

        head = p->next;

        free(p);

        return head;
    }

    q = p = head;

    while (p && p->num != num)
    {
        q = p;

        p = p->next;
    }

    if (p)
    {

        q->next = p->next;

        free(p);

        return head;
    }
    printf("Not Found!\n");
    return head;
}

int main()
{

    struct node *head, *ps;

    int num;

    printf("Create Linklist: \n");

    head = CreateListF();

    printf("Print Linklist: \n");

    PrintList(head);

    ps = (struct node *)malloc(sizeof(struct node));

    printf("Insert a integer: ");
    scanf("%d", &ps->num);

    head = InsertList(head, ps);
    printf("Print Linklist: \n");
    PrintList(head);

    printf("Delete a integer: ");
    scanf("%d", &num);

    head = DeLeteList(head, num);
    printf("Print Linklist: \n");
    PrintList(head);

    return 0;
}