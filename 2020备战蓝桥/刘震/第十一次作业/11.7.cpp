#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	//cout<<"十进制输出时："<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cout<<a<<'\t'<<hex<<b<<'\t'<<oct<<c<<endl;
	return 0;
}
//input: 
//23 23 23 23
//output:
//23      17      27