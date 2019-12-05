#include<stdio.h>
void F(int n,int m);
int main()
{
	int n,m;
	printf("«Î ‰»În(n<=1000)");
	scanf("%d",&n);m=n;
	F(n,m);
	return 0;
}
void F(int n,int m)
{
	int t,a,b;
	if(n==0)
		printf("0");
	else
		if(n==1)
			printf("1");
		else
			if(n/10==0)
				for(int i=1;i<=m/2;i++)
				{t=i*10+n;printf("%d\n",t);F(t,m);}
				else
					if(n/10<10)
						for(int j=1;j<=m/2;j++)
						{a=j*100+n;printf("%d\n",a);F(a,m);}
}