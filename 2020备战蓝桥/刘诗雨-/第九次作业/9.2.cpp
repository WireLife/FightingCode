#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;
void print(int am)
{
	if(am<10)
		cout<<am;
	else if(am==10)
		cout<<'A';
	else if(am==11)
		cout<<'B';
	else if(am==12)
		cout<<'C';
	else if(am==13)
		cout<<'D';
	else if(am==14)
		cout<<'E';
	else if(am==15)
		cout<<'F';
}
int main() {
	char two[100];
	cin>>two;
	int sum,i,j,am=0;
	sum=strlen(two);
	int *two1=new int[sum];
	for(i=0;i<sum;i++)
	{
		two1[i]=two[i]-'0';
	}
	int k1=0;
	if(sum%4==0)
	{
		for(i=0;i<sum/4;i++)
		{
            for(j=0;j<4;j++)
			{
				am=am+two1[k1+j]*(pow(2,3-j));							 
			}	
				print(am);	
				k1=k1+4;
				am=0; 
		}
	}
	else
	{
		int bm=0;
		int nm=4-sum%4;
		//cout<<nm;
		int *two2=new int[sum+nm];
		for(i=0;i<nm;i++){
			two2[i]=0;
		}
		for(i=0;i<sum;i++)
		{
			two2[nm+i]=two1[i];
		}


		sum=sum+nm;
		int k2=0;
	    for(i=0;i<sum/4;i++)
		{
            for(j=0;j<4;j++)
			{
				bm=bm+two2[k2+j]*(pow(2,3-j));							 
			}	
				print(bm);
				k2=k2+4;
				bm=0;	
		}	
	}
	//cout<<sum;
	return 0;
}
