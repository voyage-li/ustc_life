#include <bits/stdc++.h>
template <class T>
class iniqueque
{
public:
    iniqueque(int l);
    ~iniqueque();
    void quepush(T x);
    void quepop();

private:
    T *que = nullptr;
    int front, rear, tag, size;
};
template <class T>
iniqueque<T>::iniqueque(int l)
{
    que = new T[l];
    if (!que)
        std::cout << "overflow" << std::endl;
    front = 0;
    rear = 0;
    tag = 0;
    size = l;
}
template <class T>
iniqueque<T>::~iniqueque()
{
    if (que)
        delete[] que;
}
template <class T>
void iniqueque<T>::quepush(T x)
{
    if (front == rear && tag == 1)
    {
        std::cout << "overflow" << std::endl;
        return;
    }
    que[rear] = x;
    rear = (rear + 1) % size;
    std::cout << "push success" << std::endl;
    if (rear == front)
        tag = 1;
}
template <class T>
void iniqueque<T>::quepop()
{
    if (front == rear && tag == 0)
    {
        std::cout << "nothing could pop" << std::endl;
        return;
    }
    front = (front + 1) % size;
    std::cout << "pop success" << std::endl;
    tag = 0;
}
//更节省空间 但是运行时间会更长
int main()
{
    iniqueque<int> *queq = new iniqueque<int>(5);
    queq->quepush(1);
    queq->quepush(2);
    queq->quepush(3);
    queq->quepush(4);
    queq->quepush(5);
    queq->quepush(6);
    queq->quepop();
    queq->quepush(6);
    queq->quepop();
    queq->quepush(7);
    return 0;
}