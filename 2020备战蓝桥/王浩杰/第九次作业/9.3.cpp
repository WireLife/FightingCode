#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
void f(int n,int m)
{
	int i,c=0,d=n,e,g,h;
	cout << n << " ";
	while (1)
	{
		if (d == 0)break;
		d = d / 10;
		c++;
	}
	for (i = 1; i <= m; i++)
	{
		e = i;
		for (h=c; h > 0; h--)
		{
			e = e * 10;
		}
		g = e + n;
		if (g > 1000)break;
		f(g, m);
	}
}

int main()

{
	int a,b;
	cin >> a;
	b = a / 2;
	f(a,b);
	system("pause");
	return 0;
}
