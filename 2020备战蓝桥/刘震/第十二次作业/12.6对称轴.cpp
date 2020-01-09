/*判断平面上的一组点，是否关于一条竖线对称。即找到一条垂直对称轴*/

//思路：对称轴满足所有横坐标之和的平均值，然后找每一个点是否在线的那一边也有
/*
#include<iostream>
#include<map>
using namespace std;

const int maxn = 1000;

//先测试输入一次

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
		if (i->first < Symmetry) //当待测坐标在对称轴的左侧时,要查看右侧是否有y值相同的点通过key来找
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)  //遍历所有点，只测试轴右边的点
			{
				if (j->first > Symmetry)
					if (s[i->first + (Symmetry - i->first) * 2] == s[j->first]) //通过比较两边的y值来判断是否有
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
					if (s[i->first - (i->first - Symmetry) * 2] == s[j->first]) //通过比较两边的y值来判断是否有
					{
						cout << s[i->first - (i->first - Symmetry) * 2] << " " <<s[j->first]<<endl;
						k++;;
						break;
					}
			}
		}
		else     //待测坐标在坐标轴上
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

//测量全部数据,就是把定义一个map类型的数组
int main()
{
	map<double, double>s[maxn];//储存每个坐标，通过key也就是x的值来查找y的值
	int nSum; //共需要输入多少组
	int n[maxn]; //用来记录每组输入多少个数据
	int k = 0;  //这个用来判断点是否关于对称轴对称，如果对称+1
	double x, y;//用来暂时存放点的坐标
	double xSum[maxn] = { 0 }, Symmetry[maxn] = { 0 };  //找出对称轴
	
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
		if (i->first < Symmetry) //当待测坐标在对称轴的左侧时,要查看右侧是否有y值相同的点通过key来找
		{
			for (map<double, double>::iterator j = s.begin(); j != s.end(); j++)
			{
				if (s[i->first + (Symmetry - i->first) * 2] == s[j->first]) //通过比较两边的y值来判断是否有
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
				if (s[i->first - (Symmetry - i->first) * 2] == s[j->first]) //通过比较两边的y值来判断是否有
				{
					k++;;
					break;
				}
			}
		}
		else     //待测坐标在坐标轴上
			k++;
	}
	if (k == n)
		return true;
	else
		return false;
}
*/

//还是用c语言写把
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
			if (x < aver[t])   //待测点的坐标在坐标轴的左侧时
			{
				for (int j = 0; j < n[t]; j++)//那就要看看坐标轴右边有没有对应的横坐标，
				{
					if (data[t][j][0] > aver[t])
					{
						if (x + (aver[t] - x) * 2 == data[t][j][0]) //如果在坐标轴的右侧找到一个x对称的
						{
							if (y == data[t][j][1])   //在判断他们的y值是否相同
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
