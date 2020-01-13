#include<iostream>
#include<queue>
using namespace std;

int level(int x,int n,int a,int b,int *p)
{	
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		a=q.front();
		q.pop();
		if(a==b)return x;
		if((a-p[a]<=0)&&(a+p[a]>n))return -1;			
		if(a-p[a]>0)q.push(a-p[a]);
		if(a+p[a]<=n)q.push(a+p[a]);
		x++;
	}
}

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int *p=new int[n+1];
	for(int i=1;i<n+1;i++)
		cin>>p[i];
	cout<<level(0,n,a,b,p)<<endl;
	delete []p;
	return 0;
}
