#include <bits/stdc++.h>
#define ElemType char
typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
    CSNode() : firstchild(nullptr), nextsibling(nullptr){};
} CSNode, *CSTree;
CSTree init(std::string s)
{
    int l = s.length();
    CSTree head = new CSNode;
    head->data = s[0];
    head->firstchild = nullptr;
    head->nextsibling = nullptr;
    if (l == 1)
        return head;
    std::stack<char> p;
    int index = 1;
    if (s[index] == '(')
    {
        p.push(s[index++]);
        while (!p.empty())
        {
            if (s[index] == '(')
                p.push(s[index]);
            else if (s[index] == ')')
                p.pop();
            index++;
        }
        head->firstchild = init(s.substr(2, index - 3));
        if (index != l)
            head->nextsibling = init(s.substr(index + 1, l - 1 - index));
    }
    else
        head->nextsibling = init(s.substr(2, l - 2));
    return head;
}

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
    std::string s = "R(A(D,E),B,C(F(G,H,K)))";
    CSTree head = init(s);
    print_tree(head, 0);
    return 0;
}
