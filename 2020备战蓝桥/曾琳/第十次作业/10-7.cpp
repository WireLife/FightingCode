/*#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
int ans, sum;
int a[5][5];
int vis[17];
void dfs(int step)
{

	int x = step / 4;
	int y = step % 4;

	if (step >= 16)
	{
		ans++;
		int s = 0, ok = 0;
		for (int i = 0; i < 4; i++)
		{
			s = 0;
			for (int j = 0; j < 4; j++)
				s = s + a[j][i];
			if (s != 34)
			{
				ok = 1;
				return;
			}
		}
		s = a[3][0] + a[3][1] + a[3][2] + a[3][3];
		if (s != 34)
			return;
		s = a[0][0] + a[1][1] + a[2][2] + a[3][3];
		if (s != 34)
			return;
		s = a[3][0] + a[2][1] + a[1][2] + a[0][3];
		if (s != 34)
			return;
		if (!ok)
		{
			sum++;
			//            for(int i=0; i<4; i++)
			//            {
			//                for(int j=0; j<4; j++)
			//                {
			//                    printf("%d ",a[i][j]);
			//                }
			//                printf("\n");
			//            }
			//            printf("\n");
		}
		return;
	}
	else if (step == 4)
	{
		if (a[0][0] + a[0][1] + a[0][2] + a[0][3] != 34)
			return;
	}
	else if (step == 8)
	{
		if (a[1][0] + a[1][1] + a[1][2] + a[1][3] != 34)
			return;
	}
	else if (step == 12)
	{
		if (a[2][0] + a[2][1] + a[2][2] + a[2][3] != 34)
			return;
	}
	for (int i = 2; i <= 16; i++)
	{
		if (!vis[i])
		{
			a[x][y] = i;
			vis[i] = 1;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	sum = 0;
	a[0][0] = 1;
	dfs(1);
	printf("%d\n", sum);
	return 0;
}
*/
