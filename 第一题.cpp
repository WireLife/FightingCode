/*已写完，运行正确
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
	default:return atof(a);//atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
		//参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分，如123.456或123e-2。
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
