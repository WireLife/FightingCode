/*#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	char s[1000];									//�㹻����ַ��������ÿһ�еĵ���
	vector<string> s1[1000];
	string s0 = "";
	int i = 0, j = 0, k = 0;							//k�У�j��
	int m[180] = { 0 }, n[1000] = { 0 };
	while (gets_s(s) && strcmp(s, "") != 0)//gets_s()�����س��������룬����ٴλس���������Ϊ�գ�������ѭ��
	{
		for (i = 0; i < strlen(s); i++)				//ÿһ�ж�ȡ,����Ƚ�
		{
			if (s[i] != ' ')								//��ȡ��ĸ
				s0 += s[i];
			if (s[i] == ' '||i==strlen(s)-1&&(s0.size()>0))
			{
				s1[k].push_back(s0);
				if (s0.size() > m[j])
					m[j] = s0.size();
				j++;										//ÿ���һ�����ʵĴ洢j+1
				s0 = "";									//s0="";���½���s[i]
				n[k] = j;									//��k����j������
			}
		}
		j = 0;												//����һ�е����ʼΪ0��
		k++;												//�кż�1
	}
	for (int i = 0; i < k; i++)
	{
		for (int a = 0; a < n[i];a++)
		{
			cout.width(m[a]);
			cout << left <<  s1[i][a]<<" ";
		}
		cout << endl;
	}
}*/