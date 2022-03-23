#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    char name[100];
    float score1,score2,score3;
    float average;
}s[5];
int main()
{
    FILE *fp;
    if((fp=fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\stu_sort.dat","r"))==NULL)
    {
        printf("Can not open the file!\n");
        exit(0);
    }
    for(int i=0;i<5;i++)
    {
        fscanf(fp,"%d%s %f\n",&s[i].num,s[i].name,&s[i].average);
        printf("%d %s %f\n",s[i].num,s[i].name,s[i].average);
    }
    fclose(fp);
}