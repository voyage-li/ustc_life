#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 5000
int N;
struct student
{
    char str[M];
    int score;
};
void adjust(struct student s[], int i);
int main()
{
    int i, a, score;
    char str[1000];
    scanf("%d", &N);
    struct student s[N];
    for (i = 0; i < N;)
    {
        scanf("%s%d", str, &score);
        if (score <= 100 && score >= 0)
        {
            strcpy(s[i].str, str);
            s[i].score = score;
            i++;
        }
    }
    scanf("%d", &a);
    adjust(s, a);
    system("pause");
    return 0;
}
void adjust(struct student s[], int i)
{
    int j, k;
    struct student temp;
    switch (i)
    {
    case 1:
        for (j = 0; j < N; j++)
        {
            for (k = j + 1; k < N; k++)
            {
                if (strcmp(s[j].str, s[k].str) > 0)
                {
                    temp = s[j];
                    s[j] = s[k];
                    s[k] = temp;
                }
            }
        }
        for (j = 0; j < N; j++)
            printf("%s %d\n", s[j].str, s[j].score);
        break;
    case 2:
        for (j = 0; j < N; j++)
        {
            for (k = j + 1; k < N; k++)
            {
                if (s[j].score > s[k].score)
                {
                    temp = s[j];
                    s[j] = s[k];
                    s[k] = temp;
                }
            }
        }
        for (j = 0; j < N; j++)
            printf("%s %d\n", s[j].str, s[j].score);
        break;
    }
}
