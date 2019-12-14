//
//  main.c
//  弹球高度
//
//  Created by Richard.ZHENG on 2019/12/13.
//  Copyright © 2019 Richard.ZHENG. All rights reserved.
//

#include <stdio.h>

int main()
{
    int H,N;
    float s,h;
    printf("请输入起始高度和次数\n");
    scanf("%d %d",&H,&N);
    s=H;
    h=H/2;
    for(int i=2;i<=N;i++)
    {
        s=s+2*h;
        h=h/2;
    }
    printf("第%d次落地经过%fm,第%d次反弹高度为%fm\n",N,s,N,h);
    
}

