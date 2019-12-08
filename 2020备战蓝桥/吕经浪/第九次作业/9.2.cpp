#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char s1[101], s2[101], s3[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int num = 0, len, i, j, k = 1;
	scanf("%s", s1);
	len = strlen(s1);
	for (i = 0; i < len; i++)
	{
		num = num + k * s1[len - 1 - i];
		k = k * 2;
	}
	i = 0;
	while (num != 0)
	{
		s2[i] = s3[num % 16];
		num = num / 16;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		printf("%c", s2[j]);
	printf("\n");
	return 0;
}
