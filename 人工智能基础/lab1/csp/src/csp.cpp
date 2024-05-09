#include <bits/stdc++.h>
#define MAXN 999999
int maxNow = -1;
int Nowans[MAXN];

struct SaNode
{
    int people;  // 人
    int isTrue;  // 是否满足请求
    int Already; // 已经安排请求
    friend bool operator<(struct SaNode n1, struct SaNode n2)
    {
        if (n1.isTrue == n2.isTrue)
            return n1.Already > n2.Already;
        else
            return n1.isTrue < n2.isTrue;
    }
};

struct Node
{
    int loc;    // 位置
    int Remain; // 剩余值
    std::priority_queue<struct SaNode> ReLoc;
    friend bool operator<(struct Node n1, struct Node n2)
    {
        if (n1.Remain == n2.Remain)
            return n1.ReLoc.size() > n2.ReLoc.size();
        else
            return n1.Remain > n2.Remain;
    }
};

int search(std::vector<std::vector<int>> &order, int ans[], int HaveOrder[], int N, int D, int S, int disorder)
{
    if (D * S - maxNow <= disorder)
        return 0;
    std::priority_queue<struct Node> q;
    for (int i = 0; i < D * S; i++)
    {
        int cnt = 0;
        if (ans[i] != 0)
            continue;
        struct Node tmp;
        for (int j = 0; j < N; j++)
        {
            if ((i - 1 < 0 || ans[i - 1] != j + 1) && (i + 1 >= D * S || ans[i + 1] != j + 1))
            {
                struct SaNode tt;
                tt.people = j;
                tt.Already = HaveOrder[j];
                tt.isTrue = 0;
                if (order[i][j] == 1)
                {
                    cnt++;
                    tt.isTrue = 1;
                }
                tmp.ReLoc.push(tt);
            }
        }
        tmp.loc = i;
        tmp.Remain = cnt;
        if (!tmp.ReLoc.empty())
            q.push(tmp);
    }
    if (q.empty())
    {
        for (int i = 0; i < N; i++)
        {
            if (HaveOrder[i] < D * S / N)
                return 0;
        }
        int cnt = 0;
        for (int i = 0; i < D * S; i++)
        {
            if (order[i][ans[i] - 1])
                cnt++;
        }
#ifdef DEBUG
        std::cout << "AIM:  " << D * S << "  NOW:   " << cnt << std::endl;
        for (int i = 0; i < D * S; i++)
            std::cout << ans[i] << " ";
        std::cout << std::endl;
#endif
        if (cnt > maxNow)
        {
            maxNow = cnt;
            for (int i = 0; i < D * S; i++)
                Nowans[i] = ans[i];
        }
        if (cnt == D * S)
            return 1;
        return 0;
    }
    while (!q.empty())
    {
        struct Node tmp = q.top();
        q.pop();
        while (!tmp.ReLoc.empty())
        {
            int next = tmp.ReLoc.top().people;
            int isSatisfy = tmp.ReLoc.top().isTrue;
            tmp.ReLoc.pop();
            if ((D * S - maxNow) <= disorder || (isSatisfy == 0 && (D * S - maxNow) <= disorder + 1))
                break;
            ans[tmp.loc] = next + 1;
            HaveOrder[next] += 1;
            if (search(order, ans, HaveOrder, N, D, S, (isSatisfy ? disorder : disorder + 1)))
                return 1;
            ans[tmp.loc] = 0;
            HaveOrder[next] -= 1;
        }
        if (tmp.Remain == 0 && (D * S - maxNow) <= disorder + 1)
            break;
    }
    return 0;
}

int main()
{
    int N, D, S;
    char tmp;
    std::cin >> N >> tmp >> D >> tmp >> S;
    std::vector<std::vector<int>> order(D * S, std::vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            for (int p = 0; p < S; p++)
            {
                std::cin >> order[j * S + p][i];
                getchar();
            }
        }
    }
    int ans[D * S];
    memset(ans, 0, sizeof(ans));
    int HaveOrder[N];
    memset(HaveOrder, 0, sizeof(HaveOrder));
    search(order, ans, HaveOrder, N, D, S, 0);
    if (maxNow == -1)
    {
        std::cout << "No valid schedule found." << std::endl;
        return 0;
    }
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < S; j++)
        {
            std::cout << Nowans[S * i + j];
            if (j != S - 1)
                std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << maxNow << std::endl;
    return 0;
}