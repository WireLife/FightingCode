#include<stdio.h>
int main()
{
    int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int year,month,day,rnum=0,numtry;
    printf("enter(year-month-day)\n");
    scanf("%d-%d-%d",&year,&month,&day);
    for(int i=1990;i<year;i++)
        if(year%400==0)
            rnum++;
        else if(year%4==0&&year%100!=0)
            rnum++;
    if( (year%400==0)||(year%4==0&&year%100!=0) ){
        numtry=365*(year-1990)+rnum;
        for(int i=1;i<month;i++)
            numtry+=month2[i];
        numtry+=day;
    }
    if(numtry%5<=3)
        printf("fishing\n");
    else 
        printf("cleaning net");
    return 0;
}
