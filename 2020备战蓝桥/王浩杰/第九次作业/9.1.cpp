#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char a[100];

double f()
{
	float num = 0, i, s, sum = 0;
	cin >> a;
	if (a[0] == '*') { return f()*f(); }
	else if (a[0] == '+') { return f() + f(); }
	else if (a[0] == '-') { return f() - f(); }
	else if (a [0]== '/') { return f() / f(); }
	else return atof(a);
	return num;
}
int main()
{
	double a;
	a = f();
	cout << a;
	system("pause");
	return 0;
}
