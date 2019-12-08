/*7、判断元素是否存在（信息学奥赛一本通-T1211）*/

//思路：首先k是M中的元素，那么2k+1和2k+3也是M中的元素，那么2(2k+1)+1，2(3k+1)+1也是M中的元素....所以只用判断x能否用含k的这个函数是表达 
//如果有一元素K，k的下两级元素为2K+1和3k+1,k的上两级元素为(k-1)/2和(k-1)/3 
/*
#include<iostream>
using namespace std;
int x;
int f(int k);
int main()
{
	int k,x;
	cin>>k>>x;
	if(f(k)) cout<<f(k)<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
 } 

//x>k
int f(int k){
	//cout<<k<<endl; 
	if(k==x&&k>0) return 1;
	if(k<x&&x<100000)
	{
		f(2*k+1);
		f(3*k+1);
	}
	if(k>x&&k>0)
	{
		return f((k-1)/2)||f((k-1)/3);
	}	
	return 0;
		
}*/

//考虑K的元素集合边界不好找，从x的角度入手
#include<iostream>
using namespace std;
int x,k;
int f(int k);
int main()
{
	cin>>k>>x;
	if(f(x)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
 } 


int f(int x){
	//cout<<x<<endl;
	int sum=0; 
	if(x==k) return 1;
	if(x>k&&x>0)
	{
		if((x-1)%2==0)
		{
			sum+= f((x-1)/2); //不能返回这么早，要把所有的都遍历完才可以的，不然一直运行这里直到不满足条件的时候就返回0了 
			if(sum!=0) return 1;
		}
		 
		if((x-1)%3==0)
		{
			sum+=f((x-1)/3);
			if(sum!=0)return 1; 
		}
	}
	if(x<k)
	{
		if(x<=(k-1)/2)
		{
			sum+=f(2*x+1);
			if(sum!=0) return 1;
		}
		if(x<=(k-1)/3)
		{
			sum+=f(3*x+1);
			if(sum!=0) return 1;
		}	
	}	
	return 0;
}
