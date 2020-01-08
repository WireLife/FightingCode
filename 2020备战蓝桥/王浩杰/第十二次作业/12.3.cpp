
#include <iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> a;
	int n,sum=0,f;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a.push(i);
	}
	while (sum != 1)
	{
		f = a.front();
		cout << f << ' ';
		a.pop();
		f = a.front();
		a.pop();
		a.push(f);
		sum = a.size();
	}
	cout << endl<< a.front();
	system("pause");
	return 0;
}
