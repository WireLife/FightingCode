#include<stdio.h>
int n;
float h,sum;
float f(int i)
{
    h/=2;
    if(i<n){
        sum+=h*3/2;
        return f(++i);
    }
    else
         return sum+=h;
}
int main()
{
    scanf("%f%d",&h,&n);
    h*=2;
    sum=f(1);
    printf("%.2f %.2f",sum,h);
    return 0;
}
