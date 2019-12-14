/*#include <iostream>
using namespace std;
int main()
{
	int a, b;
	int i[1000];
	int k, m;
	int n = 0;
	for (a = 2; a <= 1993; a++)
	{
		for (b = 2; b <= a / 2; b++)
		{
			if (a%b == 0)
				break;
		}
		if (b == a / 2 + 1)
		{
			i[n] = a;
			cout << i[n] << endl;
			n = n + 1;
		}
	}
	for (m = 0; i[m] <= 95; m++)
	{
		for (k = n - 1; i[k] >= 1898; k--)
		{
			if (i[k] - i[m] == 1898)
				cout << i[m] << " " << i[k] << endl;
		}
	}
	system("pause");
	return 0;
}
*/
