#include<iostream>
#include<string>
using namespace std;
int main()
{
	int stu[50000];
	int a,b;
	int n,j;
	long i;
	long na=20000;
	cout<<endl;
	for(i=0;i<na;i++)
	{
		stu[i]=1;
	}
	for(i=na;i<50000;i++)
	{
		stu[i]=2;
	}
	cout<<"����Ҫ������������";
	cin>>n;
	cout<<endl;
	for(j=0;j<n;j++)
	{
		cout<<"���뽻��ѧ���ı��:";
		cin>>a>>b;
		swap(stu[a],stu[b]);
		if(stu[a]==stu[b])
			cout<<"NO"<<endl;
		else if(stu[a]!=stu[b])
			cout<<"Yes"<<endl;
	}
	return 0;
}