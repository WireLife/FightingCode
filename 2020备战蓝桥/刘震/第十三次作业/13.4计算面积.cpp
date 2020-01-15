/*编程计算由“*”号围成的下列图形的面积。面积计算方法是统计*号所围成的闭合曲线中水平线和垂直线交点的数目。
如下图所示，在10*10的二维数组中，有“*”围住了15个点，因此面积为15。*/

//用最笨的方法，暴力解法,发现不行
/*#include<iostream>
using namespace std;
int main()
{
	int map[10][10] = {
		   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		   {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		   {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		   {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		   {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
		   {0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
		   {0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
		   {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		   {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
		   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	int cnt = 0, bol = 0;;
	//用最笨的方法，被星星包围的0其在x，y方向的两端都有一个1，一共有四个1
	for (int i = 1; i < 10-1; i++)
	{
		for (int j = 1; j < 10 - 1; j++)   //这是循环每一颗星星,在边界的星星就不用考虑了
		{
			bol = 0;
			if (map[i][j] != 1)
			{	
				for(int up=i-1;up>0;up--)
					if (map[up][j] == 1) {
						bol++;
						break;
					}
				for(int down=i+1;down<10;down++)
					if (map[down][j] == 1) {
						bol++;
						break;
				}
				for(int left=j-1;left>0;left--)
					if (map[i][left] == 1) {
						bol++;
						break;
					}
				for(int right=j+1;right<10;right++)
					if (map[i][right] == 1) {
						bol++;
						break;
					}
				if (bol == 4)
					cnt++;
			}			
		}
	}

	cout << cnt << endl;
	system("pause");
	return 0;

}
*/
#include<iostream>
using namespace std;
int main() {
	int map[10][10] = {
		   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		   {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		   {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		   {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		   {0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
		   {0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
		   {0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
		   {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
		   {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
		   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
	int cnt = 0;


	for (int i = 0; i < 10; i++) {
		map[i][0] = -1;
		map[i][9] = -1;
		map[0][i] = -1;
		map[9][i] = -1;
	}

	for (int i = 0; i < 10 ; i++)
	{
		for (int j = 0; j < 10 ; j++)   //这是循环每一颗星星,在边界的星星就不用考虑了
		{
			if (map[i][j] == -1)
			{
				for (int up = i - 1; up > 0; up--)
					if (map[up][j] == 0) 
						map[up][j] = -1;
					else break;
				for (int down = i + 1; down < 10; down++)
					if (map[down][j] == 0)
						map[down][j] = -1;
					else break;
				for (int left = j - 1; left > 0; left--)
					if (map[i][left] == 0)
						map[i][left] = -1;
					else break;
				for (int right = j + 1; right < 10; right++)
					if (map[i][right] == 0) 
						map[i][right] = -1;
					else break;					
			}
		}
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (map[i][j] == 0)
				cnt++;

	cout << cnt << endl;
	system("pause");
	return 0;
}
