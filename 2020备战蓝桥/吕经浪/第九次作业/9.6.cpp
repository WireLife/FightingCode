#include<iostream>
using namespace std;
int gcd(int m, int n)//两数最大公约数
{
	int temp;
	if (m < n)
	{
		temp = m;
		m = n;
		n = temp;
	}
	while (n != 0)
	{
		temp = m % n;
		m = n;
		n = temp;
	}
	return(m);
}
int lcm(int m, int n)//两数最小公倍数
{
	int gcd(int m, int n);
	int temp;
	temp = gcd(m, n);
	return(m * n / temp);
}
int lcm1(int a[], int n)//一组数最小公倍数
{
	int i = a[0];
	int j = a[1];
	int k = lcm(i, j);
	int r = 0;
	for (r = 2; r < n; r++)
	{
		k = lcm(k, a[r]);
	}
	return(k);
}
struct Frac//接收存储分数
{
	int cld;
	int mth;
};
int main()
{
	int s = 0, n, i, a[10], b[10];
	Frac frac[10];
	char c;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> frac[i].cld >> c >> frac[i].mth;
		a[i] = frac[i].cld;
		b[i] = frac[i].mth;
	}
	int p = lcm1(b, n);
	for (i = 0; i < n; i++)
	{
		a[i] = p / b[i] * a[i];
		s = s + a[i];
	}
	int q = gcd(s, p);
	cout << s / q << "/" << p / q << endl;
	return 0;
}
