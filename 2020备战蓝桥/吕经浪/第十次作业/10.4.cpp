#include<iostream>
using namespace std;
int main()
{
	double h, x = 0;
	int n;
	cin >> h >> n;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		x += h;            //落下的路程
		h = h / 2;
		if (i != n - 1)     //在最后一次的时候， 不反弹。
			x += h;        //加反弹路程
	}
	cout << x << endl;
}
