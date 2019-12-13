#include<iostream>
using namespace std;

int count = 1;//本身算一个数
int digui(int x)
{
    for(int i=1;i<=x;++i)
    {
        if(i >= 2)
            count += i/2;
        digui(i/2);
    }
}
int Count(int n)
{
    count += n/2;//加上一个自然数后共有的组合  n/2 = 6
    digui(n/2);
    // for(int i=1;i<=n/2;++i)     i<=6
    // {
    //     if(i >= 2)
    //     {   
    //         count += i/2;//加上两个自然数后共有的组合
    //     }
    //     for(int j=1;j<=i/2;j++)   
    //     {
    //         if(j >= 2)
    //             count += j/2;//加上三个自然数后共有的组合
    //     }
    // }
    return count;
}

int main()
{
    int n=0;
    cout<<"please enter a natural number that less than or equal to 1000:"<<endl;
    cin>>n;
    cout<<"the result :"<<Count(n)<<endl;
    return 0;
}
