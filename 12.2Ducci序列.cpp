/*12.2对于一个n元组(a1, a2, …, an)，可以对于每个数求出它和下一个数的差的绝对值，得到一个新的n元
组(|a1-a2|, |a2-a3|, …, |an-a1|)。重复这个过程，得到的序列称为Ducci序列，例如：
(8, 11, 2, 7) -> (3, 9, 5, 1) -> (6, 4, 4, 2) -> (2, 0, 2, 4) -> (2, 2, 2, 2) -> (0, 0, 0, 0). 
也有的Ducci序列最终会循环。输入n元组（3≤n≤15），你的任务是判断它最终会变成0还是会循环。输入保证
最多1000步就会变成0或者循环。 */

#include<iostream>
#include<cmath>
using namespace std;

const unsigned maxn = 15;
int main()
{
	long long judge = 0;
	int i, j, k;
	int n;				//共输入多少组数据
	bool bol[maxn];		//用来存储每一组是否为ZERO
	int data[maxn][100]; //用来存放每一组数据，其中data[i][0]用来存放这一组输入几个数，后面1-data[i][0]用来存放每组数据


	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> data[i][0];
		for (j = 1; j <= data[i][0]; j++)
			cin >> data[i][j];
		data[i][data[i][0]+1] = data[i][1];  //每组在加一个数据用来存储每组数据数据的第一位
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			judge = 0;
			for (k = 1; k <= data[i][0]; k++)
			{
				data[i][k] = abs(data[i][k] - data[i][k + 1]);  //每一个有效位都更换
				//cout << data[i][k]<<" ";
			}
			//cout << endl;
			
			data[i][k] = data[i][1];    //在把最后一个元素的值变成第二个元素的值，
			
			for (k = 1; k < data[i][0]; k++) 
				judge += data[i][k];   //如果每一位有效位都是零，那么总和也是0.

			if (!judge) break;

		}
		if (!judge) bol[i] = true;
		else bol[i] = false;
	}

	for (i = 0; i < n; i++)
	{
		if (bol) cout << "ZERO" << endl;
		else cout << "LOOP" << endl;
	}

	system("pause");
	return 0;
}
