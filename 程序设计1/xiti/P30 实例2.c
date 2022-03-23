#include<stdio.h>
#include<math.h> 
int main()
{
	float f_a,f_b,f_c,f_d,f_delta,f_root1,f_root2;	
	printf("�밴�����һ����������˳����������\n");
	scanf("%f",&f_a);
	scanf("%f",&f_b);
	scanf("%f",&f_c);
	if(f_a==0)
	{
		printf("����Ķ�����ϵ��Ϊ0�����̲���һԪ���η���\n");
		return(-1);	
	}
	f_d=-f_b/(2*f_a);
	f_delta=pow(f_b,2)-4*f_a*f_c;
	if(f_delta==0)
	{
		f_root1=f_root2=f_d;
		printf("һԪ���η��� %fx^2+%fx+%f=0 ��������ͬ��ʵ������x1=x2=%f\n",f_a,f_b,f_c,f_root1);
	}
	else if(f_delta>0)
	{
		f_root1 = f_d + sqrt(f_delta)/ (2*f_a);
		f_root2 = f_d - sqrt(f_delta)/ (2*f_a);
		printf("һԪ���η��� %fx^2+%fx+%f=0 ����������ͬ��ʵ������ x1=%f ,x2=%f\n",f_a, f_b, f_c, f_root1, f_root2);
	}
	else
	{
		f_root1 = sqrt(abs(f_delta))/2*f_a;
		f_root2 = sqrt(abs(f_delta))/2*f_a;
		printf("һԪ���η��� %fx^2+%fx+%f=0 ��������������� x1=%f+i%f ,x2=%f-i%f\n", f_a, f_b, f_c, f_d, f_root1, f_d, f_root2);
	}
	return 0; 
}
