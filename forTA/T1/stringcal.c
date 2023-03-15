#include <stdio.h>
#include <stdlib.h>

int now_index = 0;
char data[100][1000];

void StrGet(char *s);                          //输入字符串
void StrPut(char *s);                          //显示字符串
int StrLen(char *s);                           //求字符串长度(不包括字符串结束标志)
void StrCat(char *s, char *t);                 //把t接到s后，结果保存在s中
int StrCmp(char *s, char *t);                  //字符串比较
void StrCpy(char *s, char *t);                 //将t复制到s中
void StrIns(char *s, int pos, char *t);        //字符串插入:将t插入s的下标pos之前
void StrSub(char *s, int pos, int n, char *t); //将s中从下标pos开始的n个字符组成的字符串保存在t中
int StrStr(char *s, char *t);                  //求t在s中第一次出现的位置下标，不存在则返回-1
int StrReplace(char *s, char *v, char *t);     //子串置换:将s中出现的v用t置换,v和t可能不等长

int get_index();
void print_all();

int main()
{
    int select = 0;
    while (1)
    {
        printf("========菜单=========\n");
        printf("|0. 退出程序        |\n");
        printf("|1. 输入字符串      |\n");
        printf("|2. 显示字符串      |\n");
        printf("|3. 求字符串长度    |\n");
        printf("|4. 拼接字符串      |\n");
        printf("|5. 字符串比较      |\n");
        printf("|6. 复制字符串      |\n");
        printf("|7. 字符串插入      |\n");
        printf("|8. 求子串          |\n");
        printf("|9. 字符串匹配      |\n");
        printf("|10. 字串置换       |\n");
        printf("|11. 显示所有数据   |\n");
        printf("=====================\n");
        scanf("%d", &select);
        int num_s, num_t, num_v;
        int len_s, len_t;
        int pos, n;
        switch (select)
        {
        case 0:
            exit(0);
            break;
        case 1:
            StrGet(data[now_index++]);
            break;
        case 2:
            printf("输入字符串编号");
            num_s = get_index();
            StrPut(data[num_s]);
            break;
        case 3:
            num_s = get_index();
            len_s = StrLen(data[num_s]);
            StrPut(data[num_s]);
            printf("字符串长度为%d\n", len_s);
            break;
        case 4:
            printf("将t接到s后\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            StrCat(data[num_s], data[num_t]);
            break;
        case 5:
            printf("比较s和t的大小\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            printf("返回结果:%d\n", StrCmp(data[num_s], data[num_t]));
            break;
        case 6:
            printf("将t复制到s中\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            StrCpy(data[num_s], data[num_t]);
            break;
        case 7:
            printf("将t插入s的下标pos之前\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            printf("请输入pos:\n");
            scanf("%d", &pos);
            StrIns(data[num_s], pos, data[num_t]);
            break;
        case 8:
            printf("将s中从下标pos开始的n个字符组成的字符串保存在t中\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            printf("请输入pos:\n");
            scanf("%d", &pos);
            printf("请输入n:\n");
            scanf("%d", &n);
            StrSub(data[num_s], pos, n, data[num_t]);
            break;
        case 9:
            printf("求t在s中第一次出现的位置下标，不存在则返回-1\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            printf("%d\n", StrStr(data[num_s], data[num_t]));
            break;
        case 10:
            printf("子串置换:将s中出现的v用t置换,v和t可能不等长\n");
            printf("请输入s的编号");
            num_s = get_index();
            printf("请输入v的编号");
            num_v = get_index();
            printf("请输入t的编号");
            num_t = get_index();
            if (StrReplace(data[num_s], data[num_v], data[num_t]) == -1)
                printf("ERROR!\n");
            break;
        case 11:
            print_all();
            break;
        default:
            print_all();
            break;
        }
    }
    return 0;
}

int get_index()
{
    printf("(<=%d):\n", now_index - 1);
    int num = now_index;
    scanf("%d", &num);
    if (num > now_index)
    {
        printf("输入了错误编号!\n");
        scanf("%d", &num);
    }
    return num;
}
void print_all()
{
    for (int i = 0; i < now_index; i++)
        printf("%2d  |  %s\n", i, data[i]);
}

void StrGet(char *s)
{
    scanf("%s", s);
};
void StrPut(char *s)
{
    printf("%s\n", s);
};
int StrLen(char *s)
{
    int len = 0;
    for (len = 0; len < 1000; len++)
        if (*(s + len) == '\0')
            break;
    return len;
};
void StrCat(char *s, char *t)
{
    int len1 = StrLen(s);
    int len2 = StrLen(t);
    for (int i = len1; i <= len1 + len2; i++)
        *(s + i) = *(t + i - len1);
};
int StrCmp(char *s, char *t)
{
    int len1 = StrLen(s);
    int len2 = StrLen(t);
    int i, j;
    for (i = 0, j = 0; i < len1 && j < len2; i++, j++)
    {
        if (*(s + i) > *(t + j))
            return 1;
        else if (*(s + i) < *(t + j))
            return -1;
    }
    if (i == len1 && j == len2)
        return 0;
    else if (i > j)
        return 1;
    else
        return -1;
};
void StrCpy(char *s, char *t)
{
    for (int i = 0; *(t + i) != '\0'; i++)
    {
        *(s + i) = *(t + i);
    }
    *(s + StrLen(t)) = '\0';
};
void StrIns(char *s, int pos, char *t)
{
    int len2 = StrLen(t);
    for (int i = pos; i < pos + len2; i++)
    {
        *(s + i + len2) = *(s + i);
        *(s + i) = *(t + i - pos);
    }
};
void StrSub(char *s, int pos, int n, char *t)
{
    for (int i = pos; i < pos + n; i++)
    {
        *(t + i - pos) = *(s + i);
        if (*(s + i) == '\0')
            break;
    }
    *(t + n) = '\0';
};
int StrStr(char *s, char *t)
{
    int len1 = StrLen(s);
    int len2 = StrLen(t);
    for (int i = 0; i < len1; i++)
    {
        int p = i, q = 0;
        while (p < len1 && q < len2)
        {
            if (*(s + p) == *(t + q))
            {
                p++;
                q++;
            }
            else
                break;
        }
        if (q == len2)
            return i;
    }
    return -1;
};
int StrReplace(char *s, char *v, char *t)
{
    int pos = StrStr(s, v);
    if (pos == -1)
        return pos;
    char tempString[1000];
    StrSub(s, pos + StrLen(v), 1000, tempString);
    StrReplace(tempString, v, t);
    *(s + pos) = '\0';
    StrCat(s, t);
    StrCat(s, tempString);
    return 0;
};