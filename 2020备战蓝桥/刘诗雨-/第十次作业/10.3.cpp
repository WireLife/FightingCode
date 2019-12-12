#include <iostream>
#include<cstring>
using namespace std;
char a[1000];
int f=0;
int a1[10]={0,1,2,3,4,5,6,7,8,9};
char s1[10][10]={"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
int a8=0;
void kai(int *a2,int start,int len1,char *s5)
{
	if(start>=len1){
	int ii;
	for(ii=0;ii<a8;ii++){
	a[f++]=s5[ii];
    }
    a[f++]=',';
    a8--;
    return;
   }
int len=3;
if(a2[start]==7||a2[start]==9)
len=4;
int i=0;
for(i;i<len;i++)
 { 
	s5[a8++]=s1[a1[a2[start]]][i];
	kai(a2,start+1,len1,s5);
	a8=start;
 }
}
int main()
{
	std::string number;
	std::cin>>number;
	int n=number.size();
	int *arr=new int[n];
	int i;
	for(i=0;i<n;i++)
    {
    	arr[i]=number[i]-'0';
	}
    char s5[100];
    kai(arr,0,n,s5);
    puts(a);
    cout<<(strlen(a))/(n+1);
    return 0;
}
