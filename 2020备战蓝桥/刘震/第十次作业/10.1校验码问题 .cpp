/*校验码问题*/
/*思路：构造一个函数来判断是否为有效的校验码，*/

#include<iostream>
using namespace std;

const int N = 13;	//0-0000-0000-0
//ISBN存放的位置
char code[N];
//校验函数
int CheckCode(char str[]);
int main()
{
	cin >> code;
	if (CheckCode(code))
		cout << "正确";
	else
		cout << "错误";

	getchar();
	getchar();
	return 0;
}

int CheckCode(char str[])
{
	int i, j, sum = 0;
	for (i = 0, j = 0; i < N - 1; i++)      
	{
		if (i != 1 && i != 6 && i != 11)
			sum += (str[i] - '0')*(++j);
	}
	if (sum % 11 == /*(int)*/(str[N - 1] - '0'))    //校验位在0-9时
		return 1;
	else if (str[N - 1] == 'X' || str[N - 1] == 'x')  //如果余数不在0-9，那么再判断是不是X
		return 1;
	else
		return 0;
}