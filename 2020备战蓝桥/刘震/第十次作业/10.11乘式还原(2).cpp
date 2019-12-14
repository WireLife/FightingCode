/*10.11乘式还原(2)*/
//思路：暴力破解

#include<iostream>
using namespace std;

//判断一个数的每一位是否是1，2, 3，5，7；
bool f(int n);

int main()
{
	int i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, x1, s[5] = { 1,2,3,5,7 };
	for (i1 = 1, j1 = 1; i1 <= 7; i1 = s[j1++])
	{
		x1 = i1;
		for (i2 = 1, j2 = 1; i2 <= 7; i2 = s[j2++])
		{
			for (i3 = 1, j3 = 1; i3 <= 7; i3 = s[j3++])
			{
				x1 = ((i1 * 10) + i2) * 10 + i3;
				for (i4 = 1, j4 = 1; i4 <= 7; i4 = s[j4++])
				{
					if ((x1 * i4) / 1000 > 0 && f(x1 * i4))
					{	
						for (i5 = 1, j5 = 1; i5 <= 7; i5 = s[j5++])
						{
							if ((x1 * i5) / 1000 > 0 && f(x1 * i5))
							{	
								if (f(x1 * i4 * 10 + x1 * i5))
								{	
									cout << "   " << i1 << i2 << i3 << endl;
									cout << "X   " << i4 << i5 << endl;
									cout << "--------" << endl;
									cout << "  " << x1 * i5 << endl;
									cout << " " << x1 * i4 << endl;
									cout << "--------" << endl;
									cout << " " << x1 * i4 * 10 + x1 * i5 << endl << endl;
									cout << "********************************************" << endl << endl;
								}	
							}
						}
					}
				}
			}
		}	
	}
	system("pause");
	return 0;
}

bool f(int n)
{
	int temp;
	for (int i = 0; n != 0; i++)
	{
		temp = n % 10;
		if (!(temp == 1 || temp == 3 || temp == 5 || temp == 7 || temp == 2))
			return false;
		n /= 10;
	}
	return true;
}