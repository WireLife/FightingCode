#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int q[100][100];
int p[100][100];
int w[100],T[100],Y[100];
void f1(int a,int b)
{
	int j;
	for (int i = 0; i <= b; i++) {
		int min = i;
		for (j = i + 1; j <= b; j++) {
			if (p[a][min] > p[a][j]) min = j;
		}
		//交换
		int temp = p[a][i];
		p[a][i] = p[a][j];
		p[a][j] = temp;
	}
}
int f()
{
	int b,n,m,o=0;
	int a,j=3,d;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> n>>m;
		T[m + 50]++;
		if (T[m + 50] == 1)
		{
			Y[o] = m + 50;
			o++;
		}
		q[m+50][n+50] = 1;
		p[m + 50][w[m+50]] = n;
		w[m + 50]++;
	}
	for (int i = 0; i <= o; i++)
	{
		a = Y[i];
		f1(a,w[a]-1);
		if (w[a] % 2 == 0)
		{
			for (int h = 0; h < w[a] / 2; h++)
			{
				if (h == 0) d = p[a][h] + p[a][w[a] - h - 1];
				else if (p[a][h] + p[a][w[a] - h - 1] == d) j = 1;
				else
				{
					j = 0;
					break;
				}
			}
			if (j == 0)break;
		}
		else
		{
			for (int h = 0; h < w[a] / 2; h++)
			{
				d = p[a][w[a] / 2 + 1];
				if (p[a][h] + p[a][w[a] - h - 1] == d) j = 1;
				else
				{
					j = 0;
					break;
				}
			}
			if (j == 0)break;
		}
	}
	return j;
}

int main()

{
	int a, b;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
	    b=f();
		if (b = 0)cout << "NO";
		else cout << "YES";
	}
	system("pause");
	return 0;
}
