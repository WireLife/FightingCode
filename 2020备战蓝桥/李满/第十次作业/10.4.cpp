#include<stdio.h>

int main()
{
	double h[1001]={1},sum=1,t;
	int i,n;
	printf("input n:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		
		h[i]=h[i-1]/2;
		sum=sum+h[i];
		t=h[i];  //h[i]的值需要一个不含i的变量将其带出for语句 
	}
	printf("共经过%fh米\n第n次反弹高度为%fh",sum,t);
	return 0;
 } 
