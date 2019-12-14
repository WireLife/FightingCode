#include<stdio.h>
typedef struct
{
	int year,month,day;
} Date;

int DateToNum(Date dt);   //把日期转化为正整数
int Leapyear(int y);   //判断是否为润年
const int NoLeapYear[]={31,28,31,30,31,30,31,31,30,31,30,31};   //非润年

int main()
{
	int n;
	Date d1,d2;
	d1.year=1990;
	d1.month=1;
	d1.day=1;
	printf("输入以后某一天的年月日：\n");
	scanf("%d%d%d",&d2.year,&d2.month,&d2.day);
	n=DateToNum(d2)-DateToNum(d1);
	if(n%5<=3)
		printf("今天打鱼\n");
	else
		printf("今天晒网\n");
	return 0;
}

int DateToNum(Date dt)
{
	int i;
	int ndays=0;
	for(i=1;i<dt.year;++i)
		ndays+=Leapyear(i)?366:365;
	for(i=1;i<dt.month;++i)
		ndays+=NoLeapYear[i-1];
	if(dt.month>2&&Leapyear(dt.year))
		++ndays;
	ndays+=dt.day;
	return ndays;
}

int Leapyear(int y)
{
	return (y%4==0&&y%100!=0)||(y%400==0);
}
