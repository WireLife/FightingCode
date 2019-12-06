#include<stdio.h>
int yueshu(int x,int y)
{
	int t;
	if(x<y)
	{t=x;x=y;y=t;}
	if(x%y==0)
		return y;
	else
	{
		t=x%y;x=y;y=t;
		yueshu(x,y);
	}
}
int beishu(int x,int y,int n)
{
	return (x*y)/n;
}
int main()
{
	int n,a[20],b[20];
	int i,m,fen=0,max;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	max=b[0];
	for(i=1;i<n;i++)
   {
	 m=yueshu(max,b[i]);
     max=beishu(max,b[i],m);
   }
   for(i=0;i<n;i++)
    fen=fen+a[i]*(max/b[i]);
   if(fen<max)
   {
	   if(max%fen==0)
	   {
		   fen=fen/(yueshu(max,fen));
		   max=max/(yueshu(max,fen));
	   }
	   printf("%d/%d",fen,max);
   }
   else if(fen>max&&max!=1)
		   printf("%d",fen/max);
	else if(fen==max||max==1)
		   printf("%d",fen);
	return 0;
}

