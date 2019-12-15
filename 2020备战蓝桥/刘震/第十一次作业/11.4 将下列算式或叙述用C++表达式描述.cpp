/*11.4 将下列算式或叙述用C++表达式描述。*/

#include<iostream>
#include<cmath>
using namespace std;

double PI = 3.1415926;

int main()
{
	double x = 1, c = 1, y = 2, a = 1, b = 1, k = 1;
	cout << PI / 2 + sqrt(asin(x) * asin(x) + c * c) << endl;
	cout << (x + y) / ((x - y) * a * y) << endl;
	cout << (sqrt(x * x + y * y) >= a) && (sqrt(x * x + y * y) <= b);
	cout << (a != b) << (a != c) << (b != c) << endl;

	cout << (k <= 20) << endl;
	getchar();
	return 0;
}