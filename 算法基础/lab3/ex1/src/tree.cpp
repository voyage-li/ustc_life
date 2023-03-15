#include <bits/stdc++.h>

enum ForColor
{
    red,
    black
};

struct Interval
{
    std::pair<int, int> in;
    int max;
    friend bool operator<(const Interval &a, const Interval &b) { return a.in.first < b.in.first; };
    friend bool operator>(const Interval &a, const Interval &b) { return a.in.first > b.in.first; };
    friend bool operator==(const Interval &a, const Interval &b) { return (a.in.first == b.in.first) && (a.in.second == b.in.second); };
};

struct TreeNode
{
    ForColor color;
    struct Interval key;
    struct TreeNode *left, *right, *parent;
};

class IntervalTree
{
private:
    struct TreeNode NILL = {black, {}, nullptr, nullptr, nullptr};
    struct TreeNode *root;
    void leftRotate(struct TreeNode *x);
    void rightRotate(struct TreeNode *y);
    void RBinsertFixup(struct TreeNode *z);
    void RBTransplant(struct TreeNode *u, struct TreeNode *v);
    void RBdeleteFixup(struct TreeNode *x);
    struct TreeNode *TreeMinmum(struct TreeNode *x)
    {
        while (x->left != NIL)
            x = x->left;
        return x;
    };
    int overlap(std::pair<int, int> a, std::pair<int, int> b) { return !(a.second <= b.first || a.first >= b.second); };
    int max_(int a, int b, int c) { return (a > b) ? (a > c ? a : c) : (b > c ? b : c); };
    void updatemax(struct TreeNode *x)
    {
        if (x == NIL)
            return;
        x->key.max = max_(x->key.in.second, x->left->key.max, x->right->key.max);
        if (x != root)
            updatemax(x->parent);
    };
    struct TreeNode *search(std::pair<int, int> key)
    {
        struct Interval aim = {key};
        struct TreeNode *tmp = root;
        while (tmp != NIL)
        {
            if (tmp->key == aim)
                return tmp;
            else if (tmp->key < aim)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        return NIL;
    };
    void RBout(struct TreeNode *p, std::ofstream &outfile)
    {
        if (p == NIL)
            return;
        else
        {
            RBout(p->left, outfile);
            outfile << p->key.in.first << " " << p->key.in.second << " " << p->key.max << std::endl;
            RBout(p->right, outfile);
        }
    }

public:
    struct TreeNode *NIL = &NILL;
    IntervalTree() { root = NIL; };
    ~IntervalTree(){};
    void RBinsert(std::pair<int, int> key);
    void RBdelete(std::pair<int, int> key);
    struct TreeNode *Intervalsearch(std::pair<int, int> i);
    void print(std::ofstream &outfile) { RBout(root, outfile); };
};

struct TreeNode *IntervalTree::Intervalsearch(std::pair<int, int> i)
{
    struct TreeNode *x = root;
    while (x != NIL && !overlap(i, x->key.in))
    {
        if (x->left != NIL && x->left->key.max >= i.first)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

void IntervalTree::leftRotate(struct TreeNode *x)
{
    struct TreeNode *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NIL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;

    y->key.max = x->key.max;
    x->key.max = max_(x->key.in.second, x->left->key.max, x->right->key.max);
}

void IntervalTree::rightRotate(struct TreeNode *y)
{
    struct TreeNode *x = y->left;
    y->left = x->right;
    if (x->right != NIL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NIL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;

    x->key.max = y->key.max;
    y->key.max = max_(y->key.in.second, y->left->key.max, y->right->key.max);
}

void IntervalTree::RBinsert(std::pair<int, int> key)
{
    struct TreeNode *z = new TreeNode;
    struct Interval tmp = {key, key.second};
    z->key = tmp;
    z->color = red;
    z->parent = NIL;
    z->left = NIL;
    z->right = NIL;
    struct TreeNode *y = NIL;
    struct TreeNode *x = root;
    while (x != NIL)
    {
        x->key.max = std::max(x->key.max, z->key.max);
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NIL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    z->left = NIL;
    z->right = NIL;
    z->color = red;
    RBinsertFixup(z);
}

void IntervalTree::RBinsertFixup(struct TreeNode *z)
{
    struct TreeNode *y;
    while (z->parent->color == red)
    {
        if (z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if (y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if (y->color == red)
            {
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = black;
                z->parent->parent->color = red;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = black;
}

void IntervalTree::RBTransplant(struct TreeNode *u, struct TreeNode *v)
{
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

void IntervalTree::RBdeleteFixup(struct TreeNode *x)
{
    struct TreeNode *w;
    while (x != root && x->color == black)
    {
        if (x == x->parent->left)
        {
            w = x->parent->right;
            if (w->color == red)
            {
                w->color = black;
                x->parent->color = red;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == black && w->right->color == black)
            {
                w->color = red;
                x = x->parent;
            }
            else
            {
                if (w->right->color == black)
                {
                    w->left->color = black;
                    w->color = red;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->right->color = black;
                leftRotate(x->parent);
                x = root;
            }
        }
        else
        {
            w = x->parent->left;
            if (w->color == red)
            {
                w->color = black;
                x->parent->color = red;
                rightRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == black && w->right->color == black)
            {
                w->color = red;
                x = x->parent;
            }
            else
            {
                if (w->left->color == black)
                {
                    w->right->color = black;
                    w->color = red;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = black;
                w->left->color = black;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
}

void IntervalTree::RBdelete(std::pair<int, int> key)
{
    struct TreeNode *z = search(key);
    if (z == NIL)
        return;
    struct TreeNode *y = z, *x;
    ForColor origin = y->color;
    if (z->left == NIL)
    {
        x = z->right;
        RBTransplant(z, z->right);
        updatemax(x->parent);
    }
    else if (z->right == NIL)
    {
        x = z->left;
        RBTransplant(z, z->left);
        updatemax(x->parent);
    }
    else
    {
        y = TreeMinmum(z->right);
        origin = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else
        {
            RBTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RBTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
        updatemax(x);
    }
    if (origin == black)
        RBdeleteFixup(x);
}

int main()
{
    srand(time(NULL));
    std::vector<std::pair<int, int>> data;
    int left, right;
    IntervalTree tree;
    while (std::cin >> left >> right)
    {
        data.push_back(std::make_pair(left, right));
        tree.RBinsert(data.back());
    }
    std::ofstream inorder("../output/inorder.txt");
    tree.print(inorder);
    inorder.close();
    std::ofstream delete_data("../output/delete_data.txt");
    for (int i = 0; i < 3; i++)
    {
        int tmp = rand() % data.size();
        tree.RBdelete(data[tmp]);
        delete_data << data[tmp].first << " " << data[tmp].second << std::endl;
        tree.print(delete_data);
    }
    delete_data.close();
    std::ofstream search("../output/search.txt");
    for (int i = 0; i < 3; i++)
    {
        std::pair<int, int> forsearch;
        if (i == 2)
            forsearch = std::make_pair(25, 30);
        else
        {
            int tmp = rand() % 40 + 1;
            int rr = tmp + rand() % 15 + 1;
            forsearch = std::make_pair(tmp, rr);
        }
        struct TreeNode *ans = tree.Intervalsearch(forsearch);
        search << forsearch.first << " " << forsearch.second << std::endl;
        if (ans == tree.NIL)
            search << "Null" << std::endl;
        else
            search << ans->key.in.first << " " << ans->key.in.second << std::endl;
    }
    search.close();
    return 0;
}