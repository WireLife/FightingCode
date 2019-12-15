/*11.1 判断下列标识符的合法性*/
/*    sin  book 5arry _name  Example2.1  main 
    $1  class_cpp   a3  x*y   my name*/

//思路：就是对每一个标识符的每一位字符进行判断
/*
#include<iostream>
using namespace std;

int main()
{
	char str[][11] = { "sin","book", "5arry", "_name", "Example2.1", "main", "$1", "class_cpp", "a3", "x*y", "my name" };
	int i, j, sign[11];
	for (i = 0; i < 11; i++)
	{
		cout << str[i] << ' ';
		if (str[i][0] >= 'a'&&str[i][0] <= 'z' || str[i][0] >= 'A'&&str[i][0] <= 'Z' || str[i][0] == '_')
		{
			for (j = 0; str[i][j] != '\0'; j++)
				if (!(str[i][j] >= 'a'&&str[i][j] <= 'z' || str[i][j] >= 'A'&&str[i][j] <= 'Z' || str[i][j] == '_' || str[i][j] >= '0'&&str[i][j] <= '9'))
				{
					sign[i] = 0;
					break;
				}
			if (j == strlen(str[i]))
				sign[i] = 1;
		}
		else
			sign[i] = 0;
	}

	//打印
	cout << "\n是标识符的有:" << endl;
	for (i = 0; i < 11; i++)
		if (sign[i])
			cout << str[i] << " ";

	cout << "\n不是标识符的有" << endl;
	for (i = 0; i < 11; i++)
		if (!sign[i])
			cout << str[i] << " ";
			
	getchar();
	return 0;
}
*/


//用C++的内置string类
#include<iostream>
#include<string>
using namespace std;

const int maxn = 11;
int main()
{
	string str[maxn]= { "sin","book", "5arry", "_name", "Example2.1", "main", "$1", "class_cpp", "a3", "x*y", "my name" };
	string is[maxn], nis[maxn];
	int i, j, k = 0, l = 0;
	for (i = 0; i < maxn; i++)
	{
		cout << str[i] << ' ';
		if (str[i][0] >= 'a'&&str[i][0] <= 'z' || str[i][0] >= 'A'&&str[i][0] <= 'Z' || str[i][0] == '_')
		{
			for (j = 0; j<str[i].length(); j++)
				if (!(str[i][j] >= 'a'&&str[i][j] <= 'z' || str[i][j] >= 'A'&&str[i][j] <= 'Z' || str[i][j] == '_' || str[i][j] >= '0'&&str[i][j] <= '9'))
				{
					nis[l++] = str[i];
					break;
				}
			if (j == str[i].length())
				is[k++] = str[i];

		}
		else
			nis[l++] = str[i];
	}

	cout << "\n是标识符的有：" << endl;
	for (i = 0; i < k; i++)
		cout << is[i] << ' ';

	cout << "\n不是标识符的有：" << endl;
	for (i = 0; i < l; i++)
		cout << nis[i] << ' ';

	getchar();
	return 0;
		
}
