#include <bits/stdc++.h>
//使用邻接矩阵表示法
#define MAX_VERTEX_NUM 20
#define VRType int
#define InfoType int
#define VertexType char
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
typedef struct ArcCell
{
    VRType adj;
    InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind;
} MGraph;
//7.34
void findindegree(MGraph &G, int degree[])
{
    for (int i = 0; i < G.vexnum; i++)
    {
        int temp = 0;
        for (int j = 0; j < G.vexnum; j++)
            if (G.arcs[j][i].adj != INT_MAX)
                temp++;
        degree[i] = temp;
    }
}

void Toplogicalsort(MGraph &G, int name[])
{
    int degree[G.vexnum];
    memset(degree, 0, sizeof(degree));
    findindegree(G, degree);
    std::stack<int> s;
    for (int i = 0; i < G.vexnum; i++)
        if (!degree[i])
            s.push(i);
    int index = 1;
    while (!s.empty())
    {
        int now = s.top();
        name[now] = index++;
        s.pop();

        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[now][i].adj != INT_MAX)
            {
                degree[i]--;
                if (degree[i] == 0)
                    s.push(i);
            }
        }
    }
}

int main()
{
    MGraph G;
    G.vexnum = 6;
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = INT_MAX;
    G.arcs[0][1].adj = 1;
    G.arcs[0][2].adj = 1;
    G.arcs[0][3].adj = 1;
    G.arcs[5][3].adj = 1;
    G.arcs[5][4].adj = 1;
    G.arcs[3][4].adj = 1;
    G.arcs[2][1].adj = 1;
    G.arcs[2][4].adj = 1;
    int name[G.vexnum];
    memset(name, 0, sizeof(name));
    Toplogicalsort(G, name);
    return 0;
}