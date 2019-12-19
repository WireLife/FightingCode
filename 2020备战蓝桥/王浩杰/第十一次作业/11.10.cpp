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
		if (c == 'A')a[i] = 'T';
		if (c == 'T')a[i] = 'A';
		if (c == 'C')a[i] = 'G';
		if (c == 'G')a[i] = 'C';
	}
	cout << endl;
	cout << a<<endl;
	system("pause");
	return 0;
}
