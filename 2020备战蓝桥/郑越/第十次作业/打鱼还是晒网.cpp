//
//  main.c
//  打鱼还是晒网
//
//  Created by Richard.ZHENG on 2019/12/15.
//  Copyright © 2019 Richard.ZHENG. All rights reserved.
//

#include <stdio.h>
#include <string.h>
//int leapYear(int year){
//    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)?1:0;
//}

int dayFrom(char Date[],int year,int month,int day){
    int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month_dayl[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    
    int leapYear(int year);
    int mday=0;
    for(int i=1990;i<year;i++)
    {
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            mday=mday+366;
        else
            mday=mday+365;
    }
    for(int i=1;i<month;i++)
    {
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            mday=mday+month_dayl[i];
        else
            mday=mday+month_day[i];
    }
    mday=mday+day;
    return mday;
}

int main(int argc, const char * argv[]) {
    int year,month,day;
    int Day;
    char Date[11];//10 or 11
    printf("请输入:年-月-日\n");//0000-00-00
    gets(Date);
    sscanf(Date,"%d-%d-%d",&year,&month,&day);
    int dayFrom(char Date[],int year,int month,int day);
    Day=dayFrom(Date,year,month,day);
    printf("%d\n",Day);
    if(Day%5<=3)
        printf("打鱼\n");
    else
        printf("晒网\n");
    return 0;
}
