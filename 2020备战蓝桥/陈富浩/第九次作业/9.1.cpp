#include<stdio.h>
#include<string.h>
#include<math.h>

char a[1000];
double f()
{
	scanf("%s",&a);
	int len=strlen(a);
	if(len==1&&!(a[0]>='0'&&a[0]<='9'))
		switch(a[0])
		{
			case '+':return f()+f();
			case '-':return f()-f();
			case '*':return f()*f();
			case '/':return f()/f();
		}
	else
	{
		return atof(a);
	}
}
 
int main()
{
	printf("%Lf\n",f());
}