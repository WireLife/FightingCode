#include<iostream> 
#include<map>
#include<cmath> 
using namespace std; 
int main()
{
	int n, a, b; 
	cin >> n; 
	map<int, int> match; 
	while(n--)
	{ 
		cin >> a >> b; 
		match[a] = b;
	}
	bool success = true; 
	for(map<int, int>::iterator it = match.begin(); it != match.end(); it++)//迭代器
	{ 
		if(!match[it->second])
		{ 
			success = false;
			break; 
		} 
	} 
	if(success) 
		cout << "SUCCESS!" << endl;
	else 
		cout << "FAIL!" << endl; 
	return 0;
