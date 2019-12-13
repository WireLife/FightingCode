/*10.14搬山游戏*/

//题目意思就是，我输入多少座山和每次最多能搬多少座，然后我先输入搬山的数目，计算机要搬的数目，此时要用一个随机函数生成计算机要搬的数量

#include<iostream>
#include<cstdlib>      //产生随机数
#include<ctime>        //随机数用时间作为种子
using namespace std;
int main()
{
	cout << "           搬山游戏：输入山的总数和每次最多能搬的数量，在每局结束后继续游戏请输入Y，退出请输入N：" << endl;
	int n, k, i,        //定义变量n,k 山的总数和每次最大能搬的数目
		cntSum = 0,     //记录总局数
		cntIWin = 0,    //记录我赢的次数 
		cntPcWin = 0;   //记录计算机赢的次数
	int I_mv = 0,       //我每次搬多少
		Pc_mv, mvM = 0; //计算机每次搬多少
	char key = 'Y';     //作为用户是否继续玩游戏的标记
	cin >> n >> k;

	srand((unsigned)time(NULL));    

	while (!(key == 'N' || key == 'n'))
	{
		cntSum++;
		mvM = 0;
		for (i = 0; ; i++)
		{
			while (1)
			{
				cin >> I_mv;
				if (I_mv > k)
					cout << "你不能搬这么多，每次上限为" << k << "座山。请重新搬" << endl;
				else if (n - mvM - I_mv > 0) break;
				     else cout << "你搬山的座数不能超过" << k << "座，请重新搬" << endl;
			}
				
			mvM += I_mv;
			if (n - mvM == 1)
			{
				cout << "你赢了！" << endl;
				cntIWin++;
				break;
			}
			
			do							//防止计算机搬山的数量一下子超过了剩余量
			{
				Pc_mv = rand() % k;
			} while (n - mvM - Pc_mv <= 0);
			
			//判断计算机搬完后是否会剩余一座
			mvM += Pc_mv;
			cout << "计算机搬了" << Pc_mv << "座山，目前还剩余" << n - mvM << "座。" << endl;
			if (n - mvM == 1)
			{
				cout << "计算机赢了！" << endl;
				cntPcWin++;
				break;
			}
		}

		cout << "是否继续游戏：";
		cin >> key;
	}

	cout << "一共玩了" << cntSum << "局，你赢了" << cntIWin << "局" << endl;
	getchar();
	getchar();
	return 0;
}