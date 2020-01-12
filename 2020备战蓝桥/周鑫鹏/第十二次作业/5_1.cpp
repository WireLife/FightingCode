/*#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	char s[1000];									//足够大的字符数组接收每一行的单词
	vector<string> s1[1000];
	string s0 = "";
	int i = 0, j = 0, k = 0;							//k行，j列
	int m[180] = { 0 }, n[1000] = { 0 };
	while (gets_s(s) && strcmp(s, "") != 0)//gets_s()遇到回车结束输入，如果再次回车，则输入为空，跳出大循环
	{
		for (i = 0; i < strlen(s); i++)				//每一行读取,逐个比较
		{
			if (s[i] != ' ')								//读取字母
				s0 += s[i];
			if (s[i] == ' '||i==strlen(s)-1&&(s0.size()>0))
			{
				s1[k].push_back(s0);
				if (s0.size() > m[j])
					m[j] = s0.size();
				j++;										//每完成一个单词的存储j+1
				s0 = "";									//s0="";重新接收s[i]
				n[k] = j;									//第k行有j个单词
			}
		}
		j = 0;												//到下一行单词最开始为0个
		k++;												//行号加1
	}
	for (int i = 0; i < k; i++)
	{
		for (int a = 0; a < n[i];a++)
		{
			cout.width(m[a]);
			cout << left <<  s1[i][a]<<" ";
		}
		cout << endl;
	}
}*/