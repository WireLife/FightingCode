#include<stdio.h>
int days(int y, int m, int d)
{
	int d1 = 0, d2 = 0, d3 = 0, sum = 0, year;
	int data[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
	{
		data[2] = 29;
		year = 366;
	}
	else
		year = 365;
	d1 = (y - 1990) * year;
	for (int i = 1; i < m; i++)
		d2 += data[i];
	d3 = d;
	sum = d1 + d2 + d3;
	if (sum % 5 <= 3 && sum % 5 >= 1)
		return 1;
	else
		return 0;
}


int main()
{
	int s, year, month, day;
	printf("Please input the year、month and day(y m d):\n");
	while (~scanf("%d%d%d", &year, &month, &day))
	{
		if (year < 1990)
		{
			printf("The year should be great than 1990"); break;
		}
		if (month < 1 || month>12)
		{
			printf("The month input is error!"); break;
		}
		if (day < 0 || day>31)
		{
			printf("The month input is error!"); break;
		}
		s = days(year, month, day);
		switch (s)
		{
		case 1: printf("打鱼\n"); break;
		case 0: printf("晒网\n"); break;
		default:break;
		}
	}
	return 0;
}
