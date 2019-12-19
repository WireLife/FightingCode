#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;
int m[25],n[25];
char q[100000];
void f()
{

}


int main()
{
	int p = 0,d=0,b,c,e=0;
	char a = '0';
	while (a != '\r')
	{
		a = _getch();
		if (a == '\r')break;
		q[p] = a;
		m[a - 97]++;
		n[a - 97] = p;
		p++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (e==0  &&  m[i] == 1)
		{
			c = n[i];
			e = 1;
		}
		else if (e == 1 && m[i] == 1)
		{
			d = n[i];
			e = 0;
		}
	}
	if (c == 0 && d == 0)
	{
		a = q[0];
		if (n[a - 97] == 0)a = q[0];
		else cout << "NO" << endl;
	}
	else if (c != 0 && d == 0)a = q[c];
	else 
	{
		b = c < d ? c : d;
		a = q[b];
	}
	cout << a << endl;
	system("pause");
	return 0;
}
