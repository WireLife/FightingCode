#include<iostream>
#include<queue>
using namespace std;
//题目说闭合曲线，表示两点之间只有一个通路（上下左右）
//在外圈增加一层0，这样每个点都有四条路
int main()
{
	int a[12][12];
	for(int i=1;i<11;i++)
		for(int j=1;j<11;j++)
			cin>>a[i][j];
	for(i=0;i<12;i++)
	{
		a[0][i]=0;
		a[11][i]=0;
		a[i][0]=0;
		a[i][11]=0;
	}
	int area=0;
	//标记入栈下标
	int itag=0;
	int jtag=0;
	queue<int> q1,q2;
	for(i=1;i<11;i++)
	{
		if(!q1.empty()&&!q2.empty())
			break;
		for(int j=1;j<11;j++)
			if(a[i][j]!=0)
			{
				//将该点下面一点入栈，从头开始遍历不为0的点只有下面的点可能符合要求
				q1.push(i+1);
		    	q2.push(j);
				itag=i+1;
				jtag=j;
				break;
			}
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
