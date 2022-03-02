#include <bits/stdc++.h>
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

void Prim(MGraph &G, int begin)
{
    std::vector<int> s;
    s.push_back(begin);
    std::pair<int, int> temp;
    int min = INT_MAX;
    int next = -1;
    for (int i = 1; i < G.vexnum; i++)
    {
        for (auto iter = s.begin(); iter != s.end(); iter++)
            for (int q = 0; q < G.vexnum; q++)
            {
                if (G.arcs[*iter][q].adj < min && std::find(s.begin(), s.end(), q) == s.end())
                {
                    next = q;
                    min = G.arcs[*iter][q].adj;
                    temp = std::make_pair(*iter, q);
                }
            }
        if (next == -1)
            break;
        std::cout << '(' << G.vexs[temp.first] << ',' << G.vexs[temp.second] << ')' << std::endl;
        s.push_back(next);
        min = INT_MAX;
        next = -1;
    }
}

int main()
{
    MGraph G;
    for (int i = 0; i < 8; i++)
        G.vexs[i] = 'a' + i;
    G.vexnum = 8;
    G.kind = UDN;
    G.arcnum = 14;
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = {INT_MAX, NULL};
    G.arcs[0][1].adj = 4;
    G.arcs[1][0].adj = 4;

    G.arcs[0][2].adj = 3;
    G.arcs[2][0].adj = 3;

    G.arcs[1][2].adj = 5;
    G.arcs[2][1].adj = 5;

    G.arcs[1][3].adj = 5;
    G.arcs[3][1].adj = 5;

    G.arcs[2][3].adj = 5;
    G.arcs[3][2].adj = 5;

    G.arcs[1][4].adj = 9;
    G.arcs[4][1].adj = 9;

    G.arcs[3][4].adj = 7;
    G.arcs[4][3].adj = 7;

    G.arcs[3][5].adj = 6;
    G.arcs[5][3].adj = 6;

    G.arcs[4][5].adj = 3;
    G.arcs[5][4].adj = 3;

    G.arcs[3][6].adj = 5;
    G.arcs[6][3].adj = 5;

    G.arcs[5][6].adj = 2;
    G.arcs[6][5].adj = 2;

    G.arcs[3][7].adj = 4;
    G.arcs[7][3].adj = 4;

    G.arcs[6][7].adj = 6;
    G.arcs[7][6].adj = 6;

    G.arcs[2][7].adj = 5;
    G.arcs[7][2].adj = 5;
    Prim(G, 0);
    return 0;
}