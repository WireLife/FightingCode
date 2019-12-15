//
//  main.c
//  校验码
//
//  Created by Richard.ZHENG on 2019/12/13.
//  Copyright © 2019 Richard.ZHENG. All rights reserved.
//

#include <stdio.h>

int check_Code(char s[]){
    int i,j=1,code,sum=0;
    for(i=0;i<11;i++)//0-0000-0000-0
    {
        if(i!=1&&i!=6)
        {
            sum=sum+(s[i]-'0')*j;
            j++;
        }
    }
    if(sum%11==10)
        code='X'-'0';
    else
        code=sum%11;
    if(code==s[12]-'0')
        return 1;
    else
        return 0;
}
int main()
{
    char s[13];
    gets(s);
    int check_Code(char s[]);
    if(check_Code(s))
        printf("ISBN有效\n");
    else
        printf("ISBN无效\n");
}

