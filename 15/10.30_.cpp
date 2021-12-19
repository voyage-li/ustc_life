#include <bits/stdc++.h>

int PartSort(std::vector<int> &array, int left, int right)
{
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

void QuickSortNotR(std::vector<int> &array, int left, int right)
{
    std::stack<int> s;
    s.push(left);
    s.push(right);
    int tag = 0;
    while (!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int index = PartSort(array, left, right);
        if (index - 1 > left)
        {
            if (index - left > 3)
            {
                s.push(left);
                s.push(index - 1);
            }
            else
                sort(array, left, index - 1);
        }
        if (index + 1 < right)
        {
            if (right - index > 3)
            {
                s.push(index + 1);
                s.push(right);
            }
            else
                sort(array, index + 1, right);
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