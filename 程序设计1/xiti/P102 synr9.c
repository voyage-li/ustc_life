#include<stdio.h>
#include<stdlib.h>
int n;
struct huan
{
    int number;
    struct huan *next;
};
struct huan *Creat()
{
    struct huan *head,*p,*rear;
    rear=head=NULL;
    printf("请输入链表的元素多少：");
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    {
        p=(struct huan*)malloc(sizeof(struct huan));
        p->number=i;
        if(rear!=NULL)
            rear->next=p;
        rear=p;
        if(i==1)
            head=p;
    }
    p->next=NULL;
    return head;
}
void shuchu(struct huan *head)
{
    struct huan *p;
    p=head;
    for(int i=0;p!=NULL;i++)
    {
        printf("%2d ",p->number);
        p=p->next;
    }
}
struct huan *reverse(struct huan *head,struct huan *linshi)
{
    struct huan *p,*q;
    p=head;
    q=linshi;
    if(q==NULL)
        head=p;
    else
    {
        linshi=q->next;
        q->next=p;
        head=reverse(q,linshi);
    }
    if(p->next==q)
        p->next=NULL;
    return head;
}
int main()
{
    struct huan *head;
    head=Creat();
    shuchu(head);
    printf("\n");
    head=reverse(head,head->next);
    shuchu(head);
    return 0;
}