#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>

using namespace std;

void shan_chu_chong_fu_kong_ge(string &a)
{
	int h, f = 0;
	for (;;)
	{
		h = a.find(' ',f);
		if (h == -1)
			break;
		if (*(a.begin()+h+1) == ' ')
			a.erase(a.begin() + h);
		else
			f = h + 1;
	}
}

void shan_chu_shou_kong_ge(string &a)
{
	for (;;)
	{
		
		if (*(a.begin()) == ' ')
			a.erase(a.begin());
		else
			break;
	}
}

int main()
{
	int m = 0, n = 0, i, b = 0,d;
	string str[1001];
	for (i = 0; i <1000 ; i++)
	{
		getline(cin,str[i]);
		if (str[i] == "quit")
			break;
	}
	cout << endl;
	for (int j = 0; j < i; j++)
		shan_chu_shou_kong_ge(str[j]);
	for (int j = 0; j < i; j++)
		shan_chu_chong_fu_kong_ge(str[j]);
	for (;;)
	{
		for (int j = 0; j < i; j++)
		{
			m = str[j].find(' ', b);
			if (m > n)
				n = m;
		}
		d = n - m;
		if (n == -1)
			break;
		for (int j = 0; j < i; j++)
		{
			m = str[j].find(' ', b);
			str[j].insert(m, d, ' ');
			cout << str[j] << endl;
		}
		b = n + 1;
	}
	return 0;
}
