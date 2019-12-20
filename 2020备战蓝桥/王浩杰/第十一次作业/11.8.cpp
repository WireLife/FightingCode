#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;
char a[100];
int main()
{
	int i;
	char c;
	for (i = 0; i < 100; i++)
	{
		c = _getch();
		if (c == '\r')break;
		a[i] = c;
		if (i >= 1)
		{
			c = a[i] + a[i - 1];
			cout << c;
		}
	}
	c = a[i-1] + a[0];
	cout << c << endl;
	system("pause");
	return 0;
}
