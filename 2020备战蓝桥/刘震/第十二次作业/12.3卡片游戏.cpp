/*ϰ��---5-3��Ƭ��Ϸ��UVa10935��
����n�ſ�Ƭ������1-n��˳���ţ�Ȼ���ó�һ�ſ�Ƭ�ӵ����ó�һ�ſ�Ƭ�ŵ�����ظ��ò���ֱ��ֻʣ1�ſ�Ƭ��
���ӵ��Ŀ�Ƭ���к����ʣ�Ŀ�Ƭ�ı�š�*/

//����һ��
//˼·����Ϊ�Ƶ����ʱ1-n��û��0��������һָ��ӵ�һ������ָ������һ�ţ�����������Ϊ0��Ȼ������һ���ƣ�ָ�����һ���ƺ�
//�ٰ�ָ��ָ���λ���Ƶ��������һ������

#include<iostream>
using namespace std;

const int sumTry = 50;//�����Ҳû��˵������漸�Σ����Ҷ�λ�����50�Ρ�
const int maxn = 50; //�����û��˵ÿ�ε��������ޣ����Ҷ�����Ϊ50�š�
/*
//����һ������
int main()
{
	int i, j = 0, k, cnt = 0;
	int n = 7; //����˵һ����18������
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
			//cout <<"�������ˣ�"<< i+1 << endl;
			break;
		}
		j++;
	}
	system("pause");
	return 0;
}*/
//��������ȫ������
int main()
{
	int eachSumCard[sumTry];
	int i, j, k = 0, n, cntt = 0;           //n������¼һ��Ҫ���ж����̳�����Ϸ,cnt��ʾÿ��һ������˶�������
	int bol[maxn] = { 0 };
	for (i = 0;; i++)
	{
		cin >> eachSumCard[i];
		if (eachSumCard[i] == 0) 
			break;
	}
	n = i ; //˵��Ҫ��i����Ϸ
	/*for (i = 0; i < n; i++)
		cout << eachSumCard[i] << " ";*/

	for (i = 0; i < n; i++)
	{
		//bol[j]����ڵ�j+1���ƣ�1�������ˣ�0����δ�������ʼ��ʱ��û�г����
		for (j = 0; j <= eachSumCard[i]; j++)
			bol[j] = 0;

		k = 0;									//k�����Ǹ�ָ��
		cntt = 0;								//�µ�һ��һ���ƻ�û�г����
		cout << "Discarded cards:";
		for (j = 0;; j++)
		{
			if (j == eachSumCard[i]) j = 0;
			if (bol[j])
				continue;
			if (k % 2 == 0)
			{
				bol[j] = 1;
				cntt++;									//���Ƶ���Ŀ+1
				if (cntt != eachSumCard[i])				//�������Ƴ��
					if(cntt+1==eachSumCard[i])
						cout << j + 1;					//�����ʽҪ��
					else cout << j + 1 << ",";
				
			}
			if (cntt == eachSumCard[i])				//������������������һ�̵�����������ô�����ʣ�µ����һ���ơ�
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
