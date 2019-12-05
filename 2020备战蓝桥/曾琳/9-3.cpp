
#include<iostream>
using namespace std;
int ans;
void dfs(int m)                           //统计m所扩展出的数据个数
{
	int i;
	ans++;                                  //每出现一个原数，累加器加1；
	for (i = 1; i <= m / 2; i++)         //左边添加不超过原数一半的自然数，作为新原数
	dfs(i);
}
int main()
{
	int n;
	cin >> n;
	dfs(n);
	cout << ans << endl;
	system("pause");
	return 0;
}
