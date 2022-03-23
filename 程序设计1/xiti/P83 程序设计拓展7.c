#include<stdio.h>
int main()
{
	char a[200];
	int i,num_l=0,num_r=0;
	while((a[i]=getchar())!=EOF)
	{
		if(a[i]==40)
			num_l++;
		else if(a[i]==41)
			num_r++;
		i++;
		if(num_l<num_r)
		{
			printf("no\n");
			return 0;
		} 
	}
	if(num_l==num_r)
		printf("yes");
	else
		printf("no");
	return 0;
}
