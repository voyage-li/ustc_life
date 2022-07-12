#include <bits/stdc++.h>

void getnext(std::string p, int next[])
{
    int len = p.length();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len - 1) //最后会对 j+1进行操作 操作到的位置应该是 len-1 所以j只能到 len-2
    {
        if (k == -1 || p[j] == p[k]) //找最长相同前后缀找到头还没有找到 或者 下一个字符相同 可以直接加 1
        {
            j++;
            k++;
            next[j] = k;
        }
        else //失衡了 其实也是一个kmp算法 这里 继续去找最长相同的前后缀 不变化
            k = next[k];
    }
    return;
}

//优化版
//处理回溯的字符和当前失衡的字符相同的情况
//如求 aaaab 的 next 数组 当匹配到 b失衡 与 a仍然失衡 就不应该继续再匹配前一个 a了
void getnext_(std::string p, int next[])
{
    int len = p.length();
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len - 1)
    {
        if (k == -1 || p[j] == p[k]) // j在这
        {
            j++;
            k++;
            if (p[j] != p[k]) //如果next回溯的字符不相等 则可以记录next
                next[j] = k;
            else //如果相等 显然 肯定仍然需要回溯 所以在next数组时直接回溯 一定回溯充分 因为next数组前面也是这样求的
                next[j] = next[k];
        }
        else
            k = next[k];
    }
    return;
}
// kmp的思想就是如果当前字符不相等 s串不一定要回到头开始比较 T串也不需要回到上一次位置的下一个进行比较
int kmp(std::string T, std::string s)
{
    int n = T.length(), m = s.length();
    int next[m];
    getnext(s, next);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || T[i] == s[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }

    if (j >= m)
    {
        T = T.substr(i);
        return (1 + kmp(T, s));
    }
    else
        return 0;
}

int search(const char *s, const char *aim, int l)
{
    char *p;
    if (p = (char *)strstr(s, aim))
        return (1 + search(p + l, aim, l));
    else
        return 0;
}

int main()
{
    std::string data;
    std::cout << "请输入文件:" << std::endl;
    getline(std::cin, data);

    std::cout << "请输入目标关键字:" << std::endl;
    std::string temp;
    getline(std::cin, temp);

    freopen(data.c_str(), "r", stdin);

    int fre = 0; //记录次数
    int i = 0;
    while (getline(std::cin, data))
    {
        i++;
        int tmp = kmp(data, temp);
        if (tmp != 0)
        {
            fre += tmp;
            std::cout << i << ' ' << data;
        }
        else
            continue;
        putchar('\n');
        char c = getchar();
        while (c != EOF)
        {
            if (c != '\n')
            {
                ungetc(c, stdin);
                break;
            }
            c = getchar();
        }
    }
    std::cout << "\'" << temp << "\'共出现" << fre << "次" << std::endl;
    fclose(stdin);
    return 0;
}