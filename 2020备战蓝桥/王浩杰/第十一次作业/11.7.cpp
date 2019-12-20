#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
	int n,p,q;
	string s1[1], s2[1];
	string a[3] = { "Rock", "Scissors", "Paper" };
	cin >> n;
	for (; n > 0; n--)
	{
		cin >> s1[0] >> s2[0];
		for (int i = 0; i < 3; i++)
		{
			if (s1[0] == a[i])p = i + 1;
			if (s2[0] == a[i])q = i + 1;
		}
		if (q == p)cout << "   Tie" << endl;
		else if ((p + q) == 4)
		{
			if(p>q)cout << "   Player1" << endl;
			else cout << "   Player2" << endl;
		}
		else if ((p - q + 1) == 0 || (p - q + 1) == 2) 
		{
			if (p > q)cout << "   Player2" << endl;
			else cout << "   Player1" << endl;
		}
	}
	system("pause");
	return 0;
}
