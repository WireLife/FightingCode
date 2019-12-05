#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;
int f1(int m, int n);
int f2(int m, int n);
int f3(int n);
int f1(int m,int n)
{
	int mod,min;
	while (1)
	{
		min = m ? n : m < n;
		mod = n % m;
		if (mod == 0)
		{
			return m;
		}
		m = mod;
		n = min;
	}
}
int f2(int m,int n)
{
	int a1, a2;
	a1 = f3(m);
	a2 = f3(n);
	if ((m != n) && (a1 == 1) && (a2 == 1))return 1;
	else if ((n - m) == 1)return 1;
	else if ((n % 2 == 1) && (m % 2 == 1) && ((n - m) == 2))return 1;
	else if ((m == 1) || (n == 1))return 1;
	else if (a2 == 1)return 1;
	else if ((a1 == 1) && (n%m != 0))return 1;
	else if (((n - 2 * m) == 1) || ((2 * m - n) == 1))return 1;
	else return 0;
}
int f3(int n)
{
	int i,m;
	for (i=2;i<n/2;i++)
	{
		m = n % i;
		if (m == 0)return 1;
	}
	return 0;
}
void f()
{
	int n, p[11], q[11], i,sum1=1,sum2=0,a,s;
	char b[1],c[1],d;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		c[0]= getch();
		p[i] = atoi(c);
		cout <<p[i];
		d = getch();
		cout << "/";
		cin >> q[i];
		sum1 = sum1 * q[i];
	}
	for (i = 0; i < n; i++)
	{
		p[i] = p[i] * sum1 / q[i];
		sum2 = sum2 + p[i];
	}
	if (sum2 > sum1)s = f2(sum1, sum2);
	else s = f2(sum2, sum1);
	if (s == 0)
	{
		if (sum2 > sum1)a = f1(sum1, sum2);
		else a = f1(sum2, sum1);
		sum2 = sum2 / a;
		sum1 = sum1 / a;
	}
	cout << sum2 << "/" << sum1;
}
int main()
{
	f();
	system("pause");
	return 0;
}
