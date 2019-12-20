#include<string>
#include<iostream>
using namespace std;

int main()
{
	string str;
	char ch;
	int i=0;
	scanf("%c",&ch);
	while(ch!='\n')
	{
	    str=str+ch;
		scanf("%c",&ch);
	}
    cout<<str<<endl;
    return 0;
}
