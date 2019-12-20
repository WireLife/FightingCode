#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a=0,b=0,c=0,d=0,e=0,i;
    string str;
    cout<<"输入一个字符串："<<endl;
	getline(cin,str); 
	for(i=0;i<str.length();i++)
    {
	  if(str[i]>='A' && str[i]<='Z')
		  a++;
	  else if(str[i]>='a' && str[i]<='z')
		  b++;
	  else if(str[i]>='0'&&str[i]<='9')
		  c++;
	  else if(str[i]==' ')
		  d++;
	  else
		  e++;
    }
    cout<<"大写字母个数："<<a<<endl;
    cout<<"小写字母个数："<<b<<endl;
    cout<<"数字个数："<<c<<endl;
    cout<<"空格个数："<<d<<endl;
    cout<<"其他字符个数："<<e<<endl;
    return 0;
}
