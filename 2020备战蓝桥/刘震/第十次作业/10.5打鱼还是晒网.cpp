/*���㻹��ɹ��*/


/*
//���ֱ����������Ժ�ڼ���
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (((n % 5) <= 3) ? "�������" : "����ɹ��");
	getchar();
	getchar();
	return 0;
}
*/

//���������������յĻ�,��ת��Ϊĳһ�����1990.1.1���ж�����
//��һ�֣�������д�����������1990.1.1���ж�����
//�ڶ��֣�ֱ�ӵ��ÿ⺯���ó�������������
#include<iostream>
using namespace std;
const int maxn = 11;

//�������������ھ���1990.1.1�ж�����
int count_day(char date[]);

//������
int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30 };

//�ж��Ƿ�Ϊ����
bool isRunyear(int i);

int main()
{
	char date[maxn];
	gets_s(date,11);
	cout << (((count_day(date) % 5) <= 3) ? "�������" : "����ɹ��");
	getchar();;
	return 0;
}

int count_day(char date[])
{
	//������
	int year, month, day, sum_day = 0;
	sscanf(date, "%d %d %d", &year, &month, &day);  //���ַ����������
	//����
	for (int i = 1990; i < year; i++)
		sum_day += (isRunyear(i)) ? 366 : 365;
	//����
	for (int i = 1; i < month; i++)  
		sum_day += month_day[i];
	//����
	sum_day += day;	
	return sum_day;
}

bool isRunyear(int i)
{
	return ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) ? true : false;
}