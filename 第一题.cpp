/*��д�꣬������ȷ
#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
char a[100];
double f() 
{
	cin >> a;
	switch (a[0])
	{
	case '+':return f() + f();
	case '-':return f() - f();
	case '*':return f()*f();
	case '/':return f() / f();
	default:return atof(a);//atof()��ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�
		//����nptr�ַ����ɰ��������š�С�����E(e)����ʾָ�����֣���123.456��123e-2��
	}
}
int main()
{
	double ans = 0.0;
	ans = f();
	printf("%f\n", ans);
	system("pause");
	return 0;
}
*/
