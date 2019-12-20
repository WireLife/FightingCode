#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cout<<"输入字符串"<<endl;
	getline(cin,s);int a=0,b=0,c=0,d=0,e=0;
	int t=s.length();
	for(int i=0;i<t;i++)
	{
		if(s[i]==32)
			a++;
		else if(s[i]>47&&s[i]<58)
			b++;
		else if(s[i]>64&&s[i]<91)
			c++;
		else if(s[i]>96&&s[i]<123)
			d++;
		else e++;
	}
	cout<<"空格的个数是"<<a<<"\n"
		<<"数字的个数是"<<b<<"\n"
		<<"大写字母的个数是"<<c<<"\n"
		<<"小写字母的个数是"<<d<<"\n"
		<<"其他字符的个数是"<<e<<endl;
	return 0;
}