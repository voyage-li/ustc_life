#include <bits/stdc++.h>

//使用拉链法处理冲突
struct Node
{
    std::string val;
    struct Node *next;
};
// hash 表用 vector 存，其实数组也可以

std::vector<struct Node *> data(44, 0);
int length = 0; // hash 表长度
std::map<std::string, int> test_fre[4];

// hash 函数
int hash(std::string s)
{
    return (s[0] * 100 + s[s.size() - 1]) % 41;
}

//插入
void insert(std::string s)
{
    length++;
    int loc = hash(s);
    struct Node *p = new struct Node;
    p->val = s;
    p->next = nullptr;
    if (data[loc] == nullptr)
        data[loc] = p;
    else
    {
        struct Node *temp = data[loc];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = p;
    }
}

//查找 找到直接返回指针 找不到返回 nullptr
struct Node *search(std::string s)
{
    int loc = hash(s);
    struct Node *p = data[loc];
    if (p != nullptr)
    {
        while (p != nullptr)
        {
            if (p->val == s)
                break;
            p = p->next;
        }
    }
    return p;
}

void CalculateEveryLength()
{
    int sum = 0;
    for (auto iter : data)
    {
        int index = 1;
        struct Node *p = iter;
        while (p != nullptr)
        {
            sum += index;
            index++;
            p = p->next;
        }
    }
    std::cout << "平均查找长度:" << std::endl;
    std::cout << std::setw(4) << (float)sum / length << std::endl;
}

std::string data_path1 = "./bin/test1.cpp";
std::string data_path2 = "./bin/test2.cpp";
std::string data_path3 = "./bin/test3.cpp";
std::string data_path4 = "./bin/test4.cpp";

void count_fre(std::string data_path, int num)
{
    std::ifstream infile(data_path.c_str(), std::ios::in);
    char c;
    while (infile.get(c))
    {
        std::string ans;
        while (true)
        {
            if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
                ans.push_back(c);
            else
                break;
            infile.get(c);
        }
        // std::cout << ans << std::endl;
        if (search(ans) != nullptr)
            test_fre[num][ans]++;
    }
    infile.close();
}

void judge(int a, int b)
{
    float fenzi = 0;
    float fenmu1 = 0, fenmu2 = 0;
    for (auto i : test_fre[a])
    {
        for (auto j : test_fre[b])
        {
            if (i.first != j.first)
                continue;
            fenzi += i.second * j.second;
            fenmu1 += i.second * i.second;
            fenmu2 += j.second * j.second;
        }
    }
    float for_d = 0;
    for (auto i : test_fre[a])
    {
        for (auto j : test_fre[b])
        {
            if (i.first != j.first)
                continue;
            for_d += pow((i.second / sqrt(fenmu1) - j.second / sqrt(fenmu2)), 2);
        }
    }

    float s = fenzi / (sqrt(fenmu1) * sqrt(fenmu2));
    std::cout << "test" << a + 1 << ".cpp和test" << b + 1 << ".cpp: Xs=" << s << "  D=" << sqrt(for_d);
    if (s >= 0.85 && sqrt(for_d) < 0.25)
        std::cout << "    确实可能相似" << std::endl;
    else
        std::cout << "    不相似" << std::endl;
}

void print_hash()
{
    std::cout << "\n使用拉链法处理冲突:" << std::endl;
    for (int i = 1; i <= 43; i++)
    {
        if (data[i] == nullptr)
            continue;
        else
        {
            struct Node *p = data[i];
            std::cout << std::setw(3) << i << "  ";
            while (p != nullptr)
            {
                std::cout << p->val;
                if (p->next != nullptr)
                    std::cout << " -> ";
                p = p->next;
            }
            std::cout << "\n";
        }
    }
}
int main()
{
    std::string fre_path = "./bin/hash.txt";
    std::ifstream infile_fre(fre_path.c_str(), std::ios::in);
    std::string s;
    while (infile_fre >> s)
    {
        insert(s);
        test_fre[0][s] = 0;
        test_fre[1][s] = 0;
        test_fre[2][s] = 0;
        test_fre[3][s] = 0;
    }
    infile_fre.close();
    CalculateEveryLength();
    print_hash();
    count_fre(data_path1, 0);
    count_fre(data_path2, 1);
    count_fre(data_path3, 2);
    count_fre(data_path4, 3);
    std::cout << "\n频次(统计按照读入的顺序):" << std::endl;
    for (auto iter : test_fre[0])
    {
        std::cout << std::setw(8) << iter.first << ' ' << std::setw(6) << test_fre[0][iter.first] << ' ' << std::setw(6) << test_fre[1][iter.first] << ' ' << std::setw(6) << test_fre[2][iter.first] << ' ' << std::setw(6) << test_fre[3][iter.first] << std::endl;
    }
    std::cout << "\n文件统计:\n";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i >= j)
                continue;
            else
                judge(i, j);
        }

    return 0;
}
