#include<iostream>
#include<malloc.h>
using namespace std;

int f(int m,int n,int max,int max1)
{
	int i,sum=0,a;
	if ((n == 0) && (m == 0))return 1;
	else if (n == 0)return 0;
    else
	{	
		a = m % n;
	    if (a == 0)max = m / n;
	    else max = m / n + 1;
		if (m == 0)return 1;
		else if(m<=max1)
		{
			for (i = m; i >= max; i--)
			{
				sum = sum + f(m - i, n - 1,max , max1);
			}
		}
	}
	return sum;
}
int main()
{
	int m,n, a,max1,i,K;
	cin >> K;
	for (; K > 0; K--)
	{
		int sum = 0;
		cin >> m >> n;
		a = m % n;
		if (a == 0)max1 = m / n;
		else max1 = m / n + 1;
		for (i = m; i >= max1; i--)
		{
			if (m - i <= max1)sum = sum + f(m - i, n - 1, m - i, max1);
			else sum = sum + 1 + (m - a * max1) / max1;
		}
		cout << sum<<endl;
	}
	system("pause");
	return 0;
}
