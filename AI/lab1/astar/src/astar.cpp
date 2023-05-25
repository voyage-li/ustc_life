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
std::queue<std::tuple<int, int, int>> astar(std::vector<int> data);

struct node
{
    int i, j, s;
    int g;
    double hv;
    std::queue<std::tuple<int, int, int>> vis;
    friend bool operator<(struct node n1, struct node n2)
    {
        if (n1.g + n1.hv == n2.g + n2.hv)
            return n1.g < n2.g;
        return n1.g + n1.hv > n2.g + n2.hv;
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

    int num = visit.size();

    std::cout << num << std::endl;

    while (!visit.empty())
    {
        auto tmp = visit.front();
        visit.pop();
        std::cout << std::get<0>(tmp) << "," << std::get<1>(tmp) << "," << std::get<2>(tmp) << std::endl;
    }

    return 0;
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
            int tmp = (cnt % 3) ? (cnt / 3 + 1) : (cnt / 3);
            tmp += (cnt % 2) ? (!(tmp % 2)) : (tmp % 2);
            retValue += tmp;
        }
    }
    return retValue;
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
    if (i < 0 || i >= n || j < 0 || j >= n)
        return -1;
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

void judge(std::vector<int> &data, int i, int j, int s, int g, std::queue<std::tuple<int, int, int>> &vis, std::priority_queue<struct node> &fque)
{
    if (move(data, i, j, s) == -1)
        return;
    struct node next = {i, j, s, g + 1, h(data), vis};
    next.vis.push(std::make_tuple(i, j, s));
    fque.push(next);
    move(data, i, j, s);
}

std::queue<std::tuple<int, int, int>> astar(std::vector<int> data)
{
    int n = data.size();
    std::priority_queue<struct node> fque;
    std::queue<std::tuple<int, int, int>> visit;
    struct node firststate = {0, 0, 0, 0, h(data), visit};
    fque.push(firststate);
    while (!fque.empty())
    {
        struct node tmp = fque.top();
        fque.pop();
        auto road = tmp.vis;
        auto now = data;
        while (!road.empty())
        {
            auto movement = road.front();
            road.pop();
            move(now, std::get<0>(movement), std::get<1>(movement), std::get<2>(movement));
        }
#ifdef DEBUG
        std::cout << tmp.g << "+" << tmp.hv << "=" << tmp.g + tmp.hv << std::endl;
#endif
        int tmpi = -1, tmpj = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (((now[i] >> (n - 1 - j)) & 1))
                {
                    tmpi = i;
                    tmpj = j;
                    break;
                }
            }
            if (tmpi != -1)
                break;
        }
        if (tmpi == -1 && tmpj == -1)
            return tmp.vis;
        judge(now, tmpi - 1, tmpj, 3, tmp.g, tmp.vis, fque);
        judge(now, tmpi - 1, tmpj, 4, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj + 1, 2, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj + 1, 3, tmp.g, tmp.vis, fque);
        judge(now, tmpi + 1, tmpj, 1, tmp.g, tmp.vis, fque);
        judge(now, tmpi + 1, tmpj, 2, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj - 1, 1, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj - 1, 4, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj, 1, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj, 2, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj, 3, tmp.g, tmp.vis, fque);
        judge(now, tmpi, tmpj, 4, tmp.g, tmp.vis, fque);
    }
    return visit;
}
