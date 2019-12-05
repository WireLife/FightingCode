#include<stdio.h>
#include<stdlib.h>
#include"1.h"
int main()
{
	float t=0;float*a;int max,m,n;a=(float*)malloc(max*sizeof(float));
	printf("测试数据组数");scanf("%d",&max);
	for(int i=0;i<2;i++)
	{scanf("%d/%d",&m,&n);a[i]=m/n;t=t+a[i];}
	printf("%d",t);
	return 0;
}
