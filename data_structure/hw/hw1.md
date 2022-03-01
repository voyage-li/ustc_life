#### 2.3

```c++
#define ElementType int
struct ListNode
{
    ElementType val;
    struct ListNode *next;
};
struct ListNode *insert_num(struct ListNode *La, ElementType e)
{
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    q->val = e;
    q->next = nullptr;
    if (!La || La->val >= e)
    {
        q->next = La;
        return q;
    }
    struct ListNode *last, *p;
    p = La;
    while (p->val < e)
    {
        last = p;
        p = p->next;
    }
    last->next = q;
    q->next = p;
    return La;
}
```

---

#### 2.5

```c++
struct ListNode *reverse(struct ListNode *p)
{
    if (!p)
        return nullptr;
    struct ListNode *q, *last;
    q = p->next;
    last = p;
    p->next = nullptr;
    while (!q)
    {
        struct ListNode *temp = q->next;
        q->next = last;
        last = q;
        q = temp;
    }
    return last;
}
```

---

#### 2.6

```c++
struct ListNode *reverse_1(struct ListNode *p)
{
    p->next = reverse(p->next);
    return p;
}
```

---

#### 2.9

```c++
struct ListNode *merge(struct ListNode *a, struct ListNode *b)
{
    while (!a || !b)
    {
        if (!a)
            return b;
        else if (!b)
            return a;
        else if (a->val < b->val)
        {
            a->next = merge(a->next, b);
            return a;
        }
        else
        {
            b->next = merge(a, b->next);
            return b;
        }
    }
}
```

---

#### 2.10

```c++
struct ListNode *delete_pre(struct ListNode *s)
{
    struct ListNode *temp = s;
    while (s->next->next != temp)
        s = s->next;
    s->next = temp;
    return temp;
}
```

---

#### 2.12

```c++
void apart(ElementType a[], int length)
{
    int i = 0, j = length - 1;
    while (i <= j)
    {
        while (a[i] % 2 == 1)
            i++;
        while (a[j] % 2 == 0)
            j--;
        if (i > j)
            break;
        ElementType temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
```