#include <bits/stdc++.h>
#define MAX_VERTEX_NUM 20
#define InfoType int
#define VertexType int
//假设有向图
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
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;
void InsertVex(ALGraph &G, VNode v)
{
    G.vertices[G.vexnum + 1] = v;
    G.vexnum++;
}
void InsertArc(ALGraph &G, VNode v, VNode w)
{
    int i, j;
    G.arcnum++;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v.data)
            break;
    }
    for (j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].data == v.data)
            break;
    }

    ArcNode *p = G.vertices[i].firstarc;
    while (p->nextarc != nullptr)
        p = p->nextarc;
    ArcNode *temp = (ArcNode *)malloc(sizeof(ArcNode));
    temp->adjvex = j;
    temp->nextarc = nullptr;
    p->nextarc = temp;
}
void DeleteVex(ALGraph &G, VNode v)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v.data)
            break;
    }
    int num;
    ArcNode *p = G.vertices[i].firstarc;
    while (p != NULL)
    {
        num++;
        p = p->nextarc;
    }
    G.arcnum -= num;
    G.vexnum--;
    for (int j = i; j < G.vexnum; j++)
        G.vertices[j] = G.vertices[j + 1];
}
void DeleteArc(ALGraph &G, VNode v, VNode w)
{
    int i, j;
    for (i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data == v.data)
            break;
    }
    for (j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].data == v.data)
            break;
    }
    G.arcnum--;
    ArcNode *p = G.vertices[i].firstarc;
    if (p->adjvex == j)
    {
        G.vertices[i].firstarc = p->nextarc;
        return;
    }
    ArcNode *last = nullptr;
    while (p->adjvex != j)
    {
        last = p;
        p = p->nextarc;
    }
    last->nextarc = p->nextarc;
}