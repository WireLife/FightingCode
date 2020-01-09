/*习题---5-3卡片游戏（UVa10935）
给定n张卡片，按照1-n的顺序编号，然后拿出一张卡片扔掉，拿出一张卡片放到最后，重复该操作直到只剩1张卡片。
求扔掉的卡片序列和最后剩的卡片的编号。*/

//方法一：
//思路：因为牌的序号时1-n，没有0，可以用一指针从第一张依次指向下面一张，丢掉的牌置为0，然后跳过一张牌，指到最后一张牌后，
//再把指针指向的位置移到最上面的一张牌上

#include<iostream>
using namespace std;

const int sumTry = 50;//题干中也没有说最多能玩几次，暂且定位最多玩50次。
const int maxn = 50; //题干中没有说每次的牌数上限，暂且定上限为50张。
/*
//先玩一把试试
int main()
{
	int i, j = 0, k, cnt = 0;
	int n = 7; //比如说一共有18把张牌
	int bol[7] = {0};
	
	for (i = 0;;i++) 
	{
		if (i == 7)i = 0;
		if (bol[i])
			continue;		
		if (j % 2 == 0)
		{
			bol[i] = 1;
			cnt++;
			cout << i + 1 << " ";
		}
		if (cnt == n)
		{
			//cout <<"就是你了："<< i+1 << endl;
			break;
		}
		j++;
	}
	system("pause");
	return 0;
}*/
//再来处理全部数据
int main()
{
	int eachSumCard[sumTry];
	int i, j, k = 0, n, cntt = 0;           //n用来记录一共要进行多少盘抽牌游戏,cnt表示每盘一共抽掉了多少张牌
	int bol[maxn] = { 0 };
	for (i = 0;; i++)
	{
		cin >> eachSumCard[i];
		if (eachSumCard[i] == 0) 
			break;
	}
	n = i ; //说明要玩i次游戏
	/*for (i = 0; i < n; i++)
		cout << eachSumCard[i] << " ";*/

	for (i = 0; i < n; i++)
	{
		//bol[j]代表第第j+1张牌，1代表抽掉了，0代表还未抽掉。开始的时候都没有抽掉。
		for (j = 0; j <= eachSumCard[i]; j++)
			bol[j] = 0;

		k = 0;									//k就是那个指针
		cntt = 0;								//新的一局一张牌还没有抽掉。
		cout << "Discarded cards:";
		for (j = 0;; j++)
		{
			if (j == eachSumCard[i]) j = 0;
			if (bol[j])
				continue;
			if (k % 2 == 0)
			{
				bol[j] = 1;
				cntt++;									//抽牌的数目+1
				if (cntt != eachSumCard[i])				//把这张牌抽掉
					if(cntt+1==eachSumCard[i])
						cout << j + 1;					//输出格式要求
					else cout << j + 1 << ",";
				
			}
			if (cntt == eachSumCard[i])				//如果抽掉的牌数等于这一盘的总牌数，那么这就是剩下的最后一张牌。
			{
				cout << endl << "Remaining card:" << j + 1 << endl;
				break;
			}
			k++;
		}
	}
	system("pause");
	return 0;
}
