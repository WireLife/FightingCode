#include<stdio.h>
int main()
{
	int n,x;
	printf("请输入是天数：");
	scanf("%d",&n);
	x=n%5;
	switch(x)
	{
		case 0:printf("晒网");break;
		case 1:printf("打鱼");break; 
		case 2:printf("打鱼");break; 
		case 3:printf("打鱼");break; 
		case 4:printf("晒网");break;
	}
	return 0;
	
}
