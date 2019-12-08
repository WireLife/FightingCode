#include <stdio.h>
int f(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("满足条件的数为\n%d\n", n);
	printf("总计%d个\n", f(n));
	return 0;
}
int f(int n)
{
	int m=n,i=1,j,h,s;
	static c = 1;
	while (m>=10)
	{
		i++;
		m/=10;
	}
	for(h=1;h<=m/2;h++)
	{
		s = h;
		j = i;
		while(j != 0)
		{
			s=s*10;
			j--;
		}
		s = s + n;
        c++;
		printf("%d\n", s);
		if(m>1)
			f(s);//递归
	}
	return c;
}
