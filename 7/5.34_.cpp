#include <bits/stdc++.h>
//5.34
#define AtomType std::string

typedef enum
{
    ATOM,
    LIST
} ElemTag;

typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} * GList;

GList reverse(GList L)
{
    if (L == NULL)
        return L;
    GList last = NULL;
    GList q = L;
    while (q != NULL)
    {
        if (q->tag == LIST)
            q->hp = reverse(q->hp);
        GList temp = q;
        q = q->tp;
        temp->tp = last;
        last = temp;
    }
    return last;
}

void output(GList L)
{
    GList p = L;
    putchar('(');
    while (p)
    {
        if (p->tag == LIST)
            output(p->hp);
        else
            std::cout << p->atom;
        p = p->tp;
    }
    putchar(')');
}
int main()
{
    GList L = (GList)malloc(sizeof(GLNode));
    L->tag = LIST;
    L->tp = NULL;
    GList a = (GList)malloc(sizeof(GLNode));
    L->hp = a;
    a->tag = LIST;
    GList b = (GList)malloc(sizeof(GLNode));
    a->hp = b;
    b->tag = ATOM;
    b->atom = "f";
    GList c = (GList)malloc(sizeof(GLNode));
    b->tp = c;
    c->tag = LIST;
    c->tp = NULL;
    GList d = (GList)malloc(sizeof(GLNode));
    c->hp = d;
    d->tag = ATOM;
    d->atom = "e";
    GList e = (GList)malloc(sizeof(GLNode));
    d->tp = e;
    e->tag = LIST;
    e->tp = NULL;
    GList f = (GList)malloc(sizeof(GLNode));
    f->tag = ATOM;
    f->tp = NULL;
    f->atom = "d";
    e->hp = f;
    GList g = (GList)malloc(sizeof(GLNode));
    a->tp = g;
    g->tag = LIST;
    GList h = (GList)malloc(sizeof(GLNode));
    g->hp = h;
    h->tag = LIST;
    GList i = (GList)malloc(sizeof(GLNode));
    h->tp = i;
    i->tag = ATOM;
    i->atom = " ";
    GList j = (GList)malloc(sizeof(GLNode));
    h->tp = j;
    j->tp = NULL;
    j->tag = LIST;
    GList k = (GList)malloc(sizeof(GLNode));
    j->hp = k;
    k->tag = ATOM;
    k->atom = "c";
    GList l = (GList)malloc(sizeof(GLNode));
    k->tp = l;
    l->tp = NULL;
    l->tag = ATOM;
    l->atom = "b";
    GList m = (GList)malloc(sizeof(GLNode));
    g->tp = m;
    m->tp = NULL;
    m->tag = ATOM;
    m->atom = "a";
    output(L);

    reverse(L);
    output(L);
    getchar();
}