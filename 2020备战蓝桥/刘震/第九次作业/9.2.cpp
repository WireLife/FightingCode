/*输入一个二进制数字组成的字符串，求变换为十六进制数据输出。*/

//两种方法第一种先转化为10进制 再将10进制转化为16进制，第二种：有2进制直接转化为十六进制。
/*
//第一种： 先转化为10进制在转化为16进制，但这可能会受到数据类型范围的约束 
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 101

int main()
{
	char bin[N],hex[N/4];
	gets(bin);
	
	int i,t,len=strlen(bin);
	long long dec=0;
	
	//二进制转为十进制 
	for(i=0;i<len;i++)
		dec+=(bin[i]-'0')*pow(2,len-i-1);
	
	//十进制转化为十六进制
	i=0;
	while(dec!=0){
		t=dec%16;
		if(t>=0&&t<=9) hex[i++]=t+'0';
		else hex[i++]=t-10+'A';
		dec/=16;	 
	}
	i--;
	while(i>=0) printf("%c",hex[i--]);
	return 0;
} */
/*
//第二种直接将二进制转化为十六进制 	4位二进制相当于一位16进制 还需要借助十进制,这不受位数的限制 
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 101
int main()
{
	char bin[N],hex[N/4];
	gets(bin);
	int i,j,t,k=0,len=strlen(bin);
	
	//每取四位转化为10进制，再转化为一位16进制 
	for(i=len%4;i<=len;i=i+4)
	{
		if(i==0) continue;		//这里判断i==0是因为当二进制恰好位数位4的整数倍的时候，避免把0赋值给十六进制的数组中 
		t=0;
		for(j=i-1;(j>=i-4)&&j>=0;j--)      //j>0作为条件是因为取不到四位的时候 ，其他情况每循环四次，把4位二进制转化为一位十进制 
		{
			if(bin[j]=='0'||bin[j]=='1')
				t+=(bin[j]-'0')*pow(2,(i-j-1)%4);
		}
		
		if(t>=0&&t<=9) hex[k++]=t+'0';
		else hex[k++]=t-10+'A';
	}
	
	hex[k]='\0';
	puts(hex);
	
	return 0;		
 } 
*/















