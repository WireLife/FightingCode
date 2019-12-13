/*#include<iostream>
using namespace std;
int marray[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct Date 
{
	int yr, mon, days;
};
int Is_Leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int Datetonumber(Date L)
{
	int total = 0, tag = 0;
	int yushu;
	int y = L.yr;
	while (y > 1990)
	{
		tag = Is_Leapyear(L.yr) ? 366 : 365;
		total = total + tag;
		y--;
	}
	while (L.mon > 0)
	{
		total = total + marray[L.mon - 1];
		L.mon--;
		
	}
	if (Is_Leapyear(L.yr) == 1)
		total++;
	total = total + L.days;
	cout << total << endl;
	yushu = total % 5;
	if (yushu >= 1 && yushu <= 3)
		return 0;
	if (yushu == 4 || yushu == 0)
		return 1;
}
Date Input(Date L)
{
	cout << "输入今天的日期(年月日）：" << endl;
	cin >> L.yr >> L.mon >> L.days;
	return L;
}
int main()
{
	Date L = { 0,0,0 };
	Input(L);
	int tem = Datetonumber(L);
	if (tem ==0)
		cout << "今天应该打渔！" << endl;
	else if(tem==1)
		cout << "今天应该晒网！" << endl;	
	system("pause");
	return 0;
	
}
*/
