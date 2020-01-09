#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "请输入两所学校交换生数量:";
	cin >> a >> b;
	if (a == b)
		cout << "可以交换";
	else
	{
		cout << "不可交换";
	}
	return 0;
}