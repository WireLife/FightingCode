/*����һ��������������ɵ��ַ�������任Ϊʮ���������������*/

//���ַ�����һ����ת��Ϊ10���� �ٽ�10����ת��Ϊ16���ƣ��ڶ��֣���2����ֱ��ת��Ϊʮ�����ơ�
/*
//��һ�֣� ��ת��Ϊ10������ת��Ϊ16���ƣ�������ܻ��ܵ��������ͷ�Χ��Լ�� 
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
	
	//������תΪʮ���� 
	for(i=0;i<len;i++)
		dec+=(bin[i]-'0')*pow(2,len-i-1);
	
	//ʮ����ת��Ϊʮ������
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
//�ڶ���ֱ�ӽ�������ת��Ϊʮ������ 	4λ�������൱��һλ16���� ����Ҫ����ʮ����,�ⲻ��λ�������� 
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 101
int main()
{
	char bin[N],hex[N/4];
	gets(bin);
	int i,j,t,k=0,len=strlen(bin);
	
	//ÿȡ��λת��Ϊ10���ƣ���ת��Ϊһλ16���� 
	for(i=len%4;i<=len;i=i+4)
	{
		if(i==0) continue;		//�����ж�i==0����Ϊ��������ǡ��λ��λ4����������ʱ�򣬱����0��ֵ��ʮ�����Ƶ������� 
		t=0;
		for(j=i-1;(j>=i-4)&&j>=0;j--)      //j>0��Ϊ��������Ϊȡ������λ��ʱ�� ���������ÿѭ���ĴΣ���4λ������ת��Ϊһλʮ���� 
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















