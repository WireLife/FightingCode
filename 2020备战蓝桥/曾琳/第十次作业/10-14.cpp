/*#include<iostream>
using namespace std;
int option, flag = 0,tem;
int counter;
int i = 0;
int result[] = { 0 };
void Menu()
{
	cout << "输入你的操作：（1.开始比赛；2.结束比赛）" << endl;
	cin >> option;
}
void Contest(int n, int k)
{
	counter++;
	int tem;
	int left = n;
	int computer;
	cout << "游戏开始!" << endl;
	do
	{
		cout << "请输入你要搬的山的总数：" << "" << endl;
		cin >> tem;
		while (tem > k || tem < 0)
		{
			cout << "输入有误!" << endl;
			cout << "请输入你要搬的山的总数：" << "" << endl;
			cin >> tem;
		}
		left -= tem;
		if (left == 1)
		{
			cout << "你赢了！" << endl;
			return;
		}
		computer = (left - 1)&(k + 1);
		if (computer == 0||computer>k)
			computer = 1;
		left -= computer;
		cout << "电脑要搬" << computer << "座山" << endl;
		cout << "现在还有" << left << "座山可以移动。" << endl;
		if (left == 1)
		{
			cout << "你输了！" << endl;
			result [counter-1]= 1;
			return;
		}
	} while (left);
	if (result[counter - 1] = 0)
		cout << "你赢了！" << endl;
	
}
int main()
{
	cout << "游戏开始!" << endl;
	while (1)
	{
		Menu();
		if (option == 1)
		{
			counter++;
			cout << "请输入山的总数：" << endl;
			int n;
			cin >> n;
			cout << "请输入最大上限k:" << " ";
			int k;
			cin >> k;
			Contest(n,k);
		}
		if (option == 2)
		{
			if (counter != 0)
			{
				cout << "一共玩了" << counter << "局！" << endl;
				for (int i = 0; i < counter; i++)
					cout << "第" << i + 1 << "局的赢家是：" << result[i] << endl;
			}
			return 0;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/
