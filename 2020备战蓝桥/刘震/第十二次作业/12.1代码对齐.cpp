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
int r[90] = { 0 };//以最坏的情况就算每一行的单词都只有一个字母

//先测试一行的数据,记录每个单词的长度
/*int main()
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
//把一行的数据给规范化
/*
int main()
{
	int a[4] = { 7,8,9,10 },len,k=0;
	string st("aa aaa aaaa aaa a  ");
	cout << st << endl;
	//先把每一行最后面的空格给删掉
	len = st.find_last_not_of(' ');
	st.erase(len + 1, st.size() - len - 1);


	for (int j = 0; j <= st.size();)
	{
		len = st.find(' ', j);
		//如果查找到最有一个单词
		if (len == -1)
		{
			break;
		}
		//如果没有查找到最后一个单词
		if (len == j) //说明两个单词之间有多的空格，此时要把多余的空格删掉
		{
			st.erase(j, 1);
		}

		if (len != j) //说明两个单词之间只有一个空格，不用再删空格
		{
			st.insert(len, a[k] - len + j + 1, '#'); 
			//此时j的位置也要变动，变动到这一列最长的位置 //比如aaa为第一列，这列最长为4，那么j=4,
			j += a[k++] + 1;
		}

	}
	cout << st << endl;*/

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
	for (i = 0; i < t; i++)
	{
		//cout << s[i] << endl;
		k = 0;
		for (j = 0; j <= s[i].size();)
		{
			//先找空格,找到一个记录其位置
			len = s[i].find(' ', j);
			if (len == -1)              //表示后后面已经没有单词了
			{
				if (s[i].size() - j > r[k])
					r[k] = s[i].size() - j;
				//cout << k << " " << endl;
				break;
			}

			if (len - j > r[k])   //两个空格之间的长度就是单词的长度+1
			{
				r[k] = len - j;
				//cout << k << " ";
			}
			if (len != j)
				k++;
			j += len - j + 1;
		}
	}

	/*for (i = 0; i < 6; i++)  //保存每一列最长的单词的长度
		cout << r[i] << " ";
	cout << endl;*/

	//现在找出了每列最长的那个单词。然后再检查每一行单词每一列单词与自身列数最长的那个单词比较,
	//比如先找出第一行的第一个单词与第一列最长的单词长度进行比较，然后填
	for (i = 0; i < t; i++)
	{
		k = 0;
		//先把每一行最后面的空格给删掉,不然后面的程序会报错
		len = s[i].find_last_not_of(' ');    //从最后一个字符倒着查找出第一个不是空格的索引
		s[i].erase(len + 1, s[i].size() - len - 1);  //把最后一个单词后面的空格趣步删掉
		
		
		for (int j = 0; j <= s[i].size();)
		{
			//每一行的从头开始查
			len = s[i].find(' ', j);
			//如果查找到最后一个单词时，因为前面把最后的空格删除，所以会返回-1
			if (len == -1)
				break;
			//如果两个单词之间有多个空格
			if (len == j) 
				s[i].erase(j, 1);
			//如果两个单词之间只有一个空格，不用再删空格
			if (len != j) 
			{
				s[i].insert(len, r[k] - len + j + 1, ' ');
				//此时j的位置也要变动，变动到这一列最长的位置 //比如aaa为第一列，这列最长为4，那么j=4,
				j += r[k++] + 1;
			}
		}
	}


	//打印
	for (i = 0; i < t; i++)
		cout << s[i] << endl;

	system("pause");
	return 0;
}