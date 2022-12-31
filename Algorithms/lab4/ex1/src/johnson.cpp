#include <bits/stdc++.h>
#include <sys/time.h>
#define MAXN 10000
struct Edge
{
    int to, next, weight;
} edge[MAXN];
int head[MAXN], vis[MAXN], dis[MAXN], h[MAXN], Pi[MAXN];
int flag = 1;
std::string data[8] = {"11", "12", "21", "22", "31", "32", "41", "42"};
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
            else
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
    std::ofstream timefile("../output/time.txt");
    struct timeval begin, end;
    for (auto iter : data)
    {
        std::ifstream infile("../input/input" + iter + ".txt");
        std::ofstream outfile("../output/result" + iter + ".txt");
        int a, b, c;
        int cnt = 0;
        int num = 0;
        int isdelete = 0;
        memset(head, 0, sizeof(head));
        memset(edge, 0, sizeof(edge));
        while (infile >> a >> b >> c)
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
        flag = 1;
        while (flag == 1)
        {
            flag = 0;
            memset(vis, 0, sizeof(vis));
            memset(dis, 0x7f, sizeof(dis));
            dis[1] = 0;
            spfa(1);
            if (flag == 1)
                isdelete = 1;
        }

        if (isdelete == 1)
            outfile << "negative circle" << std::endl;

        // johnson
        // 构建新图 G'
        gettimeofday(&begin, 0);
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
                    outfile << find_road(i, j, dis[j] - h[i] + h[j]) << std::endl;
            }
        }
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds * 1e-6;
        timefile << iter << " : " << std::fixed << elapsed << 's' << std::endl;
        infile.close();
        outfile.close();
    }
    timefile.close();
    return 0;
}