/*#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> Q;
	
	int n;
	{
		cout << "input the cards:" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
			Q.push(i + 1);
		//for (int i = 0; i < n; i++)
		//{
		//	cout << Q.front();
		//	Q.pop();

	//	}
		int flag = 1;
		cout << "the discard cards is:" << " ";
		while (Q.size() != 1)
		{
			if (flag == 1)
			{
				cout << Q.front();
				if (Q.size() != 2)
					cout << ",";
			}
			else if (flag == -1)
			{
				Q.push(Q.front());
			}
			Q.pop();
			flag = -flag;
		}
		cout << endl;
		cout << "the remain card is:" << Q.front() << endl;
		cout << endl;
		system("pause");
		return 0;

	}
}
*/
