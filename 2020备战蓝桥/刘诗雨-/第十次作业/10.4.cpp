#include <iostream>
using namespace std; 
int main() 
{
	cout<<"�ܸ߶ȣ�";
	float h;
	cin>>h;
	cout<<endl;
	cout<<"������";
	int n;
	cin>>n;
	cout<<endl;
	float sum=h;
	for(int i=1;i<=n;i++)
	{
		h=h*(0.5);
		sum=sum+2*h;
	}
	cout<<"��"<<n<<"�η�����"; 
	cout<<h<<endl;
	cout<<"��·�̣�"; 
	cout<<(sum-h*2)<<endl;
	return 0;
}
