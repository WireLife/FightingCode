/*2、习题---5-2Ducci序列（UVa1594）
对于一个n元组(a1, a2, …, an)，可以对于每个数
求出它和下一个数的差的绝对值，得到一个新的n元组
(|a1-a2|, |a2-a3|, …, |an-a1|)。重复这个过程，
得到的序列称为Ducci序列，例如： 
(8, 11, 2, 7) -> (3, 9, 5, 1) -> 
(6, 4, 4, 2) -> (2, 0, 2, 4) -> 
(2, 2, 2, 2) -> (0, 0, 0, 0). 
也有的Ducci序列最终会循环。输入n元组（3≤n≤15）
，你的任务是判断它最终会变成0还是会循环。
输入保证最多1000步就会变成0或者循环。 （一）样例输入
448 11 2 754 2 0 2 070 0 0 0 0 0 061 2 3 1 2 3 
（二）样例输出
ZEROLOOPZEROLOOP 
*/

/*
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int>s;
vector<int>m;
	int main()
	{
		int t;
		cout<<"请输入循环次数：";
		cin>>t;
		while(t--)
		{
	int n,i;
	cout<<"请输入数组为几元组：";
	cin>>n;
	//int* s=(int *) malloc(sizeof(int)*n);
	//int* m=(int *) malloc(sizeof(int)*n);   //用此动态数组会使输出总是LOOP 不知道为何。
	s.resize(n);
	m.resize(n);

	cout<<"请输入数组元素"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		m[i]=0;
	}
	for (i = 1; i <= 1000; i++)
		{
			int k = 0;
			 k = s[0];                 //把第一数先存起来，以便后面的最后一个数和第一个数的差.
			 for (int j = 0; j < n - 1; j++)
			 {
				 s[j] = abs(s[j] - s[j + 1]);
			 }
			 s[n - 1] = abs(k - s[n - 1]); 
		 }

			 if (s == m)             //判断此时是否全部的数都变成0了
			 {                   
				 cout << "ZERO" << endl;
				 break;

			 }
			 else                   //无限循环
				 cout<<"LOOP"<<endl;

		 }
	return 0;
}
		
*/
