#include<iostream>
using namespace std;
int k;
int cunzai(int x)
{
	if (x == k)
		return 1;
	if ((x - 1) % 3 == 0 && (x - 1) % 2 == 0)
		return (cunzai((x - 1) / 3) || cunzai((x - 1) / 2));
	if ((x - 1) % 3 == 0)
		return cunzai((x - 1) / 3);
	if ((x - 1) % 2 == 0)
		return cunzai((x - 1) / 2);
	return 0;
}
int main()
{
	int x;
	cin >> k >> x;
	if (cunzai(x))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
