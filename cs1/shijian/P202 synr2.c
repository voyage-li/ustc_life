#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    char name[100];
    float score1,score2,score3;
    float average;
}s[5],temp;
int main()
{
    FILE *fp1,*fp2;
    if(((fp1=fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\stud.dat","r+"))==NULL)||((fp2=fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\stu_sort.dat","r+"))==NULL))
    {
        printf("Can not open the file!\n");
        exit(0);
    }
    for(int i=0;i<5;i++)
        fscanf(fp1,"%d%s %f%f%f\n",&s[i].num,s[i].name,&s[i].score1,&s[i].score2,&s[i].score3);
    for(int i=0;i<5;i++)
        fscanf(fp1,"%d%s %f\n",&s[i].num,s[i].name,&s[i].average);
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(s[i].average>s[j].average)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
    for(i=0;i<5;i++)
    {
        fprintf(fp2,"%d %s %f\n",s[i].num,s[i].name,s[i].average);
        printf("%d %s %f\n",s[i].num,s[i].name,s[i].average);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}