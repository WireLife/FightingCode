#include<iostream>
using namespace std;
char a[55];
double RPolish ()
{
	cin >> a;
	if (a[0] == '+')
		return RPolish() + RPolish();
	else if (a[0] == '-')
		return RPolish() - RPolish();
	else if (a[0] == '*')
		return RPolish() * RPolish();
	else if (a[0] == '/')
		return RPolish() / RPolish();
	else
		return atof(a);
}
int main()
{
	cout << RPolish() << endl;
	return 0;
}
