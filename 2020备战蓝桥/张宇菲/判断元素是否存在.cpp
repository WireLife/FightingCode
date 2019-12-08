#include<stdio.h>
int k;
int fbool(int x)
{
	if(x==k)return 1;
	if((x-1)%2==0&&(x-1)%3==0) return (fbool((x-1)/2)||fbool((x-1)/3));
    if((x-1)%2==0) return fbool((x-1)/2);
    if((x-1)%3==0) return fbool((x-1)/3);
	else 
        return 0;
}
int main()
{
	int x;
	scanf("%d,%d",&k,&x);
	if(fbool(x))
		printf("yes");
	else
		printf("no");
	return 0;
}

