
#include<iostream>
#include<string>
using namespace std;
struct FenShu
{
	int Fenzi;
	int FenMu;
	char Chuhao;
};
int divisor(int a, int b)//辗转相除法求最大公约数
{
	int temp = 0;
	if (a < b)
	{
		temp = a; a = b; b = temp;
	}
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return (a);
}

int gcd1(int a, int b, int c)//求最小公倍数
{
	return (a*b) / c;
}

void Simplify(int a, int b, int n)//结果约分
{
	cout << "最终结果为:" << a / n << "/" << b / n << endl;
}
void Sum(int n, FenShu *t, int gbs)
{
	int FenZi = 0, FenMu = 0;
	int Beishu1;
	for (int i = 0; i < n; i++)
	{
		Beishu1 = gbs / (t->FenMu);
		FenZi = FenZi + (t->Fenzi)*Beishu1;
		t++;
	}
	FenMu = gbs;
	int a = divisor(FenZi, FenMu);//辗转相除法求最大公约数      //存最大公约数
	Simplify(FenZi, FenMu, a);         //结果约分
}
int main()
{
	int n, gbs = 0, c = 0;

	cout << "input the size:\n";
	cin >> n;
	if (n <= 1)
	{
		cout << "error！" << endl;

	}
	FenShu L[10] = { 0 };
	FenShu *t;
	t = L;
	for (int i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个分数为:";
		cin >> L[i].Fenzi;
		cin >> L[i].Chuhao;
		cin >> L[i].FenMu;
	}

	c = divisor(L[0].FenMu, L[1].FenMu);
	gbs = gcd1(L[0].FenMu, L[1].FenMu, c);
	Sum(n, t, gbs);
	system("pause");
	return 0;
}
