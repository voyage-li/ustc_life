#include <bits/stdc++.h>

std::map<int, std::string> map;
std::map<int, std::string> map_out;

std::string binToHex(std::string s)
{
    std::string ans;
    for (int i = 0; i < 4; i++)
    {
        int num = 0;
        for (int j = 0; j < 4; j++)
        {
            num += (s[i * 4 + j] - '0') << (3 - j);
        }
        if (num < 10)
            ans.push_back(num + '0');
        else
            ans.push_back(num - 10 + 'a');
    }
    return ans;
}

std::string To16times16(std::string incode)
{
    int i, j, k;
    unsigned char a, b;
    unsigned long offset;
    a = incode[0] - 0xa0;
    b = incode[1] - 0xa0;
    offset = (94 * (a - 1) + (b - 1)) * 32;
    std::cout << incode[0] << incode[1] << " : " << offset << std::endl;
    FILE *HZK;
    char *str = (char *)malloc(32);
    memset(str, 0, 32);
    if ((HZK = fopen("./src/HZK16", "rb")) == NULL)
    {
        printf("Can't    Open    hzk16\n");
        exit(0);
    }
    fseek(HZK, offset, SEEK_SET);
    fread(str, 32, 1, HZK);
    std::string ans;
    for (j = 0; j < 16; j++)
    {
        for (i = 0; i < 2; i++)
            for (k = 0; k < 8; k++)
            {
                if (((str[j * 2 + i] >> (7 - k)) & 0x1) != 0)
                    ans.push_back('1');
                else
                    ans.push_back('0');
            }
    }
    fclose(HZK);
    return ans;
}

void output(std::ofstream &outfile, std::string s, int x, int y)
{
    outfile << "\t<comp lib=\"4\" loc=\"(";
    outfile << x << "," << y;
    outfile << ")\" name=\"ROM\">" << std::endl;
    outfile << "\t  <a name=\"addrWidth\" val=\"16\"/>" << std::endl;
    outfile << "\t  <a name=\"dataWidth\" val=\"16\"/>" << std::endl;
    outfile << "\t  <a name=\"contents\">addr/data: 16 16" << std::endl;
    outfile << s << std::endl;
    outfile << "</a>\n\t</comp>" << std::endl;
}

void last(std::ofstream &outfile, int size)
{
    outfile << "<comp lib=\"4\" loc=\"(220,660)\" name=\"Counter\">" << std::endl;
    outfile << "<a name=\"width\" val=\"16\"/>" << std::endl;
    outfile << "<a name=\"max\" val=\"0x";
    outfile << std::hex << size - 1;
    outfile << "\"/>" << std::endl;
    outfile << "</comp>" << std::endl;
}

void begin(std::ofstream &outfile)
{
    std::ifstream infile("./src/begin.txt", std::ios::in);
    std::string s;
    while (getline(infile, s))
        outfile << s << std::endl;
    infile.close();
}

void end(std::ofstream &outfile)
{
    outfile << "</circuit>" << std::endl;
    outfile << "</project>" << std::endl;
}

std::string trim(int x, int y)
{
    std::string loc;
    for (int i = y; i < y + 16; i++)
        loc.push_back(map_out[x][i]);
    std::string ans = binToHex(loc);
    ans.push_back(' ');
    return ans;
}

std::string trim_for_l(int x, int y)
{
    std::string ans;
    for (int i = y * 4; i < y * 4 + 4; i++)
        ans.push_back(map[x][i]);
    ans.push_back(' ');
    return ans;
}

std::string binToHex_for_l(std::string s)
{
    std::string ans;
    for (int i = 0; i < 64; i++)
    {
        int num = 0;
        for (int j = 0; j < 4; j++)
        {
            num += (s[i * 4 + j] - '0') << (3 - j);
        }
        if (num < 10)
            ans.push_back(num + '0');
        else
            ans.push_back(num - 10 + 'a');
    }
    return ans;
}

int main(int argc, char **argv)
{
    std::string s(argv[2], strlen(argv[2]));

    if (argv[1][0] == 'r')
    {
        for (int i = 0; i < s.size(); i++)
        {
            std::string data;
            data.push_back(s[i]);
            i++;
            data.push_back(s[i]);
            map[i / 2] = To16times16(data);
            for (int j = 0; j < 16; j++)
            {
                std::string fenge;
                for (int p = 0; p < 16; p++)
                    fenge.push_back(map[i / 2][j * 16 + p]);
                map_out[j] += fenge;
            }
        }

        std::ofstream outfile("output.circ", std::ios::out);
        begin(outfile);

        int size = map_out[0].length() - 15;
        std::map<int, std::string> ans_map;

        for (int i = 0; i < 16; i++)
            for (int j = 0; j < size; j++)
                ans_map[i] += trim(i, j);

        int index = 0;
        for (int i = 400; i <= 1000; i += 200)
            for (int j = 110; j <= 380; j += 90)
            {
                output(outfile, ans_map[index], i, j);
                index++;
            }
        last(outfile, size);
        end(outfile);
        outfile.close();
    }
    else if (argv[1][0] == 'c')
    {
        std::string info;
        for (int i = 0; i < s.size(); i++)
        {
            std::string data;
            data.push_back(s[i]);
            i++;
            data.push_back(s[i]);
            std::string temp = To16times16(data);
            map[i / 2] = temp;
            info += temp;
        }

        int size = (map.size() * 16) - 15;
        int len = info.length();
        std::map<int, std::string> ans_map;

        for (int i = 0; i < 16; i++)
        {
            int index = 0;
            for (int j = i * 16;; j += 16)
            {
                index++;
                std::string ans;
                for (int p = 0; p < 16; p++)
                    ans.push_back(info[j + p]);
                ans_map[i] += binToHex(ans);
                ans_map[i] += " ";
                if (index == size)
                    break;
            }
        }

        std::ofstream outfile("output.circ", std::ios::out);
        begin(outfile);

        int index = 0;
        for (int i = 400; i <= 1000; i += 200)
            for (int j = 110; j <= 380; j += 90)
            {
                output(outfile, ans_map[index], i, j);
                index++;
            }
        last(outfile, size);
        end(outfile);

        outfile.close();
    }
    else if (argv[1][0] == 'l')
    {
        for (int i = 0; i < s.size(); i++)
        {
            std::string data;
            data.push_back(s[i]);
            i++;
            data.push_back(s[i]);
            std::string temp = binToHex_for_l(To16times16(data));
            map[i / 2] = temp;
        }

        int size = map.size();
        std::map<int, std::string> ans_map;

        for (int i = 0; i < 16; i++)
            for (int j = 0; j < size; j++)
                ans_map[i] = ans_map[i] + trim_for_l(j, i);

        std::ofstream outfile("output.circ", std::ios::out);
        begin(outfile);

        int index = 0;
        for (int i = 400; i <= 1000; i += 200)
            for (int j = 110; j <= 380; j += 90)
            {
                output(outfile, ans_map[index], i, j);
                index++;
            }
        last(outfile, size);
        end(outfile);

        outfile.close();
    }
    return 0;
}