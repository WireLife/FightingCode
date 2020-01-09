/*#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
typedef vector<string> STRING;
map<string, int>dict; //判断单词存在与否
vector<string>ans, IN;
map<char, STRING> find_; //表示首字母为()的所有字符串
int main()
{
	string s;
	while (cin >> s) 
	{
		IN.push_back(s);//存字符串，同时返回该元素出现的次数
		if (!dict.count(s)) dict[s] = 0;
		find_[s[0]].push_back(s);
	}
	for (int i = 0; i < IN.size(); i++)
	{                                //判断第i个字符串是否为复合词
		int yes = 0;
		string str = IN[i];
		char first = str[0]; //第i个字符串的首字母
		int len_all = str.length(); //第i个字符串的长度
		for (int j = 0; j < find_[first].size(); j++)
		{ //枚举首字母为first的所有字符串
			string wait_to_find;
			int k;
			int len1 = find_[first][j].length();
			if (len1 >= len_all) 
				continue;
			for (k = 0; k < len1; k++)
				if (str[k] != find_[first][j][k]) 
					break;
			if (k != len1) 
				continue;
			for (k = 0; k < len_all - len1; k++) 
				wait_to_find.push_back(str[len1 + k]); //取出IN[i] - find_[first][j]的字符串
			if (dict.count(wait_to_find)) 
			{ 
				yes = 1; 
			   break; 
			} //判断IN[i] - find_[first][j] 是否为单词，如是则IN[i]为复合词
		}
		if (yes) ans.push_back(IN[i]);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
*/
