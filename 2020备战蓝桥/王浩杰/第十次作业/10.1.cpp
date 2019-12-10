#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;


void f(char *s)
{
	int a,i,m,sum=0,mod1,mod2;
	char p[1];
	cout << endl;
	p[0] = s[9];
	s[9] = '0';
	a = atoi(s)/10;
	if (s[0] == '0')m = 8;
	else m = 9;
	for (i = 0; i < m; i++)
	{
		mod1 = a % 10;
		sum = sum + (9 - i)*mod1;
		a = a / 10;
	}
	mod2 = sum % 11;
	if (mod2 == 10 && p[0] == 'x')cout << '1';
	else if (mod2 == atoi(p))cout << '1';
	else cout << '0';
}

int main()
{
	char s[10],m[1];
	int i;
	for (i = 0; i <= 9; i++)
	{
		if (i == 1 || i == 5 || i == 9)
		{
			m[0] = getch();
			cout << '-';
		}
		s[i] = getch();
		cout << s[i];
	}
	f(s);
	system("pause");
	return 0;
}
