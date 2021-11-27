#include<stdio.h>
#include<math.h>
struct complex
{
    double shi;
    double xv;
};
struct complex complex1,complex2;
void Complexplus(struct complex s,struct complex t)
{
    printf("两个虚数的和为：%lf+i%lf\n",s.shi+t.shi,s.xv+t.xv);
}
void Complexji(struct complex s,struct complex t)
{
    printf("两个虚数的乘积为：%lf+i%lf\n",s.shi*t.shi-s.xv+t.xv,s.shi*t.xv+s.xv*t.shi);
}
void ABS(struct complex s)
{
    printf("复数的模为%lf\n",sqrt(s.shi*s.shi+s.xv*s.xv));
}
int main()
{
    printf("请输入一个虚数的实数部：");
    scanf("%lf",&complex1.shi);
    printf("请输入一个虚数的虚数部：");
    scanf("%lf",&complex1.xv);
    printf("请输入另一个虚数的实数部：");
    scanf("%lf",&complex2.shi);
    printf("请输入另一个虚数的虚数部：");
    scanf("%lf",&complex2.xv);
    Complexplus(complex1,complex2);
    Complexji(complex1,complex2);    
    ABS(complex1);
    ABS(complex2);
}