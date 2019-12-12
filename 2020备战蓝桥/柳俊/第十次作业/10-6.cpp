#include<stdio.h>
int sum,final;
int f(int n)
{
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}
void g(int n[300],int i)
{
    if(final<1898){
        final+=n[i];
        g(n,i+1);
    }
    else if(final==1898)
    {
        sum++;
        final=0;
        return;
    }
    else{
        final=0;
        return;
    }
}
int main()
{
    int num[300]={2,},l=0,k=1,_num[300];
    for(int i=3;i<=1993;i++)
        if(f(i)){
            num[k]=i;
            k++;
        }
    for(int i=0;i<k-1;i++){
        _num[i]=num[i+1]-num[i];
        l++;
    }
    for(int i=0;i<l;i++)
        g(_num,i);
    printf("%d",sum);
    return 0;
}
