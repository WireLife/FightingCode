//不知道为什么输入7个0的时候结果是LOOP。。。
#include<iostream>
using namespace std;
#include<cmath>

int a[100] = {0};
int b[100] = {0};
int num2 = 0;

void f2(int n)
{
    for(int i=0;i<n;i++)
    {
        b[i] = a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i < n-1)
            a[i] = abs(b[i] - b[i+1]);
        else
        {
            a[i] = abs(a[i] - b[0]);
        }
    }
}
bool Judge(int n)
{
    while(num2 <= 1000)
    {
        int num1 = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 0)
                num1++;
        }
        if(num1 == n)
        {
            return true;
        }
        else
        {
            f2(n);
            num2++;
        }
    }
    return false;
}
int main()
{
    int n,m = 0;//m表示每组数据的个数
    int temp = 0;
    string str[100];
    cin>>n;
    while(temp != n)
    {
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>a[i];
        f2(m);
        if(Judge(m) == true)
            str[temp] = "ZERO";
        else
            str[temp] = "LOOP";
        temp++;
    }
    for(int i=0;i<n;i++)
        cout<<str[i]<<endl;
    return 0;
}
