#include<stdio.h>
#include<stdlib.h>
int char_to_num(char ch);
char num_to_char(int num);
long yuan_to_decimal(char temp[]);
void decimal_to_bian(char temp[],long decimal_num);

int main()
{
	char temp[200];
//	int flag=1;
	long decimal_num;

	 
		scanf("%s",temp);	    
		decimal_num=yuan_to_decimal(temp);
		decimal_to_bian(temp,decimal_num);

			return 0;
	}
	int char_to_num(char ch)
	{
		if(ch>='0'&&ch<='9')
			return ch-'0';
		else 
			return ch-'A'+10;
	}
	char num_to_char(int num)
	{
		if(num>=0&&num<=9)
			return (char)('0'+num-0);
		else
			return (char)('A'+num-10);
	}
	long yuan_to_decimal(char temp[])
	{
		long decimal_num=0;
		int i,length;
		for(i=0;temp[i]!='\0';i++)
			length=i;
		for(i=0;i<=length;i++)
			decimal_num=(decimal_num*2)+char_to_num(temp[i]);
		return decimal_num;
	}
void decimal_to_bian(char temp[],long decimal_num)
	{
		int i=0,length;
		while(decimal_num)
		{
		   temp[i]=num_to_char(decimal_num%16);
	       decimal_num=decimal_num/16;
		   i++;
		}
	length=i;
		 for(i=length-1;i>=0;i--)
		  printf("%c",temp[i]);
	}
 
