#include<iostream>
using namespace std;
unsigned int k,x;
bool flag;
bool dfs(int a,int b)
{
	if(a>b)return false;
	if(a>100000)return false;
	if(a==b)return true;
	flag=dfs(a*2+1,b)||dfs(3*a+1,b);
	return flag;
}
int main()
{
	scanf("%d,%d",&k,&x);
	if(dfs(k,x)==true){
		cout<<"YES"<<endl;
		return 0;
	}
	cout<<"NO"<<endl;
	return 0;
}
