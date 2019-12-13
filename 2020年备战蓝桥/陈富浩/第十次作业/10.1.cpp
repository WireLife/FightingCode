#include<stdio.h>
#include<string.h>

int Check(char* s);

int main()
{
	char a[13];     //定义一字符串储存编码
	gets(a);
	if(Check(a)==1)
		printf("Right!\n");
	else
		printf("Wrong!\n");
	return 0;
}
int Check(char* s)
{
	int i,j,sum=0;
	for(i=0,j=1;i<12;i++)
		if(i!=1&&i!=6&&i!=11)
			sum+=(s[i]-'0')*(j++);
		if(sum%11==(s[12]-'0'))    //校验最后一位
			return 1;
		else if(s[12]=='X')        //校验是否为X
			return 1;
		else 
			return 0;
}
