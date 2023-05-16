#include <bits/stdc++.h>
// #define DEBUG
struct node
{
    int i, j, s;
    float value;
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
void Onlyreverse(std::vector<std::vector<int>> &data, int n, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (data[i][j])
        data[i][j] = !data[i][j];
}

int move(std::vector<std::vector<int>> &data, int n, int i, int j, int s)
{
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i, j + 1);
        reverse(data, n, i - 1, j);
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i - 1, j);
        reverse(data, n, i, j - 1);
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i, j - 1);
        reverse(data, n, i + 1, j);
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i + 1, j);
        reverse(data, n, i, j + 1);
    }
    return 0;
}

int cal1(std::vector<std::vector<int>> &data, int n, int i, int j, int s, int flag)
{
    int ans = 0;
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        ans += data[i][j];
        ans += data[i][j + 1];
        ans += data[i - 1][j];
        if (ans == flag)
        {
            Onlyreverse(data, n, i, j);
            Onlyreverse(data, n, i, j + 1);
            Onlyreverse(data, n, i - 1, j);
        }
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        ans += data[i][j];
        ans += data[i - 1][j];
        ans += data[i][j - 1];
        if (ans == flag)
        {
            Onlyreverse(data, n, i, j);
            Onlyreverse(data, n, i - 1, j);
            Onlyreverse(data, n, i, j - 1);
        }
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        ans += data[i][j];
        ans += data[i][j - 1];
        ans += data[i + 1][j];
        if (ans == flag)
        {
            Onlyreverse(data, n, i, j);
            Onlyreverse(data, n, i, j - 1);
            Onlyreverse(data, n, i + 1, j);
        }
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        ans += data[i][j];
        ans += data[i + 1][j];
        ans += data[i][j + 1];
        if (ans == flag)
        {
            Onlyreverse(data, n, i, j);
            Onlyreverse(data, n, i, j + 1);
            Onlyreverse(data, n, i + 1, j);
        }
    }
    return ans;
}

float calculate(std::vector<std::vector<int>> &data, int n)
{
    int cnt = 0;
    std::vector<std::vector<int>> tmp = data;
    int f = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, n, i, j, p, f) == f)
                {
                    cnt += 1;
                    continue;
                }

    f = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, n, i, j, p, f) == f)
                {
                    cnt += 2;
                    continue;
                }
    f = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, n, i, j, p, f) == f)
                {
                    cnt += 3;
                    continue;
                }

    return cnt / 3.0;
}

int astar(std::vector<std::vector<int>> &data, int n, std::vector<std::vector<int>> &visit)
{
#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------\n";
#endif
    std::priority_queue<struct node> pro;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < 4; p++)
            {
                struct node tmp;
                if (move(data, n, i, j, p + 1) == -1)
                    move(data, n, i, j, p + 1);
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
        if (visit[tmp.i][tmp.j] & (1 << (tmp.s - 1)))
            visit[tmp.i][tmp.j] -= 1 << (tmp.s - 1);
        else
            visit[tmp.i][tmp.j] += 1 << (tmp.s - 1);
        move(data, n, tmp.i, tmp.j, tmp.s);
        if (tmp.value == 0 || astar(data, n, visit))
            return 1;
        visit[tmp.i][tmp.j] -= 1 << (tmp.s - 1);
        move(data, n, tmp.i, tmp.j, tmp.s);
    }
#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n\n\n"
                  << std::endl;
    }
#endif
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

    int num = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 0; p < 4; p++)
                if (visit[i][j] & (1 << p))
                    num += 1;

    std::cout << num << std::endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 0; p < 4; p++)
                if (visit[i][j] & (1 << p))
                    std::cout << i << "," << j << "," << p + 1 << std::endl;

    return 0;
}