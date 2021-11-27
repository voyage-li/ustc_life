#include<stdio.h>
#include<stdlib.h>
struct book
{
    int numb;
    char name[100];
    char writer[100];
    char editor[100];
    float prize;
    struct DATE
    {
        int year;
        int month;
        int day;
    } date;
} s[10],temp;
void sort()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(s[j].numb>s[i].numb)
            {
                temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
}
void read(int i)
{
    system("cls");
    printf("请输入第%d本书的书号：",i+1);
    scanf("%d",&s[i].numb);
    printf("请输入第%d本书的书名：",i+1);
    scanf("%s",s[i].name);
    printf("请输入第%d本书的作者：",i+1);
    scanf("%s",s[i].writer);
    printf("请输入第%d本书的出版社：",i+1);
    scanf("%s",s[i].editor);
    printf("请输入第%d本书的价格：",i+1);
    scanf("%f",&s[i].prize);
    printf("请输入第%d本书的出版日期：（格式:年 月 日）",i+1);
    scanf("%d%d%d",&s[i].date.year,&s[i].date.month,&s[i].date.day);
}
void print(int i)
{
    printf("%3d\t%-10s\t%-6s\t%-25s\t%-5f\t%-4d %2d%2d\n",s[i].numb,s[i].name,s[i].writer,s[i].editor,s[i].prize,s[i].date.year,s[i].date.month,s[i].date.day);
}
int main()
{
    system("cls");
    for(int i=0;i<10;i++)
        read(i);
    sort();
    system("cls");
    for(int i=0;i<10;i++)
        print(i);
    float average=0;
    for(int i=0;i<10;i++)
        average=average+s[i].prize;
    average=average/10;
    printf("\n");
    printf("平均价格:%f\n",average);
}