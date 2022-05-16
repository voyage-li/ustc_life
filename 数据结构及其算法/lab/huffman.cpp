#include <bits/stdc++.h>

struct HTNode
{
    char key;
    int weight;
    int parent, lchild, rchild;
};
typedef HTNode *HuffmanTree;

std::map<char, int> map;
HuffmanTree HT;
std::map<int, char *> HC;
bool already_create = false;

std::string fre_path = "./bin/CharSet.txt";
std::string huff_path = "./bin/hfmtree.txt";
std::string data_path = "./bin/ToBeTran.txt";
std::string code_path = "./bin/CodeFile.txt";
std::string trans_code_path = "./bin/TextFile.txt";
std::string char_code_path = "./bin/CodePrint.txt";
std::string huff_gui_path = "./bin/TreePrint.txt";

void init();
void encode();
void translate();
void print_all();
void print_huff();
void out_put_huff(int fre, int loc, int n, int lr, std::ofstream &outfile);

int main()
{
    int tmp;
    system("cls");
    std::cout << "哈夫曼编码" << std::endl;
    std::cout << "1. 初始化" << std::endl;
    std::cout << "2. 编码" << std::endl;
    std::cout << "3. 译码" << std::endl;
    std::cout << "4. 打印代码文件" << std::endl;
    std::cout << "5. 打印huffman树" << std::endl;
    std::cout << "6. 退出" << std::endl;
    while (1)
    {
        std::cin >> tmp;
        switch (tmp)
        {
        case 1:
            init();
            break;
        case 2:
            encode();
            break;
        case 3:
            translate();
            break;
        case 4:
            print_all();
            break;
        case 5:
            print_huff();
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
    return 0;
}

void insert()
{
    already_create = true;
    std::ifstream infile(huff_path.c_str(), std::ios::in);

    int fre;
    infile >> fre;
    HT = (HuffmanTree)malloc((2 * fre) * sizeof(HTNode));
    HT[0].key = ' ';
    HT[0].weight = INT_MAX;
    char c;
    infile.get(c);
    for (int i = 1; i < 2 * fre; i++)
    {
        infile.get(HT[i].key);
        infile >> HT[i].weight >> HT[i].parent >> HT[i].lchild >> HT[i].rchild;
        if (i <= fre)
            map[HT[i].key] = HT[i].weight;
        infile.get(c);
    }

    char *cd = (char *)malloc(fre * sizeof(char));
    cd[fre - 1] = '\0';
    for (int i = 1; i <= fre; i++)
    {
        int start = fre - 1;
        int j, p;
        for (j = i, p = HT[i].parent; p != 0; j = p, p = HT[p].parent)
        {
            if (HT[p].lchild == j)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[HT[i].key] = (char *)malloc((fre - start) * sizeof(char));
        strcpy(HC[HT[i].key], &cd[start]);
    }

    infile.close();
}

void select(HuffmanTree &HT, int n) //找出最小的两个
{
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent != 0)
            continue;
        if (HT[s1].weight > HT[i].weight)
            s1 = i;
    }
    HT[s1].parent = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent != 0)
            continue;
        if (HT[s2].weight > HT[i].weight)
            s2 = i;
    }
    HT[s2].parent = n + 1;
    HT[n + 1].weight = HT[s1].weight + HT[s2].weight;
    HT[n + 1].lchild = s1;
    HT[n + 1].rchild = s2;
}
void init_huff() //建立哈夫曼树
{
    int fre = map.size();
    HT = (HuffmanTree)malloc((2 * fre) * sizeof(HTNode));
    for (int i = 0; i < 2 * fre; i++)
    {
        HT[i].key = ' ';
        HT[i].weight = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    std::map<int, int>::iterator iter;
    int index = 1;
    HT[0].weight = INT_MAX;
    for (auto iter : map)
    {
        HT[index].key = iter.first;
        HT[index].weight = iter.second;
        index++;
    }

    for (int i = fre + 1; i < 2 * fre; i++)
        select(HT, i - 1);
    char *cd = (char *)malloc(fre * sizeof(char));
    cd[fre - 1] = '\0';
    for (int i = 1; i <= fre; i++)
    {
        int start = fre - 1;
        int j, p;
        for (j = i, p = HT[i].parent; p != 0; j = p, p = HT[p].parent)
        {
            if (HT[p].lchild == j)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[HT[i].key] = (char *)malloc((fre - start) * sizeof(char));
        strcpy(HC[HT[i].key], &cd[start]);
    }
}

void init()
{
    std::ifstream infile(fre_path.c_str(), std::ios::in);
    std::ofstream outfile(huff_path.c_str(), std::ios::out);

    int fre;
    infile >> fre;
    char c;
    infile.get(c);
    int char_fre;
    while (fre--)
    {
        infile.get(c);
        infile >> char_fre;
        map[c] = char_fre;
        infile.get(c);
    }

    init_huff();

    fre = map.size();
    outfile << fre << "\n";
    for (int i = 1; i < 2 * fre; i++)
        outfile << HT[i].key << ' ' << HT[i].weight << ' ' << HT[i].parent << ' ' << HT[i].lchild << ' ' << HT[i].rchild << std::endl;
    already_create = true;
    std::cout << "初始化完成，Huffman树已存在hfmTree.txt中" << std::endl;
    infile.close();
    outfile.close();
}

void encode()
{
    if (already_create == false)
    {
        insert();
        std::cout << "从文件读取huffman树..." << std::endl;
    }

    std::ifstream infile(data_path.c_str(), std::ios::in);
    std::ofstream outfile(code_path.c_str(), std::ios::out);

    char c;
    while (infile.get(c))
    {
        outfile << HC[c];
    }
    std::cout << "编码完成，编码结果已存入CodeFile.txt" << std::endl;

    infile.close();
    outfile.close();
}

void translate()
{
    if (already_create == false)
    {
        insert();
        std::cout << "从文件读取huffman树..." << std::endl;
    }

    std::ifstream infile(code_path.c_str(), std::ios::in);
    std::ofstream outfile(trans_code_path.c_str(), std::ios::out);

    char c;
    int fre = map.size();
    int now = 2 * fre - 1;
    while (infile.get(c))
    {
        if (c == '0')
            now = HT[now].lchild;
        else
            now = HT[now].rchild;
        if (HT[now].lchild == 0)
        {
            outfile.put(HT[now].key);
            now = 2 * fre - 1;
        }
    }
    std::cout << "解码完成，编码结果已存入TextFile.txt中" << std::endl;
    infile.close();
    outfile.close();
}

void print_all()
{
    std::ifstream infile(code_path.c_str(), std::ios::in);
    std::ofstream outfile(char_code_path.c_str(), std::ios::out);

    char c;
    int index = 1;
    while (infile.get(c))
    {
        outfile.put(c);
        putchar(c);
        if (index % 50 == 0)
        {
            outfile.put('\n');
            putchar('\n');
        }
        index++;
    }
    putchar('\n');
    std::cout << "编码结果打印完成，打印结果已存入CodePrint.txt中" << std::endl;

    infile.close();
    outfile.close();
}

void print_huff()
{
    if (already_create == false)
    {
        insert();
        std::cout << "从文件读取huffman树..." << std::endl;
    }

    std::ofstream outfile(huff_gui_path.c_str(), std::ios::out);
    int fre = 2 * map.size() - 1;
    std::cout << "根节点" << std::endl;
    out_put_huff(map.size(), fre, 0, 0, outfile);
    std::cout << "huffman树打印完成，打印结果已存入TreePrint.txt中" << std::endl;
    outfile.close();
}
void out_put_huff(int fre, int loc, int n, int lr, std::ofstream &outfile)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\t";
        outfile << "\t";
    }
    if (loc <= fre)
    {
        std::cout << HT[loc].key << "(" << lr << ")" << std::endl;
        outfile << HT[loc].key << "(" << lr << ")\n";
    }
    else
    {
        std::cout << "(" << lr << ")" << std::endl;
        outfile << "(" << lr << ")\n";
    }
    if (HT[loc].lchild != 0)
        out_put_huff(fre, HT[loc].lchild, n + 1, 0, outfile);
    else
        return;
    if (HT[loc].rchild != 0)
        out_put_huff(fre, HT[loc].rchild, n + 1, 1, outfile);
    else
        return;
}
