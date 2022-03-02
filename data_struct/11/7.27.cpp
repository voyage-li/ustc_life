#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 20
#define InfoType int
#define VertexType int
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    InfoType *info;
} ArcNode;
typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
    friend bool operator==(VNode a, VNode b)
    {
        return (a.data == b.data);
    }
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;
//7.27
bool judge_all_k(ALGraph &G, int k)
{
    int visit[G.vexnum];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < G.vexnum; i++)
        for (int j = i + 1; j < G.vexnum; j++)
        {
            if (!judge_k(G, k, i, j, visit))
                return false;
        }
    return true;
}

bool judge_k(ALGraph &G, int k, int a, int b, int visit[])
{
    if (k == 0 && a == b)
        return true;
    else if (k <= 0)
        return false;
    ArcNode *p = G.vertices[a].firstarc;
    while (p != nullptr)
    {
        if (visit[p->adjvex] == 1)
        {
            p = p->nextarc;
            continue;
        }
        else
        {
            visit[p->adjvex] = 1;
            if (judge_k(G, k - 1, p->adjvex, b, visit))
                return true;
            visit[p->adjvex] = 0;
            p = p->nextarc;
        }
    }
    return false;
}
