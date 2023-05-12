#include <bits/stdc++.h>

struct node
{
    int i, j, s, value;
    friend bool operator>(struct node n1, struct node n2)
    {
        return n1.value < n2.value;
    }
    friend bool operator<(struct node n1, struct node n2)
    {
        return n1.value > n2.value;
    }
};

void reverse(std::vector<std::vector<int>> &data, int n, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    data[i][j] = !data[i][j];
}

void move(std::vector<std::vector<int>> &data, int n, int i, int j, int s)
{
    if (s == 1)
    {
        reverse(data, n, i, j);
        reverse(data, n, i, j + 1);
        reverse(data, n, i - 1, j);
    }
    if (s == 2)
    {
        reverse(data, n, i, j);
        reverse(data, n, i - 1, j);
        reverse(data, n, i, j - 1);
    }
    if (s == 3)
    {
        reverse(data, n, i, j);
        reverse(data, n, i, j - 1);
        reverse(data, n, i + 1, j);
    }
    if (s == 4)
    {
        reverse(data, n, i, j);
        reverse(data, n, i + 1, j);
        reverse(data, n, i, j + 1);
    }
}

int calculate(std::vector<std::vector<int>> &data, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (data[i][j])
                cnt++;
    return cnt;
}

int astar(std::vector<std::vector<int>> &data, int n, std::vector<std::vector<int>> &visit)
{
    std::priority_queue<struct node> pro;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < 4; p++)
            {
                if (visit[i][j] & (1 << p))
                    continue;
                move(data, n, i, j, p + 1);
                struct node tmp;
                tmp.i = i;
                tmp.j = j;
                tmp.s = p + 1;
                tmp.value = calculate(data, n);
                pro.push(tmp);
                move(data, n, i, j, p + 1);
            }
        }
    }
    while (!pro.empty())
    {
        struct node tmp = pro.top();
        pro.pop();
        visit[tmp.i][tmp.j] += 1 << (tmp.s - 1);
        move(data, n, tmp.i, tmp.j, tmp.s);
        if (tmp.value == 0 || astar(data, n, visit))
            return 1;
        visit[tmp.i][tmp.j] -= 1 << (tmp.s - 1);
        move(data, n, tmp.i, tmp.j, tmp.s);
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> data(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> data[i][j];

    std::vector<std::vector<int>> visit(n, std::vector<int>(n, 0));
    astar(data, n, visit);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 0; p < 4; p++)
                if (visit[i][j] & (1 << p))
                    std::cout << i << "," << j << "," << p + 1 << std::endl;

    return 0;
}