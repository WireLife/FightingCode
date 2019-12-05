#include<iostream>
using namespace std;
#define maxn 20
char s[maxn], a1[maxn], a2[maxn];
int main() {
	while (cin >> s)
	{
		for (int i = 0; i < 6; i++)//将两个骰子用S[]中的字母染色
		{
			a1[i + 1] = s[i];
			a2[i + 1] = s[i + 6];
		}
		for (int i = 1; i <= 6; i++)//做标记 不论怎样旋转，每个面和它的对面永远是相对位置不变，第一个骰子的第一面假设染r色，对面染g色，
			//则在第二个骰子上找出所有染r色的面，判断它的对面是不是也是g色，如果是的 则将这四个面做上标记
		{
			if (a1[i] == '*')continue;
			for (int j = 1; j <= 6; j++) 
			{
				if (a2[j] == '*')continue;
				if (a1[i] == a2[j])
				{
					if (a1[7 - i] == a2[7 - j]) 
					{
						a1[i] = a1[7 - i] = a2[j] = a2[7 - j] = '*'; 
						break;
					}
				}
			}
		}
		bool flag = true;
		for (int i = 1; i <= 6; i++)//判断第一个骰子和第二个骰子的所有标记处是否一致，如果一致 则说明两个骰子的染色方式完全一致
			if (!(a1[i] == a2[i])) 
				flag = false;

		if (flag) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;
	}
	return 0;
}
