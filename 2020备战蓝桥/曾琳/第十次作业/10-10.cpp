/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[9], ii = 0, i, a1, a2, a3, a4, b1, b2, b3, b4, flag;
	for (i = 1; i <= 8; i++) 
	{
		printf("Please enter [%d]number:", i);
		scanf("%d", &a[i]);
		ii += a[i];
	}
	printf("******************************************\n");
	if (ii % 2) /*和为奇数则输入的8个数不可用
	{
		printf("Sorry they can't be constructed required cube!\n");
		exit(0);
	}
	for (flag = 0, a1 = 1; a1 <= 8; a1++) /*flag:完成标记.flag=1;表示完成
		for (a2 = 1; a2 <= 8; a2++) /*采用八重循环建立八个整数的全排列
			if (a2 != a1) /*前两个数不能相同
				for (a3 = 1; a3 <= 8; a3++)
					if (a3 != a2 && a3 != a1) /*前三个数不能相同
						for (a4 = 1; a4 <= 8; a4++)
							if (a4 != a3 && a4 != a2 && a4 != a1) /*前四个数不能相同
								for (b1 = 1; b1 <= 8; b1++)
									if (b1 != a4 && b1 != a3 && b1 != a2 && b1 != a1) /*不能相同
										for (b2 = 1; b2 <= 8; b2++)
											if (b2 != b1 && b2 != a4 && b2 != a3 && b2 != a2 && b2 != a1)
												for (b3 = 1; b3 <= 8; b3++)
													if (b3 != b2 && b3 != b1 && b3 != a4 && b3 != a3 && b3 != a2 && b3 != a1)
														/*不能取相同的数
														for (b4 = 1; b4 <= 8; b4++)
															if (b4 != b2 && b4 != b1 && b4 != b3 && b4 != a4 && b4 != a3 && b4 != a2 && b4 != a1)
																if (a[b1] + a[b2] + a[b3] + a[b4] == ii / 2
																	&& a[a1] + a[a2] + a[b1] + a[b2] == ii / 2
																	&& a[a1] + a[a4] + a[b1] + a[b4] == ii / 2)
																{
																	flag = 1; goto out; /*满足条件则将flag置1后退出
																}
out:
	if (flag)
	{
		printf("They can be constructed required cube as follow:\n");
		printf(" /%2d............/%2d\n", a[a4], a[a3]);
		printf(" %2d/............%2d/|\n", a[a1], a[a2]);
		printf(" | | | |\n");
		printf(" | | | |\n");
		printf(" | %2d| | |%2d\n", a[b4], a[b3]);
		printf(" /................/\n");
		printf(" %2d/.............%2d/\n", a[b1], a[b2]);
	}
	else printf("Sorry they can't be constructed required cube!\n");
}

*/
