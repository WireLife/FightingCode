#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin,str);int i=0,t=0;
	while(str[i]!='\0')
	{
		if(str[i]>47&&str[i]<58)
			t++;
		i++;
	}
	cout<<t<<endl;
	return 0;
}