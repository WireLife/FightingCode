
#include<iostream>
using namespace std;
int Apple(int x, int y)
{
	if (x == 0|| y == 1)
	{
		return 1;
	}
	if (x < y)
		return Apple(x, x);
	else if(x>=y)
		return Apple(x, y - 1) + Apple(x - y, y);
}
	
int main()
{
	cout << "请输入测试数据的数目:\n";
	int n, x, y;
	cin >> n;
	while (n)
	{
		cout << "请输入数据:\n";
		cin >> x >> y;
		cout << "共有"<<Apple(x, y) << "种方案" << endl;
		n--;
	}
	cout << endl;
	system("pause");
	return 0;
}
