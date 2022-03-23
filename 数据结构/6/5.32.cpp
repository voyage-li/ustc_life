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

bool isequal(GList &L1, GList &L2)
{
    if (!L1 && !L2)
        return true;
    else if ((!L1 && L2) || (L1 && !L2))
        return false;
    else
    {
        if (L1->tag != L2->tag)
            return false;
        else if (L1->tag == ATOM)
            return L1->atom == L2->atom;
        else
            return isequal(L1->hp, L2->hp) && isequal(L1->tp, L2->tp);
    }
}
