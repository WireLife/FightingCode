#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
//仅适用于分子为个位数
struct Number
{
    int fenzi;
    int fenmu;
};

int fun1(int a,int b)//最大公约数1
{
    if(a%b == 0)
    {
        return b;
    }
    else
    {
        if(a>b)
            fun1(b,a%b);
        else
            fun1(b,a);
    }
}
int fun2(Number *N1,int n)//最大公约数2
{
    int z = fun1(N1[0].fenmu,N1[1].fenmu);
    if(n <= 2)
    {
        return z;
    }
    else
    {
        for(int i=2;i<n;i++)
        {
            z = fun1(z,N1[i].fenmu);
        }
        return z;
    }
}
int fun3(Number *N2,int n)//最小公倍数
{
    int result = 1;
    for(int i=0;i<n;i++)
        result = result*N2[i].fenmu;
    return result/fun2(N2,n);
}
void add(Number *N3,int n)//分数相加并化简
{
    int Fenmu = fun3(N3,n);
    int Fenzi = 0;
    for(int i=0;i<n;i++)
        Fenzi += ((Fenmu/N3[i].fenmu)*N3[i].fenzi);
    int gcd = fun1(Fenmu,Fenzi);    
    if(gcd != 1)
    {
        Fenzi = Fenzi/gcd;
        Fenmu = Fenmu/gcd;
    }
    cout<<Fenzi<<'/'<<Fenmu<<endl;
}
int main()
{
    int n=0;//n表示分数的个数
    string a[10];
    struct Number N[10];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    // int l[10] = {0};
    // for(int i=0;i<n;i++)
    // {
    //     l[i] = strlen(a[i]);
    // }
    for(int i=0;i<n;i++)
    {
        N[i].fenzi = stoi(a[i].substr(0,1));
        N[i].fenmu = stoi(a[i].substr(2));
    }
    add(N,n);
    return 0;
}
