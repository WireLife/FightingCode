#include <stdio.h>
int mouthlen[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
typedef struct 
{
    int year;
    int mouth;
    int day;
}Date;

void AddDay(Date* date,int add)
{
    if(date->day+add>mouthlen[date->mouth])
    {
        date->day=add-(mouthlen[date->mouth]-date->day);
        AddMouth(date);
    }
    else
    {
        date->day+=add;
    }
    
}


void AddMouth(Date* date)
{
    if(date->mouth==12)
    {
        date->year++;
        date->mouth=1;
    }
    else
    {
        date->mouth++;
    }
    
}

int main()
{
    
    Date start;
    Date end;
    char put[][8]={"打鱼","晒网"};
    scanf("%d%d%d",&start.year,&start.mouth,&start.day);
    scanf("%d%d%d",&end.year,&end.mouth,&end.day);
    int flag=0;
    
    int key[]={3,2};
    int tmp=0;
    while(1)
    {
        if(tmp<key[flag])
        {
            tmp++;
            AddDay(&start,1);
        }
        else
        {
            tmp=0;
            flag=(flag+1)%2;
        }
        if(start.year==end.year&&start.mouth==end.mouth&&start.day==end.day)
        {
            printf("%s",put[flag]);
            break;
        }
    }
}