#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

int panduan(int year)
{
	if (year / 4 == 0 && (year / 100 != 0 || year / 400 == 0))return 1;
	else return 0;
}
int f(int year,int month,int day)
{
	int m,sum=0,i;
	int s[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	m = panduan(year);
	if (m == 1)s[1] = 29;
	if (year == 1990)
	{
		for (i = 0; i < month - 1; i++)
		{
			sum = sum + s[i];
		}
		sum += day;
	}
	else
	{
		for (i = 0; i < month - 1; i++)
		{
			sum = sum + s[i];
		}
		sum += day;
		sum = sum + f(year - 1, 12, 31);
	}
	return sum;

}

int main()
{
	int year, month, day,sum,mod;
	cin >> year >> month >> day;
	sum=f(year, month, day);
	mod = sum % 5;
	if (mod >= 1 && mod <= 3)cout << "打渔" << endl;
	else cout << "晒网" << endl;
	system("pause");
	return 0;
}
