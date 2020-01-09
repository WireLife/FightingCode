#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    cout<<"请输入是几元组"<<endl;
    cin>>n;
    cout<<"请输入数据成员"<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k=1000;
    int count=0;
    while(k){
        a[n]=abs(a[0]-a[n]);
        for(int i=0;i<n-1;i++){
            a[i]=abs(a[i+1]-a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i]==0)
                count++;
        }
        if(count==n)
        {
            cout<<"is zero!"<<endl;
            return 0;
        }
        else
        {
            k--;
            continue;
        }
    }
    cout<<"is loop!"<<endl;
    return 0;
}
