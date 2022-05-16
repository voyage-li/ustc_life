#include <iostream>
struct people
{
    int num;
    int data;
    struct people *next;
};

int main()
{
    int l;
    int m;
    std::cin >> l;
    std::cin >> m;

    struct people *head, *last;
    for (int i = 0; i < l; i++)
    {
        struct people *p = (struct people *)malloc(sizeof(struct people));
        std::cin >> p->data;
        p->num = i + 1;
        if (i == 0)
            head = p;
        else
            last->next = p;
        last = p;
    }
    last->next = head;
    struct people *p = head;
    while (1)
    {
        if (m != 1)
        {
            m--;
            last = p;
            p = p->next;
        }
        else
        {
            std::cout << p->num << ' ';
            m = p->data;
            last->next = p->next;
            p = p->next;
        }
        if (p->next == p)
        {
            std::cout << p->num;
            break;
        }
    }
    putchar('\n');
    return 0;
}