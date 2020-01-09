#include <iostream>
#include <queue>
using namespace std;
queue<int> k;
int main(int argc, char *argv[])
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++)
		k.push(i);
		cout<<"Discarded cards:";
		while(k.size()!=1)
		{  
			cout<<" "<<k.front();
			if(k.size()>2)
			cout<<",";
			k.pop();
			k.push(k.front());
			k.pop();
		}
		cout<<endl;
		cout<<"Remaining card: "<<k.front()<<endl;
		k.pop();
	}
	return 0;
}
