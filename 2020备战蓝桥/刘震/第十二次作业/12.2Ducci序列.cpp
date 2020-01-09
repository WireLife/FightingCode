/*12.2����һ��nԪ��(a1, a2, ��, an)�����Զ���ÿ�������������һ�����Ĳ�ľ���ֵ���õ�һ���µ�nԪ
��(|a1-a2|, |a2-a3|, ��, |an-a1|)���ظ�������̣��õ������г�ΪDucci���У����磺
(8, 11, 2, 7) -> (3, 9, 5, 1) -> (6, 4, 4, 2) -> (2, 0, 2, 4) -> (2, 2, 2, 2) -> (0, 0, 0, 0). 
Ҳ�е�Ducci�������ջ�ѭ��������nԪ�飨3��n��15��������������ж������ջ���0���ǻ�ѭ�������뱣֤
���1000���ͻ���0����ѭ���� */

#include<iostream>
#include<cmath>
using namespace std;

const unsigned maxn = 15;
int main()
{
	long long judge = 0;
	int i, j, k;
	int n;				//���������������
	bool bol[maxn];		//�����洢ÿһ���Ƿ�ΪZERO
	int data[maxn][100]; //�������ÿһ�����ݣ�����data[i][0]���������һ�����뼸����������1-data[i][0]�������ÿ������


	cin >> n;
	
	for (i = 0; i < n; i++)
	{
		cin >> data[i][0];
		for (j = 1; j <= data[i][0]; j++)
			cin >> data[i][j];
		data[i][data[i][0]+1] = data[i][1];  //ÿ���ڼ�һ�����������洢ÿ���������ݵĵ�һλ
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 1000; j++)
		{
			judge = 0;
			for (k = 1; k <= data[i][0]; k++)
			{
				data[i][k] = abs(data[i][k] - data[i][k + 1]);  //ÿһ����Чλ������
				//cout << data[i][k]<<" ";
			}
			//cout << endl;
			
			data[i][k] = data[i][1];    //�ڰ����һ��Ԫ�ص�ֵ��ɵڶ���Ԫ�ص�ֵ��
			
			for (k = 1; k < data[i][0]; k++) 
				judge += data[i][k];   //���ÿһλ��Чλ�����㣬��ô�ܺ�Ҳ��0.

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
