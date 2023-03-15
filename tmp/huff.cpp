#include <bits/stdc++.h>

struct tmpnode
{
    int num;
    char key;
    int weight;
    int init;
    int left, right;
    int parent;
    std::string code;
    friend bool operator<(const struct tmpnode &a, const struct tmpnode &b)
    {
        if (a.weight == b.weight)
            return a.init > b.init;
        else
            return a.weight > b.weight;
    }
};

struct tmpnode huffman[100];
int loc = 0;
int init = 0;

std::string huffman_code(int i)
{
    if (i == loc - 1)
        return "";
    if (huffman[huffman[i].parent].left == i)
        return huffman_code(huffman[i].parent) + "0";
    else
        return huffman_code(huffman[i].parent) + "1";
}

std::string decode(std::string s)
{
    std::string ans = "";
    int now = loc - 1;
    for (auto iter : s)
    {
        if (iter == '0')
            now = huffman[now].left;
        else
            now = huffman[now].right;
        if (huffman[now].key != '*')
        {
            ans.push_back(huffman[now].key);
            now = loc - 1;
        }
    }
    if (now != loc - 1)
        return "INVALID";
    else
        return ans;
}

int main()
{
    std::string s, str1, str2;
    std::cin >> s >> str1 >> str2;

    std::map<char, int> data;
    int ii[26];
    memset(ii, 0, sizeof(ii));
    for (auto x : s)
    {
        if (data.find(x) != data.end())
            data[x]++;
        else
        {
            data[x] = 1;
            ii[x - '0'] = init++;
        }
    }
    std::map<int, int> init_table;
    std::priority_queue<struct tmpnode> que;
    for (auto iter : data)
    {
        struct tmpnode tmp = {loc, iter.first, iter.second, ii[iter.first - '0']};
        init_table[ii[iter.first - '0']] = loc;
        huffman[loc++] = tmp;
        que.push(tmp);
    }
    while (que.size() > 1)
    {
        auto tmp1 = que.top();
        que.pop();
        auto tmp2 = que.top();
        que.pop();
        struct tmpnode temp;
        temp.key = '*';
        temp.init = init++;
        temp.num = loc++;
        temp.weight = tmp1.weight + tmp2.weight;
        temp.left = tmp1.num;
        temp.right = tmp2.num;
        huffman[tmp1.num].parent = temp.num;
        huffman[tmp2.num].parent = temp.num;
        huffman[temp.num] = temp;
        que.push(temp);
    }

    std::map<char, std::string> char_table;
    for (int i = 0; i < data.size(); i++)
    {
        huffman[i].code = huffman_code(i);
        char_table[huffman[i].key] = huffman[i].code;
    }
    int ans_com = 0;
    for (auto i : s)
        ans_com += char_table[i].size();
    std::cout << s.size() << ' ' << ans_com / 8 + 1 << std::endl;
    for (auto iter : init_table)
    {
        std::cout << huffman[iter.second].key << ':' << huffman[iter.second].code << std::endl;
    }
    std::cout << decode(str1) << std::endl;
    std::cout << decode(str2) << std::endl;
    return 0;
}