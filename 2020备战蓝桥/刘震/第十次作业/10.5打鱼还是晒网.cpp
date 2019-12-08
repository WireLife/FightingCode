/*打鱼还是晒网*/


/*
//如果直接输入的是以后第几天
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (((n % 5) <= 3) ? "今天打鱼" : "今天晒网");
	getchar();
	getchar();
	return 0;
}
*/

//如果输入的是年月日的话,就转化为某一天距离1990.1.1日有多少天
//第一种：我来编写函数算出距离1990.1.1日有多少天
//第二种：直接调用库函数得出距离今天多少天
#include<iostream>
using namespace std;
const int maxn = 11;

//计算今输入的日期距离1990.1.1有多少天
int count_day(char date[]);

//非润年
int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30 };

//判断是否为润年
bool isRunyear(int i);

int main()
{
	char date[maxn];
	gets_s(date,11);
	cout << (((count_day(date) % 5) <= 3) ? "今天打鱼" : "今天晒网");
	getchar();;
	return 0;
}

int count_day(char date[])
{
	//年月日
	int year, month, day, sum_day = 0;
	sscanf(date, "%d %d %d", &year, &month, &day);  //把字符串变成整数
	//算年
	for (int i = 1990; i < year; i++)
		sum_day += (isRunyear(i)) ? 366 : 365;
	//算月
	for (int i = 1; i < month; i++)  
		sum_day += month_day[i];
	//算日
	sum_day += day;	
	return sum_day;
}

bool isRunyear(int i)
{
	return ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ? true : false;
}