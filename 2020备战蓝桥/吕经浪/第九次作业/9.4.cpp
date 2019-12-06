#include <iostream>
using namespace std;
int num[100000 + 1];
int pell(int n)
{
	if (n < 3)
	{
		return n;
	}
	if (num[n] == 0)
	{
		num[n] = (2 * pell(n - 1) + pell(n - 2));
	}
	return num[n] % 32767;
}
int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num[i];
	}
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << pell(num[i]) << endl;
	}
	return 0;
}
