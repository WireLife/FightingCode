
#include<iostream>
using namespace std;
void Pell(int n)
{
	int a[100] = { 1,2 };
	if (n == 1 || n == 2)
		cout << a[n - 1];
	else 
	{
		int i = 1;
		while (i != n - 1)
		{
			i++;
			a[i] = 2 * a[i-1] + a[i-2];
		}
		cout <<"第"<<n<<"项的值为:"<< a[i]<<endl;
	}
}
int main()
{
	int n;
	cout << "input the number:\n";
	cin >> n;
	Pell(n);
	system("pause");
	return 0;
}
