#include <bits/stdc++.h>

#define AtomType std::string

typedef enum
{
    ATOM,
    LIST
} ElemTag;

typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp;
            struct GLNode *tp;
        } ptr;
    };
    GLNode() : atom("") {}
} * GList;

GList reverse(GList L)
{
    if (L == NULL)
        return L;
    if (L->tag == ATOM)
    {
        return L;
    }
    else
    {
        struct GLNode *p;
        p = L->ptr.hp;
        L->ptr.hp = reverse(L->ptr.tp);
        L->ptr.tp = reverse(p);
        return L;
    }
}

//构建广义表
void sever(std::string &str, std::string &hstr)
{
    int l = str.length();
    int i;
    int flag = 0;
    std::stack<char> s;
    for (i = 0; i < l; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
            s.pop();
        else if (str[i] == ',')
        {
            if (s.empty())
            {
                hstr = str.substr(0, i);
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        hstr = str;
        str.clear();
    }
    else
        str = str.substr(i + 1, str.length());
    //这里不需要考虑长度 如果到末尾可以自动结束
}
void Create_list(GList &L, std::string s)
{
    std::string temp = "()";
    if (s.compare(temp) == 0)
        L = NULL;
    else
    {
        if (!(L = (GList)malloc(sizeof(GLNode))))
            exit(1);
        if (s.length() == 1)
        {
            L->tag = ATOM;
            L->atom = s;
        }
        else
        {
            L->tag = LIST;
            GList p = L;
            GList q;
            //脱掉外层括号
            std::string sub = s.substr(1, s.length() - 2);
            do
            {
                std::string hsub;
                sever(sub, hsub);
                Create_list(p->ptr.hp, hsub);
                q = p;
                if (!sub.empty())
                {
                    if (!(p = (GList)malloc(sizeof(GLNode))))
                        exit(1);
                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            } while (!sub.empty());
            q->ptr.tp = NULL;
        }
    }
}

void output(GList L)
{
    if (L == NULL)
        return;
    else if (L->tag == ATOM)
        std::cout << L->atom;
    else
    {
        putchar('(');
        output(L->ptr.hp);
        output(L->ptr.tp);
        putchar(')');
        putchar(',');
    }
}

int main()
{
    GList L;
    Create_list(L, "(a,((b,c),()),(((d),e),f))");
    reverse(L);
    output(L);
    std::cout << " ";
}