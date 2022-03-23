#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 20
#define InfoType int
#define VertexType char
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
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
    friend bool operator==(VNode a, VNode b)
    {
        return (a.data == b.data);
    }
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    GraphKind kind;
} ALGraph;

void Kruskal(ALGraph &G)
{
    int visit[G.vexnum];
    int index = 1;
    memset(visit, 0, sizeof(visit));
    int min = INT_MAX;
    std::pair<int, int> temp;
    for (int i = 0; i < G.vexnum; i++)
    {
        min = INT_MAX;
        for (int j = 0; j < G.vexnum; j++)
        {
            ArcNode *p = G.vertices[j].firstarc;
            while (p != NULL)
            {
                if (p->info < min)
                {
                    if (visit[j] == 0 || visit[p->adjvex] == 0 || visit[j] != visit[p->adjvex])
                    {
                        temp = std::make_pair(j, p->adjvex);
                        min = p->info;
                    }
                }
                p = p->nextarc;
            }
        }
        if (min == INT_MAX)
            break;
        std::cout << '(' << G.vertices[temp.first].data << ',' << G.vertices[temp.second].data << ')' << std::endl;
        if (visit[temp.first] == 0 && visit[temp.second] == 0)
        {
            visit[temp.first] = index;
            visit[temp.second] = index;
            index++;
        }
        else if (visit[temp.first] == 0)
            visit[temp.first] = visit[temp.second];
        else if (visit[temp.second] == 0)
            visit[temp.second] = visit[temp.first];
        else
        {
            int same = visit[temp.second];
            for (int s = 0; s < G.vexnum; s++)
                if (visit[s] == same)
                    visit[s] = visit[temp.first];
        }
    }
}

int main()
{
    ALGraph G;
    G.kind = UDN;
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

    Kruskal(G);
    return 0;
}