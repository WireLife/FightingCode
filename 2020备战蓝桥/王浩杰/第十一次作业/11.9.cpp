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
		cout << c;
		a[i] = c;
	}
	cout << endl;
	for (int n = 0; n < i; i++)
	{
		if (48 <= a[0] <= 57)
		{
			cout << "NO" << endl;
			break;
		}
		if (48 <= a[n] <= 57 || 65 <= a[n] <= 90 || 97 <= a[n] <= 122 || a[n] == '_')continue;
		else
		{
			cout << "NO" << endl;
			break;
		}
		cout << "YES" <<endl;
	}
	system("pause");
	return 0;
}
