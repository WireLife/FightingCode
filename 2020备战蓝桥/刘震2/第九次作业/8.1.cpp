/*#include<stdio.h>
#define N 10001

void Output();

int main()
{
	Output();
	return 0;
}

void Output()
{
	char c;
	c=getchar();
	if(c!='!')
	{
		Output();	
		printf("%c",c);
	}		
}*/

/*#include<stdio.h>
int main()
{
	char c,str[100];
	int i;
	for(i=0;;i++)
	{
		c=getchar();
		if(c=='!')
		{
			str[i]=='\0';
			printf("%s",str);
			return 0;
		}	
		str[i]=c;
	}
}*/
/*
#include<stdio.h>
int main()
{ 
	char c,str[100];
	int i=0,a,b;
	
	scanf("%d%c%d");
	do
	{
		c=getchar();
		str[i++]=c;
	}while(c!='!');
	
	str[i-1]='\0';
	printf("%s\n",str);	
	return 0;
}*/

#include<stdio.h>
int main()
{
	int i=0;
	char c,str[100];
	scanf("%c",&c);
	while(c!='!')
	{
		str[i++]=c;
		scanf("%c",&c);
	}
	str[i]='\0';
	printf("%s\n",str);
	return 0;
}
