#include<stdio.h>
int f(void)
{
	int one,two,three,four;
	scanf("%d-%d-%d-%d",&one,&two,&three,&four);
	if(four== ( 1*one+2*(two/1000)+3*(two/100%10)+4*(two/10%10)+5*(two%10)+6*(three/1000)+7*(three/100%10)+8*(three/10%10)+9*(three%10) )%11 )
	    return 1;
	else 
	    return 0;
}
int main()
{
	int n;
	printf("enter the number of files\n");
	scanf("%d",&n);
	while(n--)
	    if (f( )==1)
		    printf("Right\n");
		else
		    printf("Wrong\n");
	return 0;
}
