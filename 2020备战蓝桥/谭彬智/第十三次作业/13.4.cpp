#include<iostream>
#include<queue>
using namespace std;

int main()//题目说闭合曲线，表示两点之间只有一个通路（上下左右）
{
	int a[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			cin>>a[i][j];
	int area=0;
	int itag=0;
	int jtag=0;
	queue<int> q1,q2;
	for(i=1;i<9;i++)
		for(int j=1;j<9;j++)
			if(a[i][j]!=0)
			{
				q1.push(i+1);
		    	q2.push(j);
				itag=i+1;
				jtag=j;
			}
	while(!q1.empty()&&!q2.empty())
	{
		i=q1.front();
		int j=q2.front();
		q1.pop();
		q2.pop();
		if(a[i][j]==0)
		{
			if(a[i-1][j]==1&&a[i][j-1]==1&&a[i+1][j]==1&&a[i][j+1]==0)//right
			{
				area++;
				a[i][j]=1;
				q1.push(i);
				q2.push(j+1);
			}
			else if(a[i-1][j]==0&&a[i][j-1]==1&&a[i+1][j]==1&&a[i][j+1]==1)//high
			{
				area++;
				a[i][j]=1;
				q1.push(i-1);
				q2.push(j);
			}
			else if(a[i-1][j]==1&&a[i][j-1]==0&&a[i+1][j]==1&&a[i][j+1]==1)//left
			{
				area++;
				a[i][j]=1;
				q1.push(i);
				q2.push(j-1);
			}
			else if(a[i-1][j]==1&&a[i][j-1]==1&&a[i+1][j]==0&&a[i][j+1]==1)//low
			{
				area++;
				a[i][j]=1;
				q1.push(i+1);
				q2.push(j);
			}
			else if(a[i-1][j]==1&&a[i][j-1]==1&&a[i+1][j]==1&&a[i][j+1]==1)
				cout<<++area<<endl;
			else
			{
				area=0;
				if(jtag!=8)
				{
			    	q1.push(itag);
			    	q2.push(++jtag);
				}
				else if(jtag==8)
				{
					q1.push(++itag);
					q2.push(1);
				}
			}
		}
		else if(a[i][j]==1)
		{
			q1.push(i);
			q2.push(j+1);
			jtag++;
		}
	}
	return 0;
}
