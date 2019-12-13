#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

int f(int a)
{
	int i,sum=0;
	if (a % 10 == 1 || a % 10 == 3 || a % 10 == 5 || a % 10 == 7)
		sum=sum+f(a / 10);
	if (a == 0)sum=sum+1;
	else return sum;
}


int main()
{
	int  i1,i2,i3,i4,i5,m1=0,m2,m3, n1,n2,sum,a;
	for (i1 = 1; i1 <= 4; i1++)
	{
		m1 = 2*i1-1;
		for (i2 = 1; i2 <= 4; i2++)
		{
			m2 = m1 * 10 + (i2 * 2 - 1);
			for (i3 = 1; i3 <= 4; i3++)
			{
				m3 = m2 * 10 + (i3 * 2 - 1);
				for(i4=1;i4<=4;i4++)
					{
						n1 = 2 * i4 - 1;
						for (i5 = 1; i5 <= 4; i5++)
						{
							n2 = n1 * 10 + (i5 * 2 - 1);
							a = m3 * n2;
							sum=f(a);
							if (sum == 1)cout << m3 << '*' << n2 << '=' << a<<endl;
						}
					}
			}
		}
	}
	system("pause");
	return 0;
}
