#include<stdio.h>
#include<stdlib.h>
int Pell(int n);
int main()
{
	int*a,t;int max,m,n;a=(int*)malloc(max*sizeof(int));
	printf("测试数据组数");scanf("%d",&max);
	for(int i=0;i<max;i++)
	    scanf("%d",&a[i]);
	for(int j=0;j<=i;j++)
	{t=Pell(a[j]);printf("%d\n",t);}
	return 0;
}
int Pell(int n)
{
	int a;
	if(n==1)
		a=1;
	else
		if(n==2)
			a=2;
		else
			a=2*Pell(n-1)+Pell(n-2);
		return a;
}
