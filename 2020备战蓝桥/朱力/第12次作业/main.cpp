#include<stdio.h>
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int middle;
    vector<int> x;
    int a,b;
    int zu,n;
    int sumx=0;
    cin>>zu;
    while(zu){
        cin>>n;
    while(n){
        cin>>a>>b;
        sumx=sumx+a;
        x.push_back(a);
        n--;
    }
    middle=sumx/n;
    if(find(x.begin(),x.end(),middle))
    zu--;
    }
    //算出平均值，按照大小排序，然后在vector里面首尾一一对应取平均值，看是否的关于
    //总体均值相等;
}
