#include<iostream.h>
#include<vector>
#include<string.h>
int main()
{
	int n,i,j;
	cin>>n;
	int *arr1=new int[n];
	int *arr2=new int[n-1];
	for(i=0;i<n;i++)
	{
		arr1[i]=i+1;
	}
	for(i=0;i<n-1;i++)
	{
		arr2[i]=arr1[0];
        for(j=0;j<n-i+1;j++)
		{
			arr1[j]=arr1[1+j];
		}
		int temp=arr1[0];
		for(j=0;j<n-i-1;j++)
		{
			arr1[j]=arr1[j+1];
		}
		arr1[n-i-2]=temp;
	}
	cout<<"Discarded cards:";
	for(i=0;i<n-1;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;
	cout<<"Remaining card:"<<arr1[0]<<endl;
	return 0;
}