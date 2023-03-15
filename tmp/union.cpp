#include <bits/stdc++.h>
const int MAXN = 30001;
int fa[MAXN];
void init(int fre)
{
    for (int i = 1; i <= fre; i++)
        fa[i] = i;
}
int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int a, int b)
{
    int t1 = find(a);
    int t2 = find(b);
    fa[t1] = t2;
}
int main()
{
    int N;
    std::cin >> N;
    while (N--)
    {
        int m, n;
        std::cin >> m >> n;
        init(m);
        while (n--)
        {
            int a, b;
            std::cin >> a >> b;
            merge(a, b);
        }
        for (int i = 1; i <= m; i++)
            std::cout << find(i) << " ";
        std::cout << std::endl;
    }
    return 0;
}