#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	char ch;
	while(ch!='\n')
	{
		ch=getchar();
		str+=ch;
	}
	cout << str <<endl;
	return 0;
}