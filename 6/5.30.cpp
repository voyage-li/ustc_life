#include <bits/stdc++.h>

#define AtomType int

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

int getdepth(GList &L)
{
    int hdepth, tdepth;
    if (!L)
        return 1;
    else if (L->tag == ATOM)
        return 0;
    else
    {
        hdepth = getdepth(L->hp) + 1;
        tdepth = getdepth(L->tp);
        if (hdepth > tdepth)
            return hdepth;
        else
            return tdepth;
    }
}
