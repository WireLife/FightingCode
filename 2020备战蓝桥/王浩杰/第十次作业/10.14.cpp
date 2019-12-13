#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;

void f()
{
	int n, k,a,b;
	cin >> n >> k;
	while (1)
	{
		cin >> a;
		n = n - a;
		if (n <= 1)
		{
			cout << "玩家失败" << "**********************************************************************************"<<endl;
			break;
		}
		b = rand() % k + 1;
		cout << endl << b;
		n = n - b;
		if (n <= 1)
		{
			cout << "玩家胜利" << "**********************************************************************************" << endl;
			break;
		}
	}
}


int main()
{
	int n=0,a=0;
	while (1)
	{
		n++;
		f();
		cout << "1.进行下一局" << endl << "2.退出" << endl;
		cin >> a;
		if (a == 2)break;
	}
	cout << endl <<"共进行"<< n<<"局" << endl;
	system("pause");
	return 0;
}
