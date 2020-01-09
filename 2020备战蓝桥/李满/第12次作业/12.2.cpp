#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int num,d[1001];
	cout<<"请输入数组元素个数：\n";
	cin>>num;
	cout<<"请依次输入数组元素值："; 
	for(;num>0;num--)  //输入n元组 
	{
		cin>>d[num];
	}
	
	//重复计算不多于1000次 
	int j;
	for(j=0;j<1000;j++)
	{
		int i,first;
	    first=d[0];
	    for(i=0;i<num;i++) 
	    {
		    d[i]=abs(d[i]-d[i+1]);
	    }
	    d[num]=abs(d[num]-first);
	}
	
	//判断是否循环 
	
		int k;
		for(k=0;k<num;k++)
		{
			if(d[k]!=0)
			{
				;
			}
			else
			{
			 cout<<"ZERO"<<endl;
			 continue;
			}
		}
		//cout<<"LEOP"<<endl;   //???这句话加在哪里 
	return 0;
 } 
 
