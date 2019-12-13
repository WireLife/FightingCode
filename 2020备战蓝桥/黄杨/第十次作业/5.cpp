#include <stdio.h>
int main()
{
	int i,j,y,m,d,h,s;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("请输入年、月、日：\n");
	scanf("%d,%d,%d",&y,&m,&d);
	m=365,j=0;
	for(i=1990;i<y;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0)
		{
			j=j+m+1;
		}
		else 
			j=j+m;
	}
	h=0;
	for(i=1;i<m;i++)
	{
		h=h+a[i];
	}
	if((y%4==0&&y%100!=0)||y%400==0)
		if(m>2)
			h=h+1;
	s=j+h+d;
	i=s%5;
	if(i<=3)
		printf("今天是打鱼\n");
	else
		printf("今天是晒网\n");
	return 0;
}
