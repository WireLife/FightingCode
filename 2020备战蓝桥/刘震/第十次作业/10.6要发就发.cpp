/*10.6要发就发*/
//思路，先用一个数组把第一行1-1993的素数存起来，在用一个数组把第二行的数存起来
//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151
//1 2 2 4 2  4  2  4  6  2  6  4  2  4  6  6  2  6  4  2  6  4  6  8  4  2   4  
//觉得有规律可循,然而我并没有发现规律，
//把所有儿子数加起来得1991，也就是说我在儿子数组前面能找到几个和从后面能找到和为1991-1898的就ok了


#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1993; //素数最多不超过1993

int k = 0; //k用来作为儿子数组的长度
//第一行素数存放的位置
int SuNumber[maxn], SuNumberSon[maxn];
//获得素数组的函数
void get_suNumber();
//计算加和为1991-1898的数
int cnt_Add();

int main()
{
	get_suNumber();
	cout << cnt_Add();
	getchar();
	return 0;
}

void get_suNumber()
{
	int i, j, t = 0, sign;
	int sum = 0;
	for (i = 2; i <= 1993; i++)   //判断从1-1993
	{
		sign = 1;
		t = sqrt(i);
		for (j = 2; j <= t; j++)   //这里条件没有设为j*j<=i 或j<=sqrt(i);而是用一个变量t代替sqrt(i)
		{
			if (i%j == 0) {
				sign = 0;
				break;
			}
		}
		if(sign)
			SuNumber[k++] = i; 
	}
	//获得到儿子数
	for (i = 0; i < k - 1; i++)
	{
		SuNumberSon[i] = SuNumber[i + 1] - SuNumber[i];
		sum += SuNumberSon[i];
	}
}
 //思路：[0]+[k-1]+[k-2]+...+[n]==1991-1898，第二次循环在[0]+[1]+[k-1]+[k-2]+...+[n]==1991-1898,第三次循环...
int cnt_Add() 
{
	int i, j, total = 1991-1898, sumHead = 0, sumEnd = 0, cnt = 0;
	for (i = 0; sumHead <= total; i++)
	{
		sumHead += SuNumberSon[i];
		sumEnd = 0;
		for (j = k - 1; sumHead + sumEnd <= total; j--)
		{
			sumEnd += SuNumberSon[j];
			if (sumHead + sumEnd == total)
			{
				cnt++;
				//cout << SuNumber[i] << '-' << SuNumber[j] << endl;
				break;
			}
		}
	}
	return cnt;
}

