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
	int n=0,a1=0,a2=0,a3=0,a4=0,a5=0;
	char a='0';
	while(a!='\n')
	{
		a = cin.get();
		if (65 <= a && a <= 90)a1++;
		else if (97 <= a&& a <= 122)a2++;
		else if (48 <= a && a <= 57)a3++;
		else if (a == ' ')a4++;
		else if (a == '\n');
		else a5++;
	}
	cout << "大写字母个数：" << a1 << endl;
	cout << "小写字母个数：" << a2 << endl;
	cout << "数字个数：" << a3 << endl;
	cout << "空格个数：" << a4 << endl;
	cout << "其他个数：" << a5 << endl;
	system("pause");
	return 0;
}
