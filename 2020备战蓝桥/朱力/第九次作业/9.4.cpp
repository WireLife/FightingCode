#include<stdio.h>
#include<iostream>

using namespace std;
int a[10000] = {0};

int f(int k)
{
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= k; i++)
		a[i] = (2 * a[i - 1] + a[i - 2]);
	return a[k];
}

int main()
{
	int k, n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		printf("%d\n",f(k));
	}

	return 0;
}