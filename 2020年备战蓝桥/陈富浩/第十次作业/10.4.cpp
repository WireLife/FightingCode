#include<stdio.h>
double main()
{
    double hight,accum;
	int n,i;
	printf("输入球所在高度和落下的次数：\n");
	scanf("%Lf%d",&hight,&n);
	accum=hight;
    for(i=1;i<=n;i++)
	{
		hight=hight/2;		
		accum+=hight*2;
	}
	accum-=hight*2;
	printf("第%d次落地时共经过%Lf米\n第%d次反弹高度为%Lf米\n",n,accum,n,hight);
	return 0;
}
