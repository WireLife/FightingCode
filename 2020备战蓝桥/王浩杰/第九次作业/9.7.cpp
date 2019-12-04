#include<iostream>
#include<cstdio>
using namespace std;

int f(int m,int n)
{
	int sum = 0;
	if (m == n)
	{
		return 1;
	}
	else if (m > n)return 0;
	else
	{
		if (m < 100000)
		{
			sum=sum+f(2 * m + 1,n);
			if (sum != 0)return 1;
			sum=sum+f(3 * m + 1,n);
			if (sum != 0)return 1;
		}
	}
	return sum;
}
int main()
{
	int k, x,sum;
	scanf("%d,%d", &k, &x);
	if (k > x)sum = f(x, k);
	else sum = f(k,x);
	if (sum == 0)cout << "NO";
	else cout << "YES";
	system("pause");
	return 0;
}
