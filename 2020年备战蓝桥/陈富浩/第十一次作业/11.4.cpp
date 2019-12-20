#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a=0,i;
	string str;
	cout<<"输入一行字符串："<<endl;
	getline(cin,str);
	for(i=0;i<=str.length();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			a++;
	}
	cout<<"数字字符个数："<<a<<endl;
	return 0;
}
