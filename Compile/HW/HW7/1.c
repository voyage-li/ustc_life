#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000
int main()
{
    char s[MAXSIZE] = {}, ch;
    int i = 0;
    while ((ch = getchar()) != EOF)
        s[i++] = ch;
    s[i] = '\0';
    if (f(s) == 1)
        printf("Y");
    else
        printf("N");
}
int f(char s[])
{
    if (strlen(s) - 1 == 0 || strlen(s) - 1 == 1)
        return 1;
    if (s[0] != s[strlen(s) - 2])
        return 0;
    else
    {
        char t[MAXSIZE] = {};
        int i;
        for (i = 0; i < strlen(s) - 2; i++)
        {
            t[i] = s[i + 1];
        }
        f(t);
    }
}
