/*11.5.4统计字符串中的数字个数*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int cnt=0;
	string str;
	cin>>str;
	for(int i=0;i<=str.length();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
