#include<iostream>
#include<string>
using namespace std;
//The function "gets" could include the character ' ' but character '\n';
int main()
{
	char c;
	string str="";
	while(1)
	{
		scanf("%c",&c);   //here doesn't use 'cin';
		if(c=='\n')
			break;
		str=str+c;
	}
	cout<<str<<endl;
	return 0;
}

