#include <iostream>
#include <stdio.h>
using namespace std;

int h[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)           
	{
		h[i] = 1;                     
		for (int j = 1; j <= i / 2; j++)    
			h[i] += h[j];
	}
	cout << h[n];
	return 0;
}


/*
int main()
{
	int n;
	int a[1100];

	cin >> n;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 0)
			a[i] = a[i - 1] + a[i / 2];
		else
			a[i] = a[i - 1];
	}
	cout << a[n] << endl;
	return 0;
}


/*
int ni(int a)
{
	int k = 0;
	if (a < 10) {
		k = a;
	}
	else if (a < 100) {
		while (a >= 10) {
			k = a % 10;
			a = a / 10;
			k = k * 10 + a;
		}
	}
	return k;
}



int f(int a)
{
	int ni(int);
	a = ni(a);
	int ban = a / 2;
	for (int i = 1; i < ban; i++) {
		a = a * 10 + i;
		if (a < 1000)
			printf("%d", ni(a));
	}
	return 0;
}




int main()
{
	int ni(int);
	int a;
	cin >> a;
	f(a);

	return 0;

}
/*
int num = 1;
int pan(int a)			//判位操作函数
{
	if (a < 10)
		return 10;
	else if (a < 100)
		return 100;
}

int f(int a)			//移位函数
{
	int pan(int);
	int i;
	for (i = 1; i < a / 2; i++) {
		if ((pan(a) * i + a) < 1000) {
			num++;
			printf("NO.%d:%d\n", num, (pan(a) * i + a));
			f()
		}
	}
	return 0;
}


int main()
{
	int f(int);
	int a;
	cin >> a;
	cout <<"NO.1:"<<a << endl;
	f(a);
	return 0;
}
*/