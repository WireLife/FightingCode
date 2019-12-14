#include<iostream>
using namespace std;


double recorder = 0;

double T4(double h,int n)
{
    double sum = h;
    for(int i=0;i<n-1;i++)
    {
        h = h/2;
        sum += h;//落下
        sum += h;//弹起
    }
    recorder = h;
    return sum;
}

int main()
{
    double h = 0;
    int n = 0;
    cout<<"input the height and bouncind times:"<<endl;
    cin>>h>>n;
    cout<<"all journey of the ball when bouncing n times:"<<T4(h,n)<<endl;
    cout<<"the meter of bouncing:"<<recorder<<endl;
    return 0;
}
