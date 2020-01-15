//在原本的二维组外添加一层值为2的起始收缩圈
//可以通过收缩圈来确定面积，圈的收缩以为0重新赋值2来进行
//收缩的条件是在二维数组中，以0为中心的十字架内若有2则把0改为2，以此进行收缩
#include<iostream>
using namespace std;
int main()
{
	int a[12][12];
	int i,j;  //索引
	int sum=0;  //计数器
//起始收缩圈
	for(i=0;i<12;i++)
		a[i][0]=2;
	for(i=0;i<12;i++)
		a[i][11]=2;
	for(j=1;j<11;j++)
		a[0][j]=2;
	for(j=1;j<12;j++)
		a[11][j]=2;
//输入数据
	cout<<"请输入:"<<endl;
	for(i=1;i<11;i++)
		for(j=1;j<11;j++)
			cin>>a[i][j];
//收缩
//从头到尾，从尾到头,确保收缩到最小
	for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
			if(a[i][j]!=1)
			{
				if(a[i-1][j]==2||a[i][j-1]==2||a[i][j+1]==2||a[i+1][j]==2)  //十字架判断
					a[i][j]=2;
			}
	}
	for(i=10;i>0;i--)
	{
		for(j=10;j>0;j--)
			if(a[i][j]!=1)
			{
				if(a[i-1][j]==2||a[i][j-1]==2||a[i][j+1]==2||a[i+1][j]==2)  //十字架判断
					a[i][j]=2;
				else
					sum++;  //计数
			}
	}
 /*   for(i=0;i<12;i++)       //测试输出
	{
		for(j=0;j<12;j++
	cout<<a[i][j]<<' ';
		cout<<endl;
	}*/
	cout<<sum<<endl;
	return 0;
}
