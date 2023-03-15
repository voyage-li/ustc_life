#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char countries[][40]);
void sort_len(char *table[]);
void sort_ascii(char *table[]);
void output(char *table[]);

int main()
{
    char countries[10][40];
    char *table1[10];
    char *table2[10];
    input(countries);
    for (int i = 0; i < 10; i++)
    {
        table1[i] = countries[i];
        table2[i] = countries[i];
    }
    sort_len(table1);
    sort_ascii(table2);
    printf("STRLEN:\n");
    output(table1);
    printf("ASCII:\n");
    output(table2);
    return 0;
}

void input(char countries[][40])
{
    for (int i = 0; i < 10; i++)
    {
        fgets(countries[i], 40, stdin);
        countries[i][strlen(countries[i]) - 1] = '\0';
    }
}

void sort_len(char *table[])
{

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 - 1; j++)
        {
            if (strlen(table[j]) > strlen(table[j + 1]))
            {
                char *tmp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = tmp;
            }
        }
}

void sort_ascii(char *table[])
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 - 1; j++)
        {
            if (strcmp(table[j], table[j + 1]) > 0)
            {
                char *tmp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = tmp;
            }
        }
}

void output(char *table[])
{
    for (int i = 0; i < 10; i++)
        printf("%s\n", table[i]);
}