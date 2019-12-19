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
		if ((c == 90) || (c == 122))
		{
			a[i] = c - 25;
		}
		else if ((64 < c < 90) || (96 < c < 122))
		{
			a[i] = c + 1;
		}
		else 
		{ 
			a[i] = c;
		}
	}
	cout << endl;
	cout << a<<endl;
	system("pause");
	return 0;
}
