/*����߶�����*/
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
	cout << sum - h << ' ' << t; //�����һ��Ҳ�Ǵӵ��浯�����ڵ�n����غ����·����ÿ���ϵĹ��̺��µĹ���֮�ͣ�ȥ���������·�̾��Ǽ�ȥ��һ���ϵ�·��
	getchar();
	getchar();
	return 0;
}*/

//�������м����ֱ������ѧ��ʽ������
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double h;
	int n;
	cin >> h >> n;
	cout << (h*(1 - pow(1.0 / 2, n)) / (1 - 1.0 / 2)) * 2 - h << ' ' << h / pow(2, n);//�ȱ��������
	getchar();
	getchar();
	return 0;
}

