/*弹球高度问题*/
/*
#include<iostream>
using namespace std;
int main()
{
	float h, t, sum = 0;
	int n;
	cin >> h >> n;
	t = h;
	for (int i = 0; i < n; i++)
	{
		sum += t * 2;
		t = t / 2;
	}
	cout << sum - h << ' ' << t; //假设第一次也是从地面弹起，则在第n次落地后算的路程是每次上的过程和下的过程之和，去掉假设后总路程就是减去第一次上的路程
	getchar();
	getchar();
	return 0;
}*/

//不用算中间过程直接用数学公式算出结果
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double h;
	int n;
	cin >> h >> n;
	cout << (h*(1 - pow(1.0 / 2, n)) / (1 - 1.0 / 2)) * 2 - h << ' ' << h / pow(2, n);//等比数列求和
	getchar();
	getchar();
	return 0;
}

