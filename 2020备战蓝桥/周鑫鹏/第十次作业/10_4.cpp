#include<stdio.h>
#include<math.h>
void S(int n);
int main()
{
	int n;
	printf("Enter n=");
	scanf("%d",&n);
	S(n);
	return 0;
}
void S(int n)
{
	double s=1.0,h=1.0;
	for(int i=1;i<n;i++)
	{
		h=h*(1.0/2);
		s+=h;
	}
	printf("h1=%fh\ns=%fh\n",h/2,s);

}
