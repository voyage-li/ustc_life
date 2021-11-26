#include <bits/stdc++.h>

float akm(float m, float n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return akm(m - 1, 1);
    else
        return akm(m - 1, akm(m, n - 1));
}

//注意用-1标记 表示访问该栈顶元素时需要继续计算 并不能直接等于号返回
int akml(int m, int n)
{
    std::stack<std::pair<int, int>> s;
    s.push(std::make_pair(m, n));
    std::pair<int, int> tmp;
    int lasts = 0;
    while (!s.empty())
    {
        tmp = s.top();
        if (tmp.first == 0 && tmp.second != -1)
        {
            lasts = tmp.second + 1;
            s.pop();
            while (1)
            {
                if (!s.empty() && s.top().second != -1)
                    s.pop();
                else if (s.empty())
                    return lasts;
                else
                {
                    tmp = s.top();
                    s.pop();
                    s.push(std::make_pair(tmp.first, lasts));
                    break;
                }
            }
        }
        else if (tmp.second == 0 && tmp.first > 0)
            s.push(std::make_pair(tmp.first - 1, 1));
        else if (tmp.second > 0 && tmp.first > 0)
        {
            s.push(std::make_pair(tmp.first - 1, -1));
            s.push(std::make_pair(tmp.first, tmp.second - 1));
        }
    }
    return -1;
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::cout << akm(m, n) << std::endl;
    std::cout << akml(m, n) << std::endl;
    return 0;
}

/* 
2 1 入栈
2 0 入栈
1 1 入栈
1 0 入栈
0 1 入栈
0 1 退栈
1 0 退栈
0 2 入栈
0 2 退栈
1 1 退栈
2 0 退栈
1 3 入栈
1 2 入栈
1 1 入栈
1 0 入栈
0 1 入栈
0 1 退栈
1 0 退栈
0 2 入栈
0 2 退栈
1 1 退栈
0 3 入栈
0 3 退栈
1 2 退栈
0 4 入栈
0 4 退栈
1 3 退栈
2 1 退栈 
*/