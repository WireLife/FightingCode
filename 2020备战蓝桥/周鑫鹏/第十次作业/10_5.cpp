#include<stdio.h>
int main()
{
	int a,b,c,s;
	printf("����������\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a<1990)
		printf("����\n");
	else
		if(a=1990)
			if(b<1)
				printf("����\n");
			else
				if(c<1)
					printf("����\n");
				else
				{
					s=(a-1990)*365+(b-1)*30+(c-1);
					if(s<=3)
						printf("����\n");
					else
						if(s<=5)
							printf("ɹ��\n");
						else
							if(0<s%5<=3)
								printf("����\n");
							else
								printf("ɹ��");
				}
				return 0;
}