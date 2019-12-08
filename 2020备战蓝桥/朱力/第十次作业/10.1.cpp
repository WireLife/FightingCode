#include<stdio.h>
#include<iostream>
using namespace std;

int i = 0;

int main()
{
	char s[17];
	int sum = 0;
	while (scanf_s("%c", &s[i])!=EOF)
	{
		i++;
	}
	sum = (1 * (int)s[4] + 2 * (int)s[6] + 3 * (int)s[7] + 4 * (int)s[8] + 5 * (int)s[9] + 6 * (int)s[11] + 7 * (int)s[12] + 8 * (int)s[13] + 9 * (int)s[14]);
	sum = sum % 11;
	if (sum == 10)
	{
		if (s[16] == 'X')
			printf("YES");
		else
			printf("NO");
	}
	else if (sum == (int)s[16])
		printf("YES");
	else
		printf("NO");

	return 0;

}