#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include <vector>
using namespace std;
typedef struct crood
{
	double x, y;
}crood;
bool operator< (const crood& a, const crood& b)
{
	if (a.y <= b.y)
		return a.x <= b.x;
	return a.y <= b.y;
}
int F(const vector<double>p)
{
	if(p.size()>=1)
	{
		auto it = p.rbegin();
		double t = *it -*p.begin();//
		auto i = p.begin();
		++i;
		for (; i != p.end(); i++)
		{
			if ( fmod(t,(*i - *p.begin()))!=0)
				break;
		}
		if (i == p.end())
			return 1;
		return 0;
	}
	return 0;
}
int M()
{
    set<crood> sp; crood temp; set<double> spx;
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		cin >> temp.x >> temp.y;
		sp.insert(temp);
	}
	set<crood>::iterator it = sp.begin();
	auto it1 = ++it;
	--it;
	vector<double> p;
	for (; it != sp.end(); it++)
	{
		for (; it1 != sp.end(); it1++)
		{
			if ((*it).y == (*(it1)).y)
			{
				p.push_back((*it).x);
				p.push_back((*it1).x);
			}
			else
			{
				spx.insert((*it).x);
			}
		}
		if (F(p) == 0)
		{
			cout << "no" << endl;
			return 0;
		}
	}
	if (spx.size() == 1 || spx.size() == 0)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
int main()
{
	int n;
	cin>>n;
    for(int i=0;i<n;i++)
    {
        M();
    }
    return 0;
}
