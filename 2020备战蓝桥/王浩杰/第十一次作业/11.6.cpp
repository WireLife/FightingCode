#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

void f()
{

}
int main()
{
	int i = 0,n;
	float p,m,a=0,s;
	cin >> p;
	char q[500], b[500],c;
	do
	{
		c = _getch();
		q[i] = c;
		i++;
	} while (c != '\r');
	m = i;
	for (i=0; i <= m-1; i++)
	{
		c = _getch();
		if (c == q[i])a++;
	}
	m = i;
	s = a / m;
	if (s < p)cout << "NO" << endl;
	else cout << "YES" << endl;
	system("pause");
	return 0;
}
