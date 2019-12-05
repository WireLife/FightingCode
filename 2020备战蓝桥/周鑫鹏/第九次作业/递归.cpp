#include<stdio.h>
#include<stdlib.h>
#include"1.h"
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
