#include <bits/stdc++.h>
#define MAX_vex 50
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    float info;
} ArcNode;
typedef struct VNode
{
    char data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_vex];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

void insert(ALGraph &G, int v1, int v2, float weight)
{
    ArcNode *p = new ArcNode;
    p->adjvex = v2;
    p->info = weight;
    p->nextarc = nullptr;
    if (G.vertices[v1].firstarc == nullptr)
        G.vertices[v1].firstarc = p;
    else
    {
        ArcNode *q = G.vertices[v1].firstarc;
        while (q->nextarc != nullptr)
            q = q->nextarc;
        q->nextarc = p;
    }
}

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
        std::cout << '(' << (char)(temp.first + 'A') << ',' << (char)(temp.second + 'A') << ')' << std::endl;
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
    std::ifstream infile("./bin/graph.txt", std::ios::in);
    ALGraph G;
    memset(G.vertices, 0, sizeof(G.vertices));

    infile >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = 'A' + i;
        G.vertices[i].firstarc = nullptr;
    }

    int v1, v2;
    float weight;
    for (int i = 0; i < G.arcnum; i++)
    {
        infile >> v1 >> v2 >> weight;
        insert(G, v1, v2, weight);
    }

    Kruskal(G);

    infile.close();
    return 0;
}