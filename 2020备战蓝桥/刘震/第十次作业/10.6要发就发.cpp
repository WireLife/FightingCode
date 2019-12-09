/*10.6Ҫ���ͷ�*/
//˼·������һ������ѵ�һ��1-1993������������������һ������ѵڶ��е���������
//2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151
//1 2 2 4 2  4  2  4  6  2  6  4  2  4  6  6  2  6  4  2  6  4  6  8  4  2   4  
//�����й��ɿ�ѭ,Ȼ���Ҳ�û�з��ֹ��ɣ�
//�����ж�������������1991��Ҳ����˵���ڶ�������ǰ�����ҵ������ʹӺ������ҵ���Ϊ1991-1898�ľ�ok��


#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1993; //������಻����1993

int k = 0; //k������Ϊ��������ĳ���
//��һ��������ŵ�λ��
int SuNumber[maxn], SuNumberSon[maxn];
//���������ĺ���
void get_suNumber();
//����Ӻ�Ϊ1991-1898����
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
	for (i = 2; i <= 1993; i++)   //�жϴ�1-1993
	{
		sign = 1;
		t = sqrt(i);
		for (j = 2; j <= t; j++)   //��������û����Ϊj*j<=i ��j<=sqrt(i);������һ������t����sqrt(i)
		{
			if (i%j == 0) {
				sign = 0;
				break;
			}
		}
		if(sign)
			SuNumber[k++] = i; 
	}
	//��õ�������
	for (i = 0; i < k - 1; i++)
	{
		SuNumberSon[i] = SuNumber[i + 1] - SuNumber[i];
		sum += SuNumberSon[i];
	}
}
 //˼·��[0]+[k-1]+[k-2]+...+[n]==1991-1898���ڶ���ѭ����[0]+[1]+[k-1]+[k-2]+...+[n]==1991-1898,������ѭ��...
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

