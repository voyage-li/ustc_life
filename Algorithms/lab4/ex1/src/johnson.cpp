#include <bits/stdc++.h>
#define MAXN 10000
struct Edge
{
    int to, next, weight;
} edge[MAXN];
int head[MAXN], vis[MAXN], dis[MAXN], h[MAXN], Pi[MAXN];
int flag = 1;
struct Node
{
    int val;
    int dist;
    Node(int a, int b)
    {
        val = a;
        dist = b;
    }
    friend bool operator<(const struct Node &a, const struct Node &b)
    {
        return a.dist > b.dist;
    }
};
void spfa(int u)
{
    vis[u] = 1;
    for (int i = head[u], v, last = 0; v = edge[i].to, i; last = i, i = edge[i].next)
    {
        if (dis[v] > dis[u] + edge[i].weight)
        {
            dis[v] = dis[u] + edge[i].weight;
            if (vis[v])
            {
                flag = 1;
                edge[last].next = edge[i].next;
                return;
            }
            spfa(v);
        }
    }
    vis[u] = 0;
}

void dijkstra(int u)
{
    std::priority_queue<struct Node> q;
    q.push(Node(u, 0));
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        int now = tmp.val;
        if (vis[now] == 1)
            continue;
        vis[now] = 1;
        for (int p = head[now]; p; p = edge[p].next)
        {
            if (!vis[edge[p].to] && dis[edge[p].to] > dis[now] + edge[p].weight)
            {
                dis[edge[p].to] = dis[now] + edge[p].weight;
                Pi[edge[p].to] = now;
                q.push(Node(edge[p].to, dis[edge[p].to]));
            }
        }
    }
}

std::string find_road(int u, int v, int val)
{
    std::string ans = std::to_string(v);
    v = Pi[v];
    if (v == 0)
        return "(" + std::to_string(u) + "," + ans + " NULL)";
    while (u != v)
    {
        ans = std::to_string(v) + "," + ans;
        v = Pi[v];
    }
    return "(" + std::to_string(u) + "," + ans + " " + std::to_string(val) + ")";
}

int main()
{
    int a, b, c;
    int cnt = 0;
    int num = 0;
    int isdelete = 0;
    memset(head, 0, sizeof(head));
    while (std::cin >> a >> b >> c)
    {
        edge[++cnt].to = b;
        edge[cnt].next = head[a];
        edge[cnt].weight = c;
        head[a] = cnt;
        if (num < a)
            num = a;
        if (num < b)
            num = b;
    }
    // 消除负环
    while (flag == 1)
    {
        flag = 0;
        for (int i = 1; i <= num; i++)
        {
            memset(vis, 0, sizeof(vis));
            memset(dis, 0x7f, sizeof(dis));
            dis[i] = 0;
            spfa(i);
        }
        if (flag == 1)
            isdelete = 1;
    }
    // johnson
    // 构建新图 G'
    for (int i = 1; i <= num; i++)
    {
        edge[++cnt].to = i;
        edge[cnt].next = head[num + 1];
        edge[cnt].weight = 0;
        head[num + 1] = cnt;
    }
    // Bellman-Ford
    memset(h, 0x7f, sizeof(h));
    h[num + 1] = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num + 1; j++)
        {
            for (int p = head[j]; p; p = edge[p].next)
            {
                if (h[edge[p].to] > h[j] + edge[p].weight)
                    h[edge[p].to] = h[j] + edge[p].weight;
            }
        }
    }
    // 更新权重
    for (int j = 1; j <= num + 1; j++)
    {
        for (int p = head[j]; p; p = edge[p].next)
        {
            edge[p].weight += h[j] - h[edge[p].to];
        }
    }
    // dijkstra
    for (int i = 1; i <= num; i++)
    {
        memset(dis, 0x7f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        memset(Pi, 0, sizeof(Pi));
        dis[i] = 0;
        dijkstra(i);
        for (int j = 1; j <= num; j++)
        {
            if (i != j)
                std::cout << find_road(i, j, dis[j] - h[i] + h[j]) << std::endl;
        }
    }
    return 0;
}