#include <stdio.h>
#define Maxsize 100
int a(int n);
int main()
{
	int i,j,k;
	int b[Maxsize];
	scanf("%d", &j);
	for(i=0; i<j; ++i)
	{	
		scanf("%d", &k);
		b[i] = a(k);
	}
	for(i=0; i<j; ++i)
		printf("%d\n", b[i]);
	return 0;
}
int a(int n)
{
	int an=0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	while(n>2)
		return 2*a(n-1)+a(n-2);
}
