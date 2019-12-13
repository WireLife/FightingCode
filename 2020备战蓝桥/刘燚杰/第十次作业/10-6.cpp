#include<iostream>
using namespace std;

int a[1000] = {0};//素数
int b[1000] = {0};//第二行的数
int sum = 0;
int time = 0;//多少种情况
bool IsPrime(int n)
{
    int ok = 1;
    for(int i=2;i<n;i++)
    {
        if(n%i == 0)
        {
            ok = 0;
            break;
        }
    }
    return ok;
}
int Prime()
{
    int j = 0;
    for(int i=2;i<=1993;i++)
    {
        if(IsPrime(i))
        {
            a[j] = i;
            j++;
        }
    }
    return j;
}
int T5()
{
    int n = Prime();
    for(int i=0;i<n;i++)
        b[i] = a[i+1] - a[i];
    for(int i=0;i<n-1;i++)
    {
        sum += b[i];
        if(sum == 1898)
            time++;
    }
    return time;
}

int main()
{
    if(T5() == 0)
        cout<<"not exist"<<endl;
    else
        cout<<"the time of this situation:"<<T5()<<endl;
    return 0;
}


