#include<cstdio>
#include<iostream>
using namespace std;

double sum = 1;
double high=0.5;
double h(int n)
{
	if (n == 1){
		return high;
	}
		
	for (int i = 0; i < n-1; i++) {
		sum = sum + high * 2;
		high = high / 2;
	}
	return high;
}

int main()
{
	int n;
	cin >> n;
	printf("第%d次反弹高度是：%lf hm\n", n, h(n));
	printf("第%d次落地时，共经过%lf hm\n", n, sum);
	return 0;
}