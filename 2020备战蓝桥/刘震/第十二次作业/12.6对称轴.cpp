/*�ж�ƽ���ϵ�һ��㣬�Ƿ����һ�����߶Գơ����ҵ�һ����ֱ�Գ���*/

//˼·���Գ����������к�����֮�͵�ƽ��ֵ��Ȼ����ÿһ�����Ƿ����ߵ���һ��Ҳ��
/*
#include<iostream>
#include<map>
using namespace std;

const int maxn = 1000;

//�Ȳ�������һ��

int main()
{
	map<double, double>s;
	int i, k = 0, n, bol[1000] = { 0 };
	double x, y, xSum = 0, Symmetry, jSum = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		s[x] = y;
		xSum += x;
	}
	Symmetry = xSum / n;

	for (map<double, double>::iterator i = s.begin(); i != s.end(); i++)
	{
		if (i->first < Symmetry) //�����������ڶԳ�������ʱ,Ҫ�鿴�Ҳ��Ƿ���yֵ��ͬ�ĵ�ͨ��key����
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)  //�������е㣬ֻ�������ұߵĵ�
			{
				if (j->first > Symmetry)
					if (s[i->first + (Symmetry - i->first) * 2] == s[j->first]) //ͨ���Ƚ����ߵ�yֵ���ж��Ƿ���
					{
						k++;
						break;
					}
			}
		}
		else if (i->first > Symmetry)
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)
			{
				if (j->first < Symmetry)
					if (s[i->first - (i->first - Symmetry) * 2] == s[j->first]) //ͨ���Ƚ����ߵ�yֵ���ж��Ƿ���
					{
						cout << s[i->first - (i->first - Symmetry) * 2] << " " <<s[j->first]<<endl;
						k++;;
						break;
					}
			}
		}
		else     //������������������
			k++;
	}

	if (k == n)
		cout << "Yes" << endl;
	else
		cout << "NO" << endl;


	
	system("pause");
	return 0;
}


bool Check(map<double, double>s, double Symmetry, int n);

//����ȫ������,���ǰѶ���һ��map���͵�����
int main()
{
	map<double, double>s[maxn];//����ÿ�����꣬ͨ��keyҲ����x��ֵ������y��ֵ
	int nSum; //����Ҫ���������
	int n[maxn]; //������¼ÿ��������ٸ�����
	int k = 0;  //��������жϵ��Ƿ���ڶԳ���Գƣ�����Գ�+1
	double x, y;//������ʱ��ŵ������
	double xSum[maxn] = { 0 }, Symmetry[maxn] = { 0 };  //�ҳ��Գ���
	
	cin >> nSum;

	for (int i = 0; i < nSum; i++)
	{
		cin >> n[i];
		for (int j = 0; j < n[i]; j++)
		{
			cin >> x >> y;
			s[i][x] = y;
			xSum[i] += x;
		}
		Symmetry[i] = xSum[i] / n[i];
	}

	for (int i = 0; i < nSum; i++)
	{
		if (Check(s[i], Symmetry[i], n[i]))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}

bool Check(map<double, double>s, double Symmetry, int n)
{
	int k = 0;
	for (map<double, double>::iterator i = s.begin(); i != s.end(); i++)
	{
		if (i->first < Symmetry) //�����������ڶԳ�������ʱ,Ҫ�鿴�Ҳ��Ƿ���yֵ��ͬ�ĵ�ͨ��key����
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)
			{
				if (s[i->first + (Symmetry - i->first) * 2] == s[j->first]) //ͨ���Ƚ����ߵ�yֵ���ж��Ƿ���
				{
					k++;
					break;
				}
			}
		}
		else if (i->first > Symmetry)
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)
			{
				if (s[i->first - (Symmetry - i->first) * 2] == s[j->first]) //ͨ���Ƚ����ߵ�yֵ���ж��Ƿ���
				{
					k++;;
					break;
				}
			}
		}
		else     //������������������
			k++;
	}
	if (k == n)
		return true;
	else
		return false;
}
*/

//������c����д��
#include<iostream>
using namespace std;

const int maxn = 10;

int main()
{
	int nMax;
	cin >> nMax;
	int n[maxn];
	double data[maxn][maxn][2];
	double xSum[maxn] = { 0 }, aver[maxn] = { 0 };
	for (int i = 0; i < nMax; i++)
	{
		cin >> n[i];
		for (int j = 0; j < n[i]; j++)
		{
			cin >> data[i][j][0] >> data[i][j][1];
			xSum[i] += data[i][j][0];
		}
		aver[i] = xSum[i] / n[i];
	}
	int k = 0;
	double x, y;
	for (int t = 0; t < nMax; t++)
	{
		k = 0;
		for (int i = 0; i < n[t]; i++)
		{
			x = data[t][i][0];
			y = data[t][i][1];
			if (x < aver[t])   //����������������������ʱ
			{
				for (int j = 0; j < n[t]; j++)//�Ǿ�Ҫ�����������ұ���û�ж�Ӧ�ĺ����꣬
				{
					if (data[t][j][0] > aver[t])
					{
						if (x + (aver[t] - x) * 2 == data[t][j][0]) //�������������Ҳ��ҵ�һ��x�ԳƵ�
						{
							if (y == data[t][j][1])   //���ж����ǵ�yֵ�Ƿ���ͬ
							{
								k++;
								break;
							}

						}
					}
				}
			}
			else if (x > aver[t])
			{
				for (int j = 0; j < n[t]; j++)
				{
					if (data[t][j][0] < aver[t])
					{
						if (x - (x - aver[t]) * 2 == data[t][j][0])
						{
							if (y == data[t][j][1])
							{
								k++;
								break;
							}
						}
					}
				}
			}
			else
				k++;
		}
		if (k == n[t])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	getchar();
	getchar();
	return 0;
}
