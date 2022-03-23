#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int My_compare(const void *a, const void *b);
int My_compareplus(const void *a, const void *b);

struct transport
{
    char english[20];
    char foreign[20];
} dictionary[100000];

int main()
{
    int index = 0, i;
    char ch[40];
    int tmp;
    while (*fgets(ch, 40, stdin) != '\n')
    {

        for (i = 0; ch[i] != ' '; i++)
            dictionary[index].english[i] = ch[i];
        dictionary[index].english[i] = '\0';
        tmp = i;
        for (i = i + 1; ch[i] != '\n'; i++)
            dictionary[index].foreign[i - tmp - 1] = ch[i];
        dictionary[index].foreign[i] = '\0';
        //record the number of dictionary
        index++;
    }
    int dic_size = index;
    qsort(dictionary, dic_size, sizeof(dictionary[0]), My_compare); //sort foreign word
    char text[100000][20];
    index = 0;
    while (scanf("%s", text[index]) > 0)
        index++;
    int text_size = index;
    char answer[text_size][20];
    char s[5] = "eh";
    struct transport *temp;
    for (index = 0; index < text_size; index++)
    {
        temp = (struct transport *)bsearch(text[index], dictionary, dic_size, sizeof(dictionary[0]), My_compareplus); //search
        if (temp)
            strcpy(answer[index], temp->english);
        else
            strcpy(answer[index], s);
    }
    for (index = 0; index < text_size; index++)
        printf("%s\n", answer[index]);
    return 0;
}

int My_compare(const void *a, const void *b)
{
    return strcmp(((struct transport *)a)->foreign, ((struct transport *)b)->foreign);
    //need to concentrate on,I search it on the Internet
}

int My_compareplus(const void *a, const void *b)
{
    return strcmp((char *)a, ((struct transport *)b)->foreign);
    //need to concentrate on,I search it on the Internet
}