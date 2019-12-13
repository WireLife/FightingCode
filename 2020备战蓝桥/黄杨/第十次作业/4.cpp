#include <stdio.h>
int main()
{
	float h;
	int i, n;
	printf("请输入高度h和落地次数n：");
	scanf("%f %d", &h, & n);
	float v=h/2;
	for(i=2; i<=n; i++)
	{
		h = h + 2*v;
		v = v/2;
	}
	printf("第%d次落地时，共经过了%f米\n", n, h);
	printf("第%d次落地时，反弹%f米\n", n, v);
}
