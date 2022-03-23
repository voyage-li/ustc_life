#include <bits/stdc++.h>
int PartSort(std::vector<int> &array, int left, int right)
{
    if (left > right)
        return -1;
    int base = array[left];
    int i = left, j = right;
    int temp;
    while (i < j)
    {
        while (i < j && array[j] >= base)
            j--;
        while (i < j && array[i] <= base)
            i++;
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[left] = array[i];
    array[i] = base;
    return i;
}
void sort(std::vector<int> &array, int left, int right)
{
    for (int i = left; i <= right; i++)
        for (int j = i; j <= right; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
}

bool judge(std::vector<int> &array, int left, int right)
{
    if (left > right)
        return false;
    for (int i = left; i < right; i++)
        if (array[i] > array[i + 1])
            return false;
    return true;
}

void QuickSortNotR(std::vector<int> &array, int left, int right)
{
    std::stack<int> s;
    s.push(left);
    s.push(right);
    while (!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        if (right - left + 1 <= 3)
        {
            sort(array, left, right);
            continue;
        }
        int index = PartSort(array, left, right);
        if (index == -1)
            continue;
        if (judge(array, left, index - 1))
        {
            s.push(index + 1);
            s.push(right);
        }
        else if (judge(array, index + 1, right))
        {
            s.push(left);
            s.push(index - 1);
        }
        else if (index - left > right - index)
        {
            s.push(left);
            s.push(index - 1);
            s.push(index + 1);
            s.push(right);
        }
        else
        {
            s.push(index + 1);
            s.push(right);
            s.push(left);
            s.push(index - 1);
        }
    }
}
int main()
{
    std::vector<int> a;
    int temp;
    while (std::cin >> temp)
        a.push_back(temp);
    QuickSortNotR(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}