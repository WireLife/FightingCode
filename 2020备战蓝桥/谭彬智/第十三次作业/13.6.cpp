#include<iostream>
#include<queue>
using namespace std;

int level(int n,int k,int *x,int *y)
{
	int tag=1;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		if(q.front==n)
		{
			tag--;
			q.pop();
		}
		if(n<10)
			for(int i=1;i<=k;i++)
				if(n==x[i])
				{
					n=y[i];
					tag++;
					q.push(n);
				}
		if(n>=10&&n<100)
		{
			int a=n/10;
			int b=n%10;
			for(int i=1;i<=k;i++)
			{
				if(a==x[i])
				{
					a=y[i];
					tag++;
					q.push(a*10+b);
				}
				if(b==x[i])
				{
					b=y[i];
					tag++;
					q.push(a*10+b);
				}
			}
		}
		if(n>=100&&n<1000)
		{
			int a=n/100;
			int b=(n/10)%10;
			int c=n%10;
			for(int i=1;i<=k;i++)
			{
				if(a==x[i])
				{
					a=y[i];
					tag++;
					q.push(a*100+b*10+c);
				}
				if(b==x[i])
				{
					b=y[i];
					tag++;
					q.push(a*100+b*10+c);
				}
				if(c==x[i])
				{
					c=y[i];
					tag++;
					q.push(a*100+b*10+c);
				}
			}
		}
		if(n>=1000&&n<=2000)
		{
			int a=n/1000;
			int b=(n/100)%10;
			int c=(n/10)%10;
			int d=n%10;
			for(int i=1;i<=k;i++)
			{
				if(a==x[i])
				{
					a=y[i];
					tag++;
					q.push(a*1000+b*100+c*10+d);
				}
				if(b==x[i])
				{
					b=y[i];
					tag++;
					q.push(a*1000+b*100+c*10+d);
				}
				if(c==x[i])
				{
					c=y[i];
					tag++;
					q.push(a*1000+b*100+c*10+d);
				}
				if(d==x[i])
				{
					d=y[i];
					tag++;
					q.push(a*1000+b*100+c*10+d);
				}
			}
		}
	}
	return tag;
}

				

int main()
{
	int n,k;
	cin>>n>>k;
	int *x=new int[k+1];
	int *y=new int[k+1];
	for(int i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	cout<<level(n,k,x,y)<<endl;
	delete []x;
	delete []y;
	return 0;
}
