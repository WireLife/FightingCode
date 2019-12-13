#include<iostream>
using namespace std;
#define MaxSize 13
bool Check(char a[])
{
	int i, j, sum = 0;
	for (i=0, j=1; i<MaxSize-1; i++)      
	{
		if (i!=1&&i!=6&&i!=11)
		{
			sum=sum+(a[i]-'0')*j;
			j++;
		}		
	}
	if((a[MaxSize-1]-'0')==sum%11)    
		return true;
	else if(a[MaxSize-1]=='X')  
		return true;
	else
		return false;
}
int main()
{
	cout<<"请输入ISBN:";
	char code[MaxSize];
	cin>>code;
	if(Check(code))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}

