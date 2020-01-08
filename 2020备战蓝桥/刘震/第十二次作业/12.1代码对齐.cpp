/*
输入若干行代码，要求各列单词的左边界对齐且尽量靠左。单词之间至少要空一格。每个单词
不超过80个字符，每行不超过180个字符，一共最多1000行。注意输出时每行的最后一列后面没
有空格符。
*/

//输入的时候是一个单词一个单词输入的，而且每个单词之间至少有一个空格，然后每一行最后有一个回车。
//因为最多不超过1000,每行最多不超过180个字符，那就定义一个string[1000];
//然后找出第一列最长的单词，第二列最长的单词..然后再用insert或则erase函数就OK了。
//因为题干没有说输入到什么时候截止，就暂且当输入#的时候结束

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string s[1000];
int r[90] = { 0 };//就算每一行的单词都只有一个字母
/*
//先测试一行的数据
int main()
{
	int i,len,ju,k=0;
	string ss;
	getline(cin, ss);

	cout << ss <<" "<<ss.size() <<endl;
	for (i = 0; i <= ss.size();)
	{
		//先找空格,找到一个记录其位置
		len = ss.find(' ', i);
		if (len == -1)      //表示后后面已经没有单词了
		{
			if (ss.size() - i  > r[k])
				r[k++] = ss.size() - i ;
			break;
		}

		if (len - i > r[k])   //两个空格之间的长度就是单词的长度+1
		{
			r[k++] = len - i;
		}
		i += len - i + 1;
	}
	cout << r[0] << " " << r[1] << " " << r[2] << endl;

	system("pause");
	return 0;
}
*/

//再来对于全部数据
int main()
{
	int i = 0, j = 0, k = 0, len = 0, t, ju;
	
	//先输入数据
	for (i = 0;;i++)
	{
		getline(cin,s[i]);
		if (*(s[i].end() - 1) == '#')
		{
			t = i + 1;
			break;
		}
	}

	//再找出每一列最长的单词
	for (i = 0; i <= t; i++)
	{
		cout << s[i] << endl;
		len = 0; k = 0;
		for (j = 0; j <= s[i].size();)
		{
			//先找空格,找到一个记录其位置
			len = s[i].find(' ', j);
			if (len == -1)              //表示后后面已经没有单词了
			{
				if (s[i].size() - j > r[k])
					r[k] = s[i].size() - j;
				cout << k << " " << endl;
				break;
			}

			if (len - j > r[k])   //两个空格之间的长度就是单词的长度+1
			{
				r[k] = len - j;
				cout << k << " ";
			}
			if (len != j)
				k++;
			j += len - j + 1;
		}
	}

	for (i = 0; i < 6; i++)
		cout << r[i] << " ";


	//现在找出了每列最长的那个单词。



	system("pause");
	return 0;
}
