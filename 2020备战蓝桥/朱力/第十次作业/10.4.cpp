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
	printf("��%d�η����߶��ǣ�%lf hm\n", n, h(n));
	printf("��%d�����ʱ��������%lf hm\n", n, sum);
	return 0;
}