#include<stdio.h>
#include<stdlib.h>
char a[55];
double cal()
{
    scanf("%s",a);
    if(a[0]=='+')
        return cal()+cal();
    else if(a[0]=='-')
        return cal()-cal();
    else if(a[0]=='*')
        return cal()*cal();
    else if(a[0]=='/')
        return cal()/cal();
    else
        return atof(a);
}
int main()
{
    printf("%f\n",cal());
    return 0;
}
