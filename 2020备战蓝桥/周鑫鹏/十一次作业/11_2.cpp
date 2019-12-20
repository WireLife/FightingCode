#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1,str2,str;
	cout << "Enter a string" <<endl;
	cin >> str1;
	cout << "Enter another string " <<endl;
	cin >> str2;
	str=str1+str2;
	cout << str <<endl;
	return 0;
}