#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

int s1[1993], s2[1993];
int f(int i)
{
	int a;
	if (i == 3)return 1;
	for (a = 2; a < i / 2; a++)
	{
		if ((i / a) == 0)return 0;
	}
	return 1;
}
void f1(int s)
{
	int sum = 0,n=0,m=0;
	for (int i = 0; i < s; i++)
	{
		if (sum == 1898)n++;
		if (sum >= 1898)
		{
			sum = sum - s2[m] + s2[i];
			m++;
		}
		else sum = sum + s2[i];
	}
	cout << n << endl;
}
int main()
{
	int m,s=0,sum=0;
	for (int i = 1; i <= 1993; i++)
	{
		m = f(i);
		if (m == 1)
		{
			s1[s] = i;
			s++;
		}
	}
	for (int i = 0; i < s; i++)
	{
		s2[i] = s1[i + 1] - s1[i];
	}
	f1(s);
	system("pause");
	return 0;
}
