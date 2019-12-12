#include<stdio.h>
int main()
{
	int a,b,c,s;
	printf("输入年月日\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a<1990)
		printf("错误\n");
	else
		if(a=1990)
			if(b<1)
				printf("错误\n");
			else
				if(c<1)
					printf("错误\n");
				else
				{
					s=(a-1990)*365+(b-1)*30+(c-1);
					if(s<=3)
						printf("打鱼\n");
					else
						if(s<=5)
							printf("晒网\n");
						else
							if(0<s%5<=3)
								printf("打鱼\n");
							else
								printf("晒网");
				}
				return 0;
}