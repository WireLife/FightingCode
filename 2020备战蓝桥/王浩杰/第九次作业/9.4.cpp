#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int f(int n)
{
	if (n == 1)return 1;
	else if (n == 2)return 2;
	else return 2 * f(n - 1) + f(n - 2);
}

int main()

{
	int a, b, c;
	cin >> a;
	for (; a > 0; a--)
	{
		cin >> b;
		c = f(b);
		cout << c << endl;
	}
	system("pause");
	return 0;
}
