//
//  main.cpp
//  产生数
//
//  Created by Richard.ZHENG on 2020/1/15.
//  Copyright © 2020 Richard.ZHENG. All rights reserved.
//

#include <iostream>
//#include <map>
int main(int argc, const char * argv[]) {
    using namespace std;
    char orNumber[4];
    int ornumber[4],a[10],count_n=1,i,j,k,key,rules_n;
    for(i=0;i<10;i++)
        a[i]=1;
    scanf("%s",orNumber);
    cin>>rules_n;
    int rules[rules_n][2];
    for(i=0;i<rules_n;i++)
        for(j=0;j<2;j++)
            scanf("%d",&rules[i][j]);
    for(key=0;key<10;key++)
    {
        k=key;
        for(i=0;i<rules_n;i++)
            if(rules[i][0]==k)
            {
                a[key]++;
                k=rules[i][1];
            }
    }
    for(i=0;i<strlen(orNumber);i++)
    {
        ornumber[i]=orNumber[i]-'0';
//        printf("%d",ornumber[i]);
        count_n=count_n*a[ornumber[i]];
    }
    printf("%d\n",count_n);
                
    return 0;
}
