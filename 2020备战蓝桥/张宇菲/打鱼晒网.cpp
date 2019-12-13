#include<stdio.h>
typedef struct data{
	int year;
	int month;
	int day;
}DATE;
int runyear(int);
int countday(DATE);
int main()
{
	DATE today;
	int result;
	scanf("%d %d %d",&today.year,&today.month,&today.day);
    result=countday(today)%5;
	if(result>0&&result<=2)
	printf("打鱼");
	else
		printf("晒网");
	return 0;
}
int runyear(int year)
{
	if((year%400==0)||(year%4==0&&year%100!=0))
		return 1;
	else
		return 0;
}
int countday(DATE today)
{
	int i,year,day,totalday=0;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30};
	for(year=0;i<today.year;year++)
	{
	if(runyear(year))
		totalday=totalday+366;
	else 
		totalday=totalday+366;
	if(runyear(today.year))
	 	month[2]++;
	for(i=0;i<=today.month;i++)
		totalday=totalday+month[i];
		totalday=totalday+today.day;
	return totalday;
	}


}
