#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

void f(int m, int n)
{
	int s, a, b;
	if (m == 1)cout << '1' << '/' << n;
	else if (m%n == 0) { s = m / n; cout << '1' << '/' << s; }
	else
	{
		s = n / m + 1;
		cout << '1' << '/' << s << '+';
		b = s * n;
		a = m * s - n;
		f(a, b);
	}
}


int main()
{
	int m, n;
	char b[1];
	b[0] = _getch();
	m = atoi(b);
	cout << m;
	b[0] = _getch();
	cout << "/";
	cin >> n;
	f(m, n);
	system("pause");
	return 0;
}
