#include <bits/stdc++.h>

struct ListNode
{
    float num;
    float deg;
    struct ListNode *next;
};

std::map<int, struct ListNode *> map;
int num_L = 0;

void begin();                       //菜单
void insert_l();                    //输入
void print_l();                     //输出所有已输入多项式
void plus_l();                      //加法
void minus_l();                     //减法
void multiply_L();                  //乘法
void der_l();                       //导数
void end_delete();                  //结束清空数据
void f_x();                         //多项式在x的值
void print_all();                   //直接输出（不暂停）
void print_now(struct ListNode *p); //输出一个多项式

int main()
{
    begin();
    return 0;
}

void begin()
{
    system("clear");
    std::cout << "        多项式处理        " << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "|| 1. 输入多项式          ||" << std::endl;
    std::cout << "|| 2. 展示多项式          ||" << std::endl;
    std::cout << "|| 3. 多项式加法          ||" << std::endl;
    std::cout << "|| 4. 多项式减法          ||" << std::endl;
    std::cout << "|| 5. 多项式乘法          ||" << std::endl;
    std::cout << "|| 6. 多项式导数          ||" << std::endl;
    std::cout << "|| 7. 多项式在x的值       ||" << std::endl;
    std::cout << "|| 8. 退出程序            ||" << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "请选择操作：" << std::endl;
    int select = 0;
    std::cin >> select;
    system("clear");
    switch (select)
    {
    case 1:
        insert_l();
        break;
    case 2:
        print_l();
        break;
    case 3:
        plus_l();
        break;
    case 4:
        minus_l();
        break;
    case 5:
        multiply_L();
        break;
    case 6:
        der_l();
        break;
    case 7:
        f_x();
        break;
    case 8:
        end_delete();
        break;
    default:
        std::cout << "请重新输入！" << std::endl;
        begin();
        break;
    }
}

void insert_l()
{
    system("clear"); //清屏
    std::cout << "请输入多项式：（输入格式为 系数 幂次，输入0 0结束输入）" << std::endl;
    num_L++;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q, *last;
    float a, b;
    std::cin >> a >> b;
    head->num = a;
    head->deg = b;
    head->next = NULL; //初始化表头

    while (1)
    {
        std::cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        q = head;
        p->num = a;
        p->deg = b;
        p->next = NULL;
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
                continue;
            }
            last->next = p;
            p->next = q;
        }
        else //在表尾插入p结点
            last->next = p;
    }
    map[num_L] = head;
    print_now(map[num_L]);
    getchar();
    getchar();
    begin();
}

void print_l()
{
    system("clear");
    print_all();
    getchar();
    getchar();
    begin();
}

void plus_l()
{
    system("clear");
    print_all();
    std::cout << "请输入需要相加的两个多项式的编号 最后的答案将存储在尚未编号的多项式中" << std::endl;
    int plus1, plus2;
    std::cin >> plus1 >> plus2;
    if (plus1 > num_L || plus2 > num_L || plus1 < 1 || plus2 < 1)
    {
        std::cout << "需要处理的多项式尚未初始化！" << std::endl;
        getchar();
        getchar();
        begin();
    }
    num_L++;
    struct ListNode *head, *l1, *l2, *last;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    last = head;
    l1 = map[plus1];
    l2 = map[plus2];
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
    map[num_L] = head->next;
    free(head);
    print_now(map[plus1]);
    print_now(map[plus2]);
    std::cout << "answer:" << std::endl;
    print_now(map[num_L]);
    getchar();
    getchar();
    begin();
}

void minus_l()
{
    system("clear");
    print_all();
    std::cout << "请输入需要相减的多项式编号被减数在前 最后的答案将存储在尚未编号的多项式中" << std::endl;
    int minus1, minus2;
    std::cin >> minus1 >> minus2;
    if (minus1 > num_L || minus2 > num_L || minus1 < 1 || minus2 < 1)
    {
        std::cout << "需要处理的多项式尚未初始化！" << std::endl;
        getchar();
        getchar();
        begin();
    }
    num_L++;
    struct ListNode *head, *l1, *l2, *last;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->num = 0;
    head->deg = 0;
    head->next = NULL;
    last = head;
    l1 = map[minus1];
    l2 = map[minus2];
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
        map[num_L] = head->next;
        free(head);
    }
    else
        map[num_L] = head;
    print_now(map[minus1]);
    print_now(map[minus2]);
    std::cout << "answer:" << std::endl;
    print_now(map[num_L]);
    getchar();
    getchar();
    begin();
}

void multiply_L()
{
    system("clear");
    print_all();
    std::cout << "请输入需要相乘的多项式编号 最后的答案将存储在尚未编号的多项式中" << std::endl;
    int mul1, mul2;
    std::cin >> mul1 >> mul2;
    if (mul1 > num_L || mul2 > num_L || mul1 < 1 || mul2 < 1)
    {
        std::cout << "需要处理的多项式尚未初始化！" << std::endl;
        getchar();
        getchar();
        begin();
    }
    num_L++;
    struct ListNode *l1, *l2, *q, *last, *head;
    int ishead = 0;
    //循环每一项相乘 用和 insert_l()函数相同的方法直接插入新链表
    for (l1 = map[mul1]; l1; l1 = l1->next)
        for (l2 = map[mul2]; l2; l2 = l2->next)
        {
            struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->num = l1->num * l2->num;
            p->deg = l1->deg + l2->deg;
            p->next = NULL;
            if (p->num == 0)
            {
                free(p);
                continue;
            }
            if (!ishead)
            {
                head = p;
                last = head;
                ishead = 1;
                continue;
            }
            q = head;
            while (q && p->deg < q->deg)
            {
                last = q;
                q = q->next;
            }
            if (q == head)
            {
                if (q->deg == p->deg)
                {
                    q->num += p->num;
                    free(p);
                    if (q->num == 0)
                    {
                        head = q->next;
                        free(q);
                    }
                    continue;
                }
                p->next = head;
                head = p;
            }
            else if (q)
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
                    continue;
                }
                last->next = p;
                p->next = q;
            }
            else
                last->next = p;
        }
    if (ishead == 0)
    {
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->num = 0;
        head->deg = 0;
        head->next = NULL;
    }
    map[num_L] = head;
    print_now(map[mul1]);
    print_now(map[mul2]);
    std::cout << "answer:" << std::endl;
    print_now(map[num_L]);
    getchar();
    getchar();
    begin();
}

void der_l()
{
    system("clear");
    print_all();
    std::cout << "请输入需要求导的多项式编号 最后的答案将存储在尚未编号的多项式中" << std::endl;
    int der;
    std::cin >> der;
    if (der > num_L || der < 1)
    {
        std::cout << "需要处理的多项式尚未初始化！" << std::endl;
        getchar();
        getchar();
        begin();
    }
    num_L++;
    struct ListNode *head, *p, *q, *last;
    int ishead = 0;
    p = map[der];
    while (p)
    {
        q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->num = p->num * p->deg;
        q->deg = p->deg - 1;
        q->next = NULL;
        if (q->num == 0)
        {
            free(q);
            p = p->next;
            continue;
        }
        if (p == map[der])
        {
            head = q;
            ishead = 1;
        }
        else
            last->next = q;
        last = q;
        p = p->next;
    }
    if (ishead == 1)
        map[num_L] = head;
    else
    {
        head = (struct ListNode *)malloc(sizeof(struct ListNode));
        head->deg = 0;
        head->num = 0;
        head->next = NULL;
    }
    print_now(map[der]);
    std::cout << "answer:" << std::endl;
    print_now(map[num_L]);
    getchar();
    getchar();
    begin();
}

void print_now(struct ListNode *p)
{
    if (p == NULL)
        std::cout << "0";
    else
        while (p)
        {
            if (p->deg != 0)
            {
                if (fabs(p->num) != 1)
                    std::cout << p->num;
                else if (p->num == -1)
                    putchar('-');
                if (p->deg == 1)
                    std::cout << 'x';
                else
                {
                    std::cout << "x^";
                    if (p->deg < 0)
                        std::cout << '(' << p->deg << ')';
                    else
                        std::cout << p->deg;
                }
            }
            else
                std::cout << p->num;
            if (p->next)
            {
                if (p->next->num > 0)
                    std::cout << '+';
                p = p->next;
            }
            else
                break;
        }
    putchar('\n');
}

void f_x()
{
    system("clear");
    print_all();
    std::cout << "请输入需要计算的多项式编号 以及x的值" << std::endl;
    int num;
    float x;
    std::cin >> num >> x;
    if (num > num_L || num < 1)
    {
        std::cout << "需要处理的多项式尚未初始化！" << std::endl;
        getchar();
        getchar();
        begin();
    }
    float answer = 0;
    struct ListNode *p = map[num];
    while (p)
    {
        answer += p->num * pow(x, p->deg);
        p = p->next;
    }
    print_now(map[num]);
    std::cout << "F" << num << '(' << x << ")=";
    std::cout << answer << std::endl;
    getchar();
    getchar();
    begin();
}

void end_delete()
{
    struct ListNode *p, *q;
    for (int i = 1; i <= num_L; i++)
    {
        p = map[i];
        while (p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
    }
    std::cout << "已销毁多项式存储数据并退出" << std::endl;
    exit(0);
}

void print_all()
{
    for (int i = 1; i <= num_L; i++)
    {
        std::cout << std::right << std::setw(2) << i;
        std::cout << "| ";
        print_now(map[i]);
    }
}
