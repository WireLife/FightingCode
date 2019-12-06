#include<stdio.h>
#include<string>
char a[100],b[100];
char c[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L'};
void main()
{
	scanf("%s",a);
	int i,j,len;
	int num=0;
	len=strlen(a);	
	for(i=0;i<len;i++)
		if(a[i]<='9')
			num=num*2+a[i]-'0'+0;
		else
			num=num*2+a[i]-'A'+10;
		i=0;
		while(num!=0)
		{
			b[i]=c[num%16]; 
			num=num/16;
			i++;
		}
		for (j=i-1;j>=0;j--)
			printf("%c",b[j]); 
		printf("\n");
}
