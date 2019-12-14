#include <iostream>
#include<cstring>
using namespace std;
int j;
int fun(int a[],int i,int len)
{
	int sum=0;
	for(j=i;j<len;j++)
	{
		sum=sum+a[j];
		if(sum==1898) 
		break;
		
	}
	return sum;
 } 
int main() {
	int a[1000];
	int n,m=1,i,h=0;
	cout<<2<<' ';
	a[0]=2;
	for(n=3;n<=1993;n++)
	{
	   	for(i=2;i<=n;i++)
	   {
		if(n%i==0)
		break;
	   }  
	   if(i==n)
	   {
	   	cout<<n<<' ';
		a[m]=n;
		m++;
	   }
	}
	cout<<endl;
	int *b=new int[m-1];
	for(i=1;i<m;i++)
	{
		b[i-1]=a[i]-a[i-1];
		cout<<(a[i]-a[i-1])<<' ';
	}
    for(i=0;i<m-1;i++){
    	if(fun(b,i,m-1)==1898)
    	h++;
    }
    cout<<endl;
    cout<<"×Ü¸öÊý£º"<<h;
	return 0;
}

