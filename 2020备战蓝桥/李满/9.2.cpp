#include<stdio.h>
#include<string.h>
//1.将二进制转换为十进制;2.将十进制转换为十六进制输出

int main()
{
	//1.0存储二进制数字，并读取二进制数字长度给unit
	int integer2[101],integer16[101],unit,u,i=0,j=0;
	printf("请输入一个二进制数字\n");
	for(i;;i++)
	{
		scanf("%d",&integer2[i]);
	}
	unit=sizeof(integer2[101]);
	u=unit-1;
	
	int integer10=0,t10;
	for(j;j>=1;j--,u--,i--)
	{
		t10=integer2[i]*(pow(2,u));
		integer10=integer10+t10;
	}
	
	/*...
	//1.1求得到的十进制数integer10是x位数，并存储到数组integer10当中
	for(int x=0;;x++)
	{
		if(  (int)(integer10/pow(10,x))=0  )  break;
	}
	
	int y1,y2;
	for(x;x>=0;x--)
	{
		integer10[x]=(int)(integer10/pow(10,x-1));
		integer10=integer10-integer10[x]*pow(10,x-1);
	}
	...*/
	
	//2.0将十进制转换为十六进制输出
	//2.1定义十六进制
	int scale[16]={0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F} ;
	int k,x;
	//2.2十进制的数转换为存储十六进制的数组
	for(k=0;x!=0;integer10=(int)integer10/16)
	{
		x=integer10%16;
	    switch(x)
	    {
	    	case 0:integer16[k]=0;
	    	case 1:integer16[k]=1;
	    	case 2:integer16[k]=2;
	    	case 3:integer16[k]=3;
	    	case 4:integer16[k]=4;//
	    	case 5:integer16[k]=5;
	    	case 6:integer16[k]=6;
	    	case 7:integer16[k]=7;
	    	case 8:integer16[k]=8;
	    	case 9:integer16[k]=9;//
	    	case 10:integer16[k]=A;
	    	case 11:integer16[k]=B;
	    	case 12:integer16[k]=C;
	    	case 13:integer16[k]=D;
	    	case 14:integer16[k]=E;//
	    	case 15:integer16[k]=F;
		}
    }
    //2.3判断是否需要加“H” （用函数检验integer16[]数组中是否有字母 ） 
	//2.4将存储数字的十六进制数组输出
	int u;
	for(u;;u++)
	{
		printf("")
	 } 
	 
 } //说明：半成品程序暂时运行不出来。有
