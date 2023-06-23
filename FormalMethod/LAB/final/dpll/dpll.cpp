#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

std::vector<int> idlist;
std::vector<char> namelist;
int var_num, clauses_num;

int main()
{
    char c;
    while (1)
    {
        std::cin >> c;
        if (c == 'c')
        {
            int id, name;
            std::cin >> id >> name;
            idlist.push_back(id);
            namelist.push_back(name);
        }
        else
            break;
    }
    std::string s;
    std::cin >> s >> var_num >> clauses_num;
    for (int i = 0; i < clauses_num; i++)
    {
    }
}