#include <stdio.h>
int flag;
void Fun(int k,int x)
{
	if(k==x)
	{
		flag=1;
		return;
	}
	if(k>x)
	{
		flag=0;
		return;
	}
	Fun(k*2+1,x);
	Fun(k*3+1,x);
} 
int main() {
	int k,x;
    scanf("%d,%d",&k,&x);
    if(k>x)
    {
    	int temp;
    	temp=k;
    	k=x;
    	x=temp;
	}
	Fun(k,x);
	if(flag==1)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
