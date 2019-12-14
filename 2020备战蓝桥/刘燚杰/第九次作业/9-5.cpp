#include<iostream>
using namespace std;

int apple(int a,int b)
{
    if(a == 1 ||b == 1)//一个苹果或一个盘子都只有一种方法
        return 1;
    if(a>b)
        return apple(b,b);
    else
        return apple(a,b-1)+apple(a-b,b);
}
int main()
{
    int t = 0;//测试数据组数
    cin>>t;
    int time = 0;//次数
    int m = 0;//苹果
    int n = 0;//盘子
    int o[20]={0};
    while(time !=t )
    {
        cin>>m>>n;
        o[time] = apple(m,n);
        time++;
    }
    for(int i=0;i<t;i++)
        cout<<o[i]<<endl;
    return 0;
}
