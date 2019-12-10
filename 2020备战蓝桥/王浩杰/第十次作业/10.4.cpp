#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;


float f(float h, float n)
{
	float  sum=0;
	if (n == 0)
	{
		sum = sum + h ;
		cout << h << endl;
	}
	else
	{
		sum = sum + h + f(h / 2, n - 1);
	}
	return sum;

}

int main()
{
	float h,n,sum;
	cin >> h >> n;
	sum=f(h/2,n-1)+h;
	cout << sum << endl;
	system("pause");
	return 0;
}
