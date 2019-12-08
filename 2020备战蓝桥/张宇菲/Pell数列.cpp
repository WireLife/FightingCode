#include<stdio.h>
int shu(int k)
{
	int a[100];
	a[1]=1;
	a[2]=2;
	if(k>2)
		a[k]=2*shu(k-1)+shu(k-2);
  return a[k];
}
int main()
{ 
	int k;
	scanf("%d",&k);
	printf("%d",shu(k));
	return 0;
}
