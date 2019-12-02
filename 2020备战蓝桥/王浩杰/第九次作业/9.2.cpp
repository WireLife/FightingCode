#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char a[100];
int f1(int b)
{
	int a=b%10,c,d;
	if (b < 10)c = b ;
	else { d = f1(b / 10); c = 2 * d + a; }
	return c;
}
void f2(int c)
{
	int a = c / 16,b = c % 16;
	if (a >= 1)f2(a);
	if (b < 10) { cout << b; }
	else
	{
		switch (b)
		{
		case 10:cout << "A";
		case 11:cout << "B";
		case 12:cout << "C";
		case 13:cout << "D";
		case 14:cout << "E";
		case 15:cout << "F";
		}
	}

}
void f()
{
	int b,c;
	cin >> a;
	b = atoi(a);
	c = f1(b);
	f2(c);
}
int main()
{
	f();
	system("pause");
	return 0;
}
