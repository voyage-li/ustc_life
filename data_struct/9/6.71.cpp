#include <bits/stdc++.h>
#define ElemType char
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
    CSNode() : firstchild(nullptr), nextsibling(nullptr){};
} CSNode, *CSTree;
//6.68
CSTree initCSTree()
{
    std::queue<std::pair<CSTree, int>> ss;
    std::map<CSTree, CSTree> tail;
    CSTree head = (CSTree)malloc(sizeof(CSNode));
    int deg;
    std::cin >> head->data >> deg;
    tail[head] = nullptr;
    ss.push(std::make_pair(head, deg));
    while (!ss.empty())
    {
        while (!ss.empty() && ss.front().second == 0)
            ss.pop();
        if (ss.empty())
            break;
        CSTree h = ss.front().first;
        CSTree p = (CSTree)malloc(sizeof(CSNode));
        std::cin >> p->data >> deg;
        ss.push(std::make_pair(p, deg));
        tail[p] = nullptr;
        ss.front().second -= 1;
        if (tail[h] == nullptr)
        {
            h->firstchild = p;
            tail[h] = p;
        }
        else
        {
            tail[h]->nextsibling = p;
            tail[h] = p;
        }
    }
    return head;
}
//6.71
void print_tree(CSTree head, int n)
{
    if (head == nullptr)
        return;
    std::string blank = "|   |";
    for (int i = 0; i < n; i++)
        std::cout << blank;
    std::cout << "| " << head->data << " |" << std::endl;
    print_tree(head->firstchild, n + 1);
    print_tree(head->nextsibling, n);
}
int main()
{
    freopen("data.txt", "r", stdin);
    CSTree head = initCSTree();
    print_tree(head, 0);
    fclose(stdin);
    return 0;
}