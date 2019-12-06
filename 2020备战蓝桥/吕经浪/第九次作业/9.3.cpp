#include<iostream>
using namespace std;
int num = 0;
void jishu(int n)
{
	int i;
	num++;
	for (i = n / 2; i >= 1; i--)
	{
		jishu(i);
	}
}
int main()
{
	int n;
	cin >> n;
	jishu(n);
	cout << num << endl;
	return 0;
}
