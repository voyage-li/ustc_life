#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cnode
{
    char *name;          //乘客姓名
    char *idcard;        //证件号码
    int seatno;          //座位号
    struct cnode *clink; //下一乘客指针
};

struct pnode
{
    int no;              //航班号
    char *destin;        //终到站
    int limit, rest;     //总座位数、余票额
    struct cnode *clist; //乘客名单
    struct pnode *plink; //下一班指针
};

struct pnode *airline;

void booktickets();
void unbooktickets();
void search_airline();
void add_airplane();
void remove_ariplane();

int main()
{

    while (1)
    {
        printf("========菜单=========\n");
        printf("|0. 退出程序        |\n");
        printf("|1. 订票            |\n");
        printf("|2. 退票            |\n");
        printf("|3. 查询            |\n");
        printf("|4. 添加航班        |\n");
        printf("|5. 移除航班        |\n");
        printf("=====================\n");
        int select = 0;
        scanf("%d", &select);
        switch (select)
        {
        case 0:
            exit(0);
            break;
        case 1:
            booktickets();
            break;
        case 2:
            unbooktickets();
            break;
        case 3:
            search_airline();
            break;
        case 4:
            add_airplane();
            break;
        case 5:
            remove_ariplane();
            break;
        default:
            break;
        }
    }
    return 0;
}

void booktickets()
{
    char *this_name = (char *)malloc(sizeof(char) * 20);
    char *this_idcard = (char *)malloc(sizeof(char) * 20);
    printf("请输入用户信息:\n");
    printf("输入用户姓名:  ");
    scanf("%s", this_name);
    printf("输入证件号:  ");
    scanf("%s", this_idcard);
    printf("输入航班号:  ");
    int num;
    scanf("%d", &num);
    struct pnode *p = airline;
    while (p)
    {
        if (p->no == num)
            break;
        p = p->plink;
    }
    if (p == NULL)
    {
        printf("没有查询到!\n");
        return;
    }
    if (p->rest > 0)
    {
        printf("成功预定!\n");
        struct cnode *q = p->clist;
        struct cnode *s = (struct cnode *)malloc(sizeof(struct cnode));
        s->idcard = this_idcard;
        s->name = this_name;
        s->clink = NULL;
        p->rest = p->rest - 1;
        s->seatno = p->limit - p->rest;
        printf("你的座位是: %d\n", s->seatno);
        if (q == NULL)
        {
            p->clist = s;
            return;
        }
        while (q->clink)
            q = q->clink;
        q->clink = s;
    }
}
void unbooktickets()
{
    int num, seatnum;
    printf("请输入航班号:  \n");
    scanf("%d", &num);
    printf("请输入座位号:  \n");
    scanf("%d", &seatnum);
    struct pnode *p = airline;
    while (p)
    {
        if (p->no == num)
            break;
        p = p->plink;
    }
    struct cnode *q = p->clist;
    struct cnode *last;
    while (q)
    {
        if (q->seatno == seatnum)
            break;
        last = q;
        q = q->clink;
    }
    if (q == p->clist)
        p->clist = q->clink;
    else
    {
        last->clink = q->clink;
    }
    p->rest = p->rest + 1;
}

void search_airline()
{
    printf("选择查询方式:\n");
    printf("1. 查询目的地\n");
    printf("2. 查询航班号\n");
    int select = 0;
    scanf("%d", &select);
    while (select != 1 && select != 2)
    {
        printf("输入错误!\n");
        scanf("%d", &select);
    }
    if (select == 1)
    {
        printf("输入需要查询的目的地:\n");
        char aim[30];
        scanf("%s", aim);
        struct pnode *p = airline;
        while (p)
        {
            if (strcmp(p->destin, aim) == 0)
                break;
            p = p->plink;
        }
        if (p == NULL)
        {
            printf("没有查询到!\n");
            return;
        }
        printf("航班号: %d\n", p->no);
        printf("终到站: %s\n", p->destin);
        printf("余票/总票: %d/%d\n", p->rest, p->limit);
    }
    else
    {
        printf("输入需要查询的航班号:\n");
        int num;
        scanf("%d", &num);
        struct pnode *p = airline;
        while (p)
        {
            if (p->no == num)
                break;
            p = p->plink;
        }
        if (p == NULL)
        {
            printf("没有查询到!\n");
            return;
        }
        printf("航班号: %d\n", p->no);
        printf("终到站: %s\n", p->destin);
        printf("余票/总票: %d/%d\n", p->rest, p->limit);
        printf("乘客:\n");
        struct cnode *q = p->clist;
        while (q)
        {
            printf("\n\n乘客姓名:  %s\n", q->name);
            printf("证件号码:  %s\n", q->idcard);
            printf("座位号:  %d\n", q->seatno);
            q = q->clink;
        }
    }
}

void add_airplane()
{
    struct pnode *p = airline;
    struct pnode *last = NULL;
    while (p)
    {
        last = p;
        p = p->plink;
    }
    p = (struct pnode *)malloc(sizeof(struct pnode));
    int plane_num;
    char *destination = (char *)malloc(sizeof(char) * 30);
    int limit;
    printf("请输入航班号:  \n");
    scanf("%d", &plane_num);
    printf("请输入终到站:  ");
    scanf("%s", destination);
    printf("请输入座位数:  ");
    scanf("%d", &limit);
    p->no = plane_num;
    p->destin = destination;
    p->limit = limit;
    p->rest = limit;
    p->clist = NULL;
    p->plink = NULL;
    if (last == NULL)
        airline = p;
    else
        last->plink = p;
}
void remove_ariplane()
{
    printf("请输入航班号:  ");
    int num;
    scanf("%d", &num);
    struct pnode *p = airline;
    struct pnode *last = NULL;
    while (p)
    {
        if (p->no == num)
            break;
        else
        {
            last = p;
            p = p->plink;
        }
    }
    if (p == NULL)
    {
        printf("没有查询到此航班!\n");
        return;
    }
    if (last == NULL)
    {
        airline = p->plink;
        free(p);
    }
    else
    {
        last->plink = p->plink;
        free(p);
    }
    printf("成功删除!\n");
}
