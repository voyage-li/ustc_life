#include <bits/stdc++.h>
// #define DEBUG

float calculate(std::vector<std::vector<int>> &data);

struct node
{
    int i, j, s;
    int f;
    std::vector<std::vector<int>> data;
    std::vector<std::vector<int>> visist;
    friend bool operator<(struct node n1, struct node n2)
    {
        if (n1.f + calculate(n1.data) == n2.f + calculate(n2.data))
            return n1.f < n2.f;
        else
            return n1.f + calculate(n1.data) > n2.f + calculate(n2.data);
    }
};

void reverse(std::vector<std::vector<int>> &data, int i, int j)
{
    int n = data.size();
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    data[i][j] = !data[i][j];
}
void Onlyreverse(std::vector<std::vector<int>> &data, int i, int j)
{
    int n = data.size();
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (data[i][j])
        data[i][j] = !data[i][j];
}

int move(std::vector<std::vector<int>> &data, int i, int j, int s)
{
    int n = data.size();
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        reverse(data, i, j);
        reverse(data, i, j + 1);
        reverse(data, i - 1, j);
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        reverse(data, i, j);
        reverse(data, i - 1, j);
        reverse(data, i, j - 1);
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        reverse(data, i, j);
        reverse(data, i, j - 1);
        reverse(data, i + 1, j);
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        reverse(data, i, j);
        reverse(data, i + 1, j);
        reverse(data, i, j + 1);
    }
    return 0;
}

int cal1(std::vector<std::vector<int>> &data, int i, int j, int s, int flag)
{
    int n = data.size();
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
            Onlyreverse(data, i, j);
            Onlyreverse(data, i, j + 1);
            Onlyreverse(data, i - 1, j);
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
            Onlyreverse(data, i, j);
            Onlyreverse(data, i - 1, j);
            Onlyreverse(data, i, j - 1);
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
            Onlyreverse(data, i, j);
            Onlyreverse(data, i, j - 1);
            Onlyreverse(data, i + 1, j);
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
            Onlyreverse(data, i, j);
            Onlyreverse(data, i, j + 1);
            Onlyreverse(data, i + 1, j);
        }
    }
    return ans;
}

float calculate(std::vector<std::vector<int>> &data)
{
    int n = data.size();
    int cnt = 0;
    std::vector<std::vector<int>> tmp = data;
    int f = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 1;
                    continue;
                }

    f = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 2;
                    continue;
                }
    f = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 3;
                    continue;
                }
    int cnt1 = cnt;
    tmp = data;
    cnt = 0;
    f = 3;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 1;
                    continue;
                }

    f = 2;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 2;
                    continue;
                }
    f = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 3;
                    continue;
                }
    if (cnt1 > cnt)
        cnt1 = cnt;
    tmp = data;
    cnt = 0;
    f = 3;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 1;
                    continue;
                }

    f = 2;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 2;
                    continue;
                }
    f = 1;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 3;
                    continue;
                }
    if (cnt1 > cnt)
        cnt1 = cnt;
    tmp = data;
    cnt = 0;
    f = 3;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 1;
                    continue;
                }

    f = 2;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 2;
                    continue;
                }
    f = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
                if (cal1(tmp, i, j, p, f) == f)
                {
                    cnt += 3;
                    continue;
                }
    if (cnt1 > cnt)
        cnt1 = cnt;
    return cnt1;
}

std::vector<std::vector<int>> astar(std::vector<std::vector<int>> data)
{
    int n = data.size();
    std::priority_queue<struct node> pro;
    std::set<std::vector<std::vector<int>>> NSame;
    std::vector<std::vector<int>> visit(n, std::vector<int>(n, 0));
    struct node first;
    first.data = data;
    first.f = 0;
    first.visist = visit;
    pro.push(first);
    while (!pro.empty())
    {
        std::vector<std::vector<int>> now = pro.top().data;
        std::vector<std::vector<int>> vis = pro.top().visist;
        int fmp = pro.top().f;
        pro.pop();
#ifdef DEBUG
        std::cout << fmp << "+" << calculate(now) << "=" << fmp + calculate(now) << std::endl;
#endif
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 1; p <= 4; p++)
                {
                    if (move(now, i, j, p) == -1)
                        continue;
                    struct node tmp;
                    tmp.i = i;
                    tmp.j = j;
                    tmp.s = p;
                    tmp.f = fmp + 1;
                    tmp.data = now;
                    tmp.visist = vis;
                    tmp.visist[i][j] ^= 1 << (p - 1);
                    if (calculate(tmp.data) == 0)
                        return tmp.visist;
                    if (!NSame.count(tmp.data))
                        pro.push(tmp);
                    move(now, i, j, p);
                }
            }
        }
    }
    return visit;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> data(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> data[i][j];

    int t;
    std::cin >> t;
    while (t--)
    {
        int i, j, s;
        scanf("%d,%d,%d", &i, &j, &s);
        move(data, i, j, s);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cout << data[i][j];
    return 0;
    auto visit = astar(data);

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