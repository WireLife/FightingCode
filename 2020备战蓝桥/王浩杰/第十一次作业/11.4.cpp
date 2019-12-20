#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

void f()
{

}


int main()
{
	int a3 = 0;
	char a = '0';
	while (a != '\n')
	{
		a = cin.get();
		if (48 <= a && a <= 57)a3++;
	}

	cout << "数字个数：" << a3 << endl;

	system("pause");
	return 0;
}
