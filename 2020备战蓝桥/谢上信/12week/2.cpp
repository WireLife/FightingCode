#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

void Ducci(int x[100],int y,int z)
{
	int b[y], c;
	for (int i = 0; i < y-1; i++)
	{
		c = x[i] - x[i + 1];
		if (c < 0)
			c = -c;
		b[i] = c;
	}
	c = x[y] - x[1];
	if (c < 0)
		c = -c;
	b[y] = c;
	for(int i=0;i<100;i++)
	{
		if(b[i]!=0&&z<1000)
		{
			z+1;
			Ducci(b,y,z);
			i=0;
		}
		else if(z>=1000)
			{
			cout<<"LOOP";
			 break;
		}
		else
		{
			cout<<"ZEROLOOP";
			break;
		}
	}
}

int main()
{
	int a[100],d,e=0;
	for (int i = 0; i < 100; i++)
	{
		cin >> a[i];
		d = i;
		if (a[i] < 0)
			break;
	}
	Ducci(a,d,e);
	return 0;
}
