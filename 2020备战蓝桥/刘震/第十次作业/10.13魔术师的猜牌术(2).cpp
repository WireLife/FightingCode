/*魔术师的猜牌术(2)*/
//思路：用循环做，用一个数组储存这26个字符，因为每次要翻开然后放在桌子上所以，每次具体翻哪一张牌是确定的
//a a a a a a a a a a a a a a a
//1     2     3     4     5   
/*#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 26;  //黑桃桃红桃桃加起来一共26张
char display[maxn][7] = { "黑桃A","黑桃2","黑桃3" ,"黑桃4" ,"黑桃5" ,"黑桃6" ,"黑桃7" ,"黑桃8" ,"黑桃9" ,"黑桃B" ,"黑桃J" ,"黑桃Q" ,"黑桃K",
                        "红桃A","红桃2","红桃3" ,"红桃4" ,"红桃5" ,"红桃6" ,"红桃7" ,"红桃8" ,"红桃9" ,"红桃B" ,"红桃J" ,"红桃Q" ,"红桃K" }; //这里10用B来代替，两个字符代替一个字符

int main()
{
	int i, j = 0, k = 0;
	char s[maxn][3];  //这里是仿照那个整形数组赋初值的

	memset(s, "0", maxn);
	cout << s[1] << endl;
	while (1)
	{                   
		for (i = 0; i < 26; i++)
		{
			if (strcmp(s[i], "0"));
			{
				if (j % 3 == 0)
				{
					strcpy(s[i], display[k++]);
				}
				else j++;
			}
		}
		if (k >= maxn) break;
	}

	for (i = 0; i < maxn; i++)
		cout << s[i] << endl;
	
	getchar();
	return 0;
}
//遇到的问题：
*/

//上面的程序本打算用新建一个字符数组赋值用的，后来遇到了二维字符数组初始化问题，这里不用新建赋值数组，建一个标记下标的整型数组
#include<iostream>
using namespace std;

const int maxn = 26;  //黑桃桃红桃桃加起来一共26张
char display[maxn][7] = { "黑桃A","黑桃2","黑桃3" ,"黑桃4" ,"黑桃5" ,"黑桃6" ,"黑桃7" ,"黑桃8" ,"黑桃9" ,"黑桃10" ,"黑桃J" ,"黑桃Q" ,"黑桃K",
"红桃A","红桃2","红桃3" ,"红桃4" ,"红桃5" ,"红桃6" ,"红桃7" ,"红桃8" ,"红桃9" ,"红桃10" ,"红桃J" ,"红桃Q" ,"红桃K" }; 

int main()
{
	int i, j = 0, k = 1, sign[maxn] = { 0 }; //初始化
	while (1)
	{
		for (i = 0; i < maxn; i++)     //思路就是把牌排成一排，从第一次开始翻，然后每隔2张再翻一次，一直翻到结尾再从头开始，遇到已经翻的跳过
		{
			if (sign[i] == 0)
			{
				if (j % 3 == 0)
				{
					sign[i] = k++;
					j = 0;
				}
				j++;
			}
		}
		if (k > maxn) break;
	}

	for (i = 0; i < maxn; i++)
		cout << display[sign[i]-1] << endl;
		
	getchar();
	return 0;
}
