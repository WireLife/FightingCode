#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;
char a[1000];

void Gets()
{
	char m;
	int n=0;
	while(1)
	{
		m = _getch();
		a[n] = m;
		n++;
		if (m== '\r')break;
	}

}


int main()
{
	Gets();
	system("pause");
	return 0;
}
