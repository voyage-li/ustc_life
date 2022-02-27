#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Polynomial //多项式
{
    int ratio;               //系数
    int n;                   //幂次
    struct Polynomial *next; //多项式的下一项
};

struct Polynomial *create() //输入数据
{
    struct Polynomial *head, *p, *rear;
    char c;
    head = p = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    scanf("%d %d", &head->ratio, &head->n);
    rear = p;
    while (1)
    {
        c = getchar();
        if (c != ' ') //判断结束
            break;
        p = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        scanf("%d %d", &p->ratio, &p->n);
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return head;
}

void arrange(struct Polynomial *head) //排序链表
{
    struct Polynomial *p, *q;
    p = head;
    int temp;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (q->n > p->n)
            {
                temp = q->n;
                q->n = p->n;
                p->n = temp;
                temp = q->ratio;
                q->ratio = p->ratio;
                p->ratio = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void kill(struct Polynomial *head) //释放链表
{
    struct Polynomial *p, *q;
    for (p = head; p != NULL; p = q)
    {
        q = p->next;
        free(p);
    }
}

struct Polynomial *add(struct Polynomial *head1, struct Polynomial *head2) //计算
{
    arrange(head1);
    arrange(head2);
    struct Polynomial *answer = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    struct Polynomial *p, *q, *temp, *rear = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    p = head1;
    q = head2;
    int a = 0;
    while (1)
    {
        temp = (struct Polynomial *)malloc(sizeof(struct Polynomial));
        /* 比较两个链表的值，然后将值赋给新的链表 */
        if (p == NULL && q == NULL)
        {
            rear->next = NULL;
            break;
        }
        else if (p != NULL && (q == NULL || p->n > q->n)) //防止对空的结构体指针取值
        {
            temp->ratio = p->ratio;
            temp->n = p->n;
            p = p->next;
        }
        else if (q != NULL && (p == NULL || p->n < q->n))
        {
            temp->ratio = q->ratio;
            temp->n = q->n;
            q = q->next;
        }
        else
        {
            temp->ratio = p->ratio + q->ratio;
            temp->n = p->n;
            p = p->next;
            q = q->next;
        }
        if (a == 0) //记录链表的头指针
        {
            answer = temp;
            rear = temp;
            a = 1;
        }
        rear->next = temp;
        rear = temp;
    }
    kill(head1);
    kill(head2);
    return answer;
}

void output(struct Polynomial *p)
{
    while (p != NULL)
    {
        if (p->ratio != 0) //运算之后有的项可能会变成0
            printf("%d %d ", p->ratio, p->n);
        p = p->next;
    }
}

int main()
{
    struct Polynomial *head1, *head2, *answer;
    head1 = create();
    head2 = create();
    answer = add(head1, head2);
    output(answer);
    kill(answer);
    return 0;
}