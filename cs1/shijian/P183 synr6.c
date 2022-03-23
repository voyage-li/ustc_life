#include<stdio.h>
#include<stdlib.h>
struct huan
{
    int number;
    struct huan *next;
};
struct huan *Creat()
{
    struct huan *head,*p,*rear;
    rear=head=NULL;
    for(int i=1;i<14;i++)
    {
        p=(struct huan*)malloc(sizeof(struct huan));
        p->number=i;
        if(rear!=NULL)
            rear->next=p;
        rear=p;
        if(i==1)
            head=p;
    }
    rear->next=head;
    return head;
}
int main()
{
    struct huan *head,*p,*q,*h;
    p=q=head=Creat();
    int i;
    for(i=1;;i++)
    {
        h=p;
        if(i%3==0)
            q->next=p->next;
        p=p->next;
        if(i%3==0)
            free(h);
        if(i!=1&&i%3!=0)
            q=q->next;
        if(q==p->next&&p==q->next)
            break;
    }
    printf("幸存者为%d %d\n",p->number,q->number);
    free(p);
    free(q);
}