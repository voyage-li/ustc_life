#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,disc,twoa,term1,term2,root1,root2;
	printf("enter a,b,c:");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a==0)
		if(b==0)
			printf("no answer due to input error\n");
		else
			printf("the single root is %f\n",-c/b);
	else
	{
		disc=b*b-4*a*c;
		twoa=2*a;
		term1=-b/twoa;
		term2=sqrt(fabs(disc))/twoa;
		if(disc<0)
			printf("complex roots\n real part=%f\n",term1,term2);
		else if(disc==0)
			printf("real roots\n root1=%f root2=%f\n",term1+term2,term1-term2);
		else
			{
				root1=term1+term2;
				root2=c/(a*root1);
			printf("real roots\n root1=%f root2=%f\n",root1,root2);	
			}
	}
	return 0;
 } 
