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
//dfs
void visit(ALGraph &G, int v)
{
    std::cout << v;
}

void all(ALGraph &G, void (*visit)(ALGraph &G, int v))
{
    std::stack<int> s;
    int visited[G.vexnum];
    memset(visited, 0, sizeof(visited));
    s.push(0);
    while (!s.empty())
    {
        int now = s.top();
        s.pop();
        if (!visited[now])
        {
            visit(G, now);
            visited[now] = 1;
            ArcNode *p = G.vertices[now].firstarc;
            while (p != nullptr)
            {
                s.push(p->adjvex);
                p = p->nextarc;
            }
        }
    }
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

    void (*t)(ALGraph &, int);
    t = visit;
    all(G, t);

    return 0;
}