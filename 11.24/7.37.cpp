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

int DP(ALGraph &G, int i, int dp[], int choice[])
{
    if (dp[i] > 0)
        return dp[i];
    ArcNode *p = G.vertices[i].firstarc;
    int loc = -1;
    while (p != nullptr)
    {
        int temp = DP(G, p->adjvex, dp, choice) + p->info;
        if (temp > dp[i])
        {
            dp[i] = temp;
            choice[i] = p->adjvex;
        }
        p = p->nextarc;
    }
    return dp[i];
}

void find_longest_road(ALGraph &G)
{
    int dp[G.vexnum];
    memset(dp, 0, sizeof(dp));
    int choice[G.vexnum];
    for (int i = 0; i < G.vexnum; i++)
        choice[i] = -1;
    for (int i = 0; i < G.vexnum; i++)
        DP(G, i, dp, choice);
    int temp = 0;
    int loc;
    for (int i = 0; i < G.vexnum; i++)
        if (dp[i] > temp)
        {
            loc = i;
            temp = dp[i];
        }

    std::cout << G.vertices[loc].data << ' ';
    while (choice[loc] != -1)
    {
        loc = choice[loc];
        std::cout << G.vertices[loc].data << ' ';
    }
    putchar('\n');
}

int main()
{
    ALGraph G;
    G.vexnum = 9;
    G.arcnum = 12;
    G.vertices[0].data = 'a';
    G.vertices[1].data = 'b';
    G.vertices[2].data = 'c';
    G.vertices[3].data = 'd';
    G.vertices[4].data = 'e';
    G.vertices[5].data = 'f';
    G.vertices[6].data = 'g';
    G.vertices[7].data = 'h';
    G.vertices[8].data = 'i';

    ArcNode *p = new ArcNode;
    p->adjvex = 2;
    p->info = 2;
    G.vertices[0].firstarc = p;
    ArcNode *q = new ArcNode;
    q->adjvex = 3;
    q->info = 2;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 3;
    p->info = 3;
    G.vertices[1].firstarc = p;
    q = new ArcNode;
    q->adjvex = 4;
    q->info = 2;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 5;
    p->info = 3;
    G.vertices[2].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 5;
    p->info = 3;
    G.vertices[3].firstarc = p;
    q = new ArcNode;
    q->adjvex = 6;
    q->info = 2;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 6;
    p->info = 1;
    G.vertices[4].firstarc = p;
    p->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 7;
    p->info = 2;
    G.vertices[5].firstarc = p;
    q = new ArcNode;
    q->adjvex = 8;
    q->info = 3;
    p->nextarc = q;
    q->nextarc = nullptr;

    p = new ArcNode;
    p->adjvex = 7;
    p->info = 2;
    G.vertices[6].firstarc = p;
    q = new ArcNode;
    q->adjvex = 8;
    q->info = 2;
    p->nextarc = q;
    q->nextarc = nullptr;

    G.vertices[7].firstarc = nullptr;
    G.vertices[8].firstarc = nullptr;

    find_longest_road(G);
}