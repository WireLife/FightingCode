/*У��������*/
/*˼·������һ���������ж��Ƿ�Ϊ��Ч��У���룬*/

#include<iostream>
using namespace std;

const int N = 13;	//0-0000-0000-0
//ISBN��ŵ�λ��
char code[N];
//У�麯��
int CheckCode(char str[]);
int main()
{
	cin >> code;
	if (CheckCode(code))
		cout << "��ȷ";
	else
		cout << "����";

	getchar();
	getchar();
	return 0;
}

int CheckCode(char str[])
{
	int i, j, sum = 0;
	for (i = 0, j = 0; i < N - 1; i++)      
	{
		if (i != 1 && i != 6 && i != 11)
			sum += (str[i] - '0')*(++j);
	}
	if (sum % 11 == /*(int)*/(str[N - 1] - '0'))    //У��λ��0-9ʱ
		return 1;
	else if (str[N - 1] == 'X' || str[N - 1] == 'x')  //�����������0-9����ô���ж��ǲ���X
		return 1;
	else
		return 0;
}