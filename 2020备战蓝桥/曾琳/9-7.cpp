
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int k, x;
bool f(int y) {
	if (y > x)return false;
	if (y == x)return true;
	if (f(2 * y + 1) || f(3 * y + 1))return true;
	return false;
}
int main()
{
	cout << "输入K和N值:\n";
	cin >> k;
	cin.get();
	cin >> x;
	int a = k;
	bool b = f(a);
	if (b)cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}
