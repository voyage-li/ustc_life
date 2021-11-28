#include <bits/stdc++.h>

template <class T>
class mystack
{
public:
    T *stack;
    int a, b;
    int size = 5;
};

template <class T>
void inistack(mystack<T> &tws)
{
    tws.stack = (T *)malloc(sizeof(T) * tws.size);
    tws.a = 0;
    tws.b = tws.size - 1;
    if (!tws.stack)
        std::cout << "OVERFLOW!" << std::endl;
}
template <class T>
void push(mystack<T> &tws, int i, T x)
{
    if (i == 0)
    {
        if (!isfull(tws))
        {
            tws.stack[tws.a++] = x;
            std::cout << "push success!" << std::endl;
        }
        else
            std::cout << "stack is full" << std::endl;
    }
    else
    {
        if (!isfull(tws))
        {
            tws.stack[tws.b--] = x;
            std::cout << "push success!" << std::endl;
        }
        else
            std::cout << "stack is full" << std::endl;
    }
}
template <class T>
void pop(mystack<T> &tws, int i)
{
    if (i == 0)
    {
        tws.a--;
        std::cout << "pop success!" << std::endl;
    }
    else
    {
        tws.b++;
        std::cout << "pop success!" << std::endl;
    }
}
template <class T>
void deletestack(mystack<T> &tws)
{
    if (tws.size)
        delete[] tws.stack;
}
template <class T>
int isfull(mystack<T> &tws)
{
    if (tws.a > tws.b)
        return 1;
    else
        return 0;
}

int main()
{
    mystack<int> mystack;
    inistack(mystack);
    push(mystack, 0, 1);
    push(mystack, 1, 1);
    push(mystack, 0, 1);
    push(mystack, 1, 1);
    push(mystack, 0, 1);
    push(mystack, 0, 1);
    pop(mystack, 1);
    push(mystack, 0, 1);
    push(mystack, 0, 1);
    return 0;
}