#include<stdio.h>
#include<stdlib.h>
#include"1.h"
int main()
{
	int*a;int max,b,c;a=(int*)malloc(max*sizeof(int));
	printf("测试数据组数");scanf("%d",&max);
	for(int i=0;i<max;i++)
	scanf("%d",&a[i]);
	for(int j=0;j<i;j++)
	{c=a[j];b=Pell(c);printf("%d\n",b);}
	return 0;
}
