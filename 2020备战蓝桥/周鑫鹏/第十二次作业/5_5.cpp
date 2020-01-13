#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main()
{
	set<string> word;
	int k = 0;
	char s1[100];
	string s="";
	while (gets_s(s1)&&strcmp(s1,"")!=0)
	{
		s += s1;
		word.insert(s);
		s = "";
		k++;
	}
	string t="";
	auto it = word.begin();
	auto it1 = word.end();
	auto j = word.begin();
	--it1;
	for (it; it!=word.end(); it++)
	{
		for (j=word.begin(); j !=word.end(); j++)
		{
			if (it != word.end())
			{
				t = *it + *j;
				word.insert(t);
				if (word.size() == k)
					cout << t << endl;
				else
					word.erase(t);
				t = "";
			}
		}
	}
	return 0;
}