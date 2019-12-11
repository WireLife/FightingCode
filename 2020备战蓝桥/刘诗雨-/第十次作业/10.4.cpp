#include <iostream>
using namespace std; 
int main() 
{
	cout<<"总高度：";
	float h;
	cin>>h;
	cout<<endl;
	cout<<"次数：";
	int n;
	cin>>n;
	cout<<endl;
	float sum=h;
	for(int i=1;i<=n;i++)
	{
		h=h*(0.5);
		sum=sum+2*h;
	}
	cout<<"第"<<n<<"次反弹："; 
	cout<<h<<endl;
	cout<<"总路程："; 
	cout<<(sum-h*2)<<endl;
	return 0;
}
