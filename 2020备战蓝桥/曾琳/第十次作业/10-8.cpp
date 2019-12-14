#include<stdio>
int main(void)
{
	long int a, b, c;
	while (true)
	{
		printf("Please enter a optional fraction(a/b):");
		scanf("%ld/%ld", &a, &b); /*输入分子a和分母b*/
		printf("It can be decomposed to:");
		while (true)
		{
			if (b%a) /*若分子不能整除分母*/
				c = b / a + 1; /*则分解出一个分母为b/a+1的埃及分数*/
			else { c = b / a; a = 1; } /*否则，输出化简后的真分数(埃及分数)*/
			if (a == 1)
			{
				printf("1/%ld\n", c);
				break; /*a为1标志结束*/
			}
			else
				printf("1/%ld + ", c);
			a = a * c - b; /*求出余数的分子*/
			b = b * c; /*求出余数的分母*/
			if (a == 3) /*若余数为3，输出最后两个埃及分数*/
			{
				printf("1/%ld + 1/%ld\n", b / 2, b); break;
			}
		}
	}
	return 0;
}
