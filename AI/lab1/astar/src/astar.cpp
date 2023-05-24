#include <bits/stdc++.h>

#ifdef DEBUG
std::string print(int num)
{
    std::string ans = "";
    while (num != 0)
    {
        if (num % 2)
            ans = "1" + ans;
        else
            ans = "0" + ans;
        num = num / 2;
    }
    return ans;
}
#endif

double h(std::vector<int> data);
int reverse(std::vector<int> &data, int i, int j);
int onlyReverse(std::vector<int> &data, int i, int j);
int move(std::vector<int> &data, int i, int j, int s);
std::vector<std::vector<int>> astar(std::vector<int> data);

struct node
{
    int i, j, s;
    int g;
    std::vector<int> state;
    std::vector<std::vector<int>> vis;
    friend bool operator<(struct node n1, struct node n2)
    {
        if (n1.g + h(n1.state) == n2.g + h(n2.state))
            return n1.g < n2.g;
        return n1.g + h(n1.state) > n2.g + h(n2.state);
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> data(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int tmp;
            std::cin >> tmp;
            if (tmp == 1)
                data[i] = data[i] ^ (1 << (n - 1 - j));
        }
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

int cal(std::vector<int> &data, int i, int j, int s)
{
    int n = data.size();
    int ans = 0;
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        ans += onlyReverse(data, i, j);
        ans += onlyReverse(data, i, j + 1);
        ans += onlyReverse(data, i - 1, j);
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        ans += onlyReverse(data, i, j);
        ans += onlyReverse(data, i - 1, j);
        ans += onlyReverse(data, i, j - 1);
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        ans += onlyReverse(data, i, j);
        ans += onlyReverse(data, i, j - 1);
        ans += onlyReverse(data, i + 1, j);
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        ans += onlyReverse(data, i, j);
        ans += onlyReverse(data, i + 1, j);
        ans += onlyReverse(data, i, j + 1);
    }
    return ans;
}

double h1(std::vector<int> state)
{
    int n = state.size();
    int cnt1 = 0, cnt = 0;
    std::vector<int> data = state;
    int f = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
            {
                if (move(data, i, j, p) == f)
                {
                    cal(data, i, j, p);
                    cnt += 1;
                }
                else
                    move(data, i, j, p);
            }
    f = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
            {
                if (move(data, i, j, p) == f)
                {
                    cal(data, i, j, p);
                    cnt += 2;
                }
                else
                    move(data, i, j, p);
            }
    f = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int p = 1; p <= 4; p++)
            {
                if (move(data, i, j, p) == f)
                {
                    cal(data, i, j, p);
                    cnt += 3;
                }
                else
                    move(data, i, j, p);
            }
    cnt1 = cnt;
    // cnt = 0;
    return cnt / 3.0;
}

double h(std::vector<int> state)
{
    std::vector<int> data = state;
    int n = data.size();
    int retValue = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((data[i] >> (n - 1 - j)) & 1) == 0)
                continue;
            int cnt = 0;
            std::queue<std::pair<int, int>> q;
            q.push(std::make_pair(i, j));
            while (!q.empty())
            {
                auto now = q.front();
                q.pop();
                for (int ii = now.first - 1; ii <= now.first + 1; ii++)
                    for (int jj = now.second - 1; jj <= now.second + 1; jj++)
                        if (onlyReverse(data, ii, jj) == 1)
                            q.push(std::make_pair(ii, jj)), cnt++;
            }
            retValue += (cnt % 3) ? (cnt / 3 + 1) : (cnt / 3);
        }
    }
    return retValue * 1.5;
}

int onlyReverse(std::vector<int> &data, int i, int j)
{
    int n = data.size();
    if (i < 0 || j < 0 || i >= n || j >= n)
        return -1;
    int tmp = data[i];
    data[i] ^= (1 << (n - 1 - j));
    if (tmp > data[i])
        return 1;
    else
    {
        data[i] = tmp;
        return 0;
    }
}

int reverse(std::vector<int> &data, int i, int j)
{
    int n = data.size();
    if (i < 0 || j < 0 || i >= n || j >= n)
        return -1;
    int tmp = data[i];
    data[i] ^= (1 << (n - 1 - j));
    if (tmp > data[i])
        return 1;
    else
        return 0;
}

int move(std::vector<int> &data, int i, int j, int s)
{
    int n = data.size();
    int ans = 0;
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        ans += reverse(data, i, j);
        ans += reverse(data, i, j + 1);
        ans += reverse(data, i - 1, j);
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        ans += reverse(data, i, j);
        ans += reverse(data, i - 1, j);
        ans += reverse(data, i, j - 1);
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        ans += reverse(data, i, j);
        ans += reverse(data, i, j - 1);
        ans += reverse(data, i + 1, j);
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        ans += reverse(data, i, j);
        ans += reverse(data, i + 1, j);
        ans += reverse(data, i, j + 1);
    }
    return ans;
}

std::vector<std::vector<int>> astar(std::vector<int> data)
{
    int n = data.size();
    std::priority_queue<struct node> fque;
    std::set<std::vector<int>> NSame;
    std::vector<std::vector<int>> visit(n, std::vector<int>(n, 0));
    struct node firststate = {0, 0, 0, 0, data, visit};
    fque.push(firststate);
    while (!fque.empty())
    {
        struct node tmp = fque.top();
        fque.pop();
#ifdef DEBUG
        std::cout << tmp.g << "+" << h(tmp.state) << "=" << tmp.g + h(tmp.state) << std::endl;
#endif
        std::priority_queue<struct node> tque;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 1; p <= 4; p++)
                {
                    if (move(tmp.state, i, j, p) == -1)
                        continue;
                    if (h(tmp.state) == 0)
                    {
                        tmp.vis[i][j] ^= 1 << (p - 1);
                        return tmp.vis;
                    }
                    struct node next = {i, j, p, tmp.g + 1, tmp.state, tmp.vis};
                    next.vis[i][j] ^= 1 << (p - 1);
                    if (!NSame.count(next.state))
                    {
                        tque.push(next);
                        NSame.insert(next.state);
                    }
                    move(tmp.state, i, j, p);
                }
            }
        }
        for (int i = 0; !tque.empty(); i++)
        {
            fque.push(tque.top());
            tque.pop();
        }
    }
    return visit;
}
