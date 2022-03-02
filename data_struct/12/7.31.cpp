#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 20
#define InfoType int
#define VertexType char
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    InfoType info;
} ArcNode;
typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;
//7.31
int min(int a, int b)
{
    return a > b ? b : a;
}
void DFS(ALGraph &G, int i, int &time, std::vector<int> &s, int dfn[], int low[])
{
    s.push_back(i);
    time++;
    dfn[i] = time;
    low[i] = time;
    ArcNode *p = G.vertices[i].firstarc;
    while (p != nullptr)
    {
        if (dfn[p->adjvex] == 0)
        {
            DFS(G, p->adjvex, time, s, dfn, low);
            low[i] = min(low[i], low[p->adjvex]);
        }
        else if (std::find(s.begin(), s.end(), p->adjvex) != s.end())
            low[i] = min(low[i], dfn[p->adjvex]);
        p = p->nextarc;
    }
    if (dfn[i] == low[i])
    {
        int temp = -1;
        while (temp != i)
        {
            temp = s.back();
            s.pop_back();
            std::cout << G.vertices[temp].data << ' ';
        }
        putchar('\n');
    }
}
//O(N+e)
void Tarjan(ALGraph &G)
{
    int dfn[G.vexnum];
    int low[G.vexnum];
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    std::vector<int> s;
    int time = 0;
    for (int i = 0; i < G.vexnum; i++)
        if (dfn[i] == 0)
            DFS(G, i, time, s, dfn, low);
}

int main()
{
    ALGraph G;
    G.vexnum = 8;
    G.arcnum = 11;
    G.vertices[0].data = 'a';
    G.vertices[1].data = 'b';
    G.vertices[2].data = 'c';
    G.vertices[3].data = 'd';
    G.vertices[4].data = 'e';
    G.vertices[5].data = 'f';
    G.vertices[6].data = 'u';
    G.vertices[7].data = 'v';

    ArcNode *p = new ArcNode;
    p->adjvex = 1;
    G.vertices[0].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 5;
    G.vertices[1].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 3;
    G.vertices[2].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 4;
    G.vertices[3].firstarc = p;
    ArcNode *q = new ArcNode;
    q->adjvex = 7;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 6;
    G.vertices[4].firstarc = p;
    q = new ArcNode;
    q->adjvex = 5;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 7;
    G.vertices[5].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 0;
    G.vertices[6].firstarc = p;
    q = new ArcNode;
    q->adjvex = 2;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 1;
    G.vertices[7].firstarc = p;
    p->nextarc = nullptr;

    Tarjan(G);
}