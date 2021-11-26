#include <bits/stdc++.h>
//直接使用stl库了
bool match(std::string s)
{
    std::stack<char> p;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            p.push(s[i]);
        else if (s[i] == ')')
        {
            if (p.top() == '(')
                p.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (p.top() == '{')
                p.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (p.top() == '[')
                p.pop();
            else
                return false;
        }
    }
    if (p.empty())
        return true;
    else
        return false;
}
int main()
{
    std::string s = "[321{}()43243{{{3241}}}[{342}]321]()";
    std::cout << match(s) << std::endl;
    s = "13421[656{76}([){{3213214{3}}}[{}]]]()";
    std::cout << match(s) << std::endl;
    return 0;
}