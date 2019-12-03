/*PellÊıÁĞ*/ 
#include<stdio.h>
#define N 10000
int f(int i);

int main()
{
	int n,i,Pell[N];
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&Pell[i]);
	
	for(i=0;i<n;i++)
		printf("%d\n",f(Pell[i]));
		
	return 0;	
 } 

int f(int i)
{
	if(i==1) return 1;
	else if(i==2) return 2;
	else return 2*f(i-1)+f(i-2);	 
}
