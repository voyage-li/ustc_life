#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 20
#define InfoType int
#define VertexType int
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

bool judge_arc(ALGraph &G, int v1, int v2, int visit[])
{
    ArcNode *p = G.vertices[v1].firstarc;
    while (p != nullptr)
    {
        if (visit[p->adjvex] == 1)
        {
            p = p->nextarc;
            continue;
        }
        visit[p->adjvex] = 1;
        if (p->adjvex == v2)
            return true;
        else
        {
            if (judge_arc(G, p->adjvex, v2, visit))
                return true;
            else
            {
                visit[p->adjvex] = 0;
                p = p->nextarc;
            }
        }
    }
    return false;
}

bool judge(ALGraph &G, int v1, int v2)
{
    int visit[G.vexnum];
    memset(visit, 0, sizeof(visit));
    return judge_arc(G, v1, v2, visit);
}

int main()
{
    ALGraph G;
    G.vexnum = 8;
    G.arcnum = 14;
    for (int i = 0; i < 8; i++)
        G.vertices[i].data = 'a' + i;

    ArcNode *p = new ArcNode;
    p->adjvex = 1;
    p->info = 4;
    G.vertices[0].firstarc = p;
    ArcNode *q = new ArcNode;
    q->adjvex = 2;
    q->info = 3;
    q->nextarc = nullptr;
    p->nextarc = q;

    ArcNode *temp = p;

    p = new ArcNode;
    p->adjvex = 2;
    p->info = 5;
    G.vertices[1].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 5;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 0;
    p->info = 4;
    q->nextarc = p;
    q = new ArcNode;
    q->adjvex = 4;
    q->info = 9;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 2;
    p->info = 5;
    G.vertices[2].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 5;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 0;
    p->info = 3;
    q->nextarc = p;
    q = new ArcNode;
    q->adjvex = 7;
    q->info = 5;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 1;
    p->info = 5;
    G.vertices[3].firstarc = p;
    q = new ArcNode;
    q->adjvex = 2;
    q->info = 5;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 4;
    p->info = 7;
    q->nextarc = p;
    q = new ArcNode;
    q->adjvex = 5;
    q->info = 6;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 6;
    p->info = 5;
    q->nextarc = p;
    q = new ArcNode;
    q->adjvex = 7;
    q->info = 4;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 1;
    p->info = 9;
    G.vertices[4].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 7;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 5;
    p->info = 3;
    q->nextarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 4;
    p->info = 3;
    G.vertices[5].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 6;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 6;
    p->info = 2;
    q->nextarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 5;
    p->info = 2;
    G.vertices[6].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 5;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 7;
    p->info = 6;
    q->nextarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 6;
    p->info = 6;
    G.vertices[7].firstarc = p;
    q = new ArcNode;
    q->adjvex = 3;
    q->info = 4;
    p->nextarc = q;
    p = new ArcNode;
    p->adjvex = 2;
    p->info = 5;
    q->nextarc = p;
    p->nextarc = nullptr;

    std::cout << judge(G, 0, 7);

    return 0;
}