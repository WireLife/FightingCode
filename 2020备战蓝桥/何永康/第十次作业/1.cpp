
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[14];
	cin >> a;
	int b[10];
	int j = 0;
	int sum = 0;
	for (int i = 0; i < 13; i++)
	{
		if (a[i] != '-')
		{
			b[j++] = a[i] - '0';
		}
	}
	for (int i = 0; i < 9; i++)
		sum = sum + (i + 1) * b[i];
	if (sum % 11 == b[9])
		cout << "YES";
	else
		cout << "NO";


	return 0;
}
