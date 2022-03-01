#### 1.2

~~~mermaid
graph LR
   d1((d1.))-->d2((d2.))
   d2((d2.))-->d3((d3.))
   d3((d3.))-->d4((d4.))
   d1((d1.))-->d4((d4.))
   d4((d4.))-->d2((d2.))
   d4((d4.))-->d1((d1.))
   d1((d1.))---d2((d2.))
   d1((d1.))---d3((d3.))
   d1((d1.))---d4((d4.))
   d2((d2.))---d4((d4.))
   d2((d2.))---d3((d3.))
~~~

---

#### 1.3

##### (1)  $$n-1$$

##### (2)  $$n$$

##### (3) $$1 \ or \ 2$$

##### (4) $$n$$

##### (5) $$\lfloor \sqrt{n} \rfloor$$

##### (6) $$1100$$

##### (7) $$\sum_{k=1}^n\frac{n(n+1)}{2}$$

---

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

---

#### 3.7

```c++
bool match(std::string s)
{
    std::stack<char> p;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            p.push(s[i]);
        else if (s[i] == ')')
        {
            if (p.top() == '(')
                p.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (p.top() == '{')
                p.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (p.top() == '[')
                p.pop();
            else
                return false;
        }
    }
    if (p.empty())
        return true;
    else
        return false;
}
```

---

#### 3.8

```c++
std::string polish(std::string str)
{
    std::map<char, int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    std::stack<char> s1, s2;
    int i = 0;
    while (i < str.length())
    {
        char iter = str[i];
        if ((iter <= 'z' && iter >= 'a') || (iter <= 'Z' && iter >= 'A') || iter == '(')
        {
            if (iter != '(')
                s1.push(iter);
            else
                s2.push(iter);
            i++;
        }
        else if (iter == ')')
        {
            while (!s2.empty() && s2.top() != '(')
            {
                s1.push(s2.top());
                s2.pop();
            }
            if (!s2.empty())
                s2.pop();
            i++;
        }
        else if (s2.empty() || s2.top() == '(')
        {
            s2.push(iter);
            i++;
        }
        else if (priority[iter] > priority[s2.top()])
        {
            s2.push(iter);
            i++;
        }
        else
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    std::string ans;
    while (!s2.empty())
    {
        ans.push_back(s2.top());
        s2.pop();
    }
    return ans;
}
```

---

#### 3.9

```c++
double polish_value(std::vector<std::string> data)
{
    std::stack<double> s;
    for (auto iter : data)
    {
        if (iter == "+" || iter == "-" || iter == "*" || iter == "/")
        {
            double num1 = s.top();
            s.pop();
            double num2 = s.top();
            s.pop();
            if (iter == "+")
                num1 = num2 + num1;
            else if (iter == "-")
                num1 = num2 - num1;
            else if (iter == "*")
                num1 = num1 * num2;
            else
                num1 = num2 / num1;
            s.push(num1);
        }
        else
            s.push(strtof(iter.c_str(), nullptr));
    }
    return s.top();
}
```

---

#### 3.10

```c++
#define ElemType int
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr rear;
    QNode head;
} LinkQueue;
void InitQueue(LinkQueue &Q)
{
    Q.rear = new QNode;
    Q.rear->next = Q.rear;
}
void EnQueue(LinkQueue &Q, ElemType e)
{
    QueuePtr S = new QNode;
    S->data = e;
    S->next = Q.rear->next;
    Q.rear->next = S;
    Q.rear = S;
}
void DeQueue(LinkQueue &Q, ElemType &e)
{

    QNode *q = Q.rear->next->next;
    e = q->data;
    Q.rear->next->next = q->next;
    if (Q.rear->next->next == Q.rear->next)
        Q.rear = Q.rear->next;
    delete q;
}
```

---

#### 3.11

```c++
#define MaxQSize 7
#define ElemType int
typedef struct
{
    ElemType *base;
    int rear;
    int length;
} Queue;

Queue InitQueue()
{
    Queue Q;
    Q.base = (ElemType *)malloc(MaxQSize * sizeof(ElemType));
    Q.rear = 0;
    Q.length = 0;
    return Q;
}

void EnQueue(Queue &Q, ElemType x)
{
    if (Q.length == MaxQSize)
    {
        printf("队满");
        exit(0);
    }
    Q.base[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxQSize;
    Q.length++;
}

ElemType DeQueue(Queue &Q)
{
    ElemType x;
    if (Q.length == 0)
    {
        printf("队空");
        exit(0);
    }
    x = Q.base[(Q.rear + MaxQSize - Q.length + 1) % MaxQSize];
    Q.length--;
    return x;
}
```

---

#### 5.1

```c++
```

