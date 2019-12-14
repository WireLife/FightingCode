#include<iostream>
using namespace std;

int Pell(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    else
        return 2*Pell(n-1)+Pell(n-2);
}
int main()
{
    int g=0;
    int w[1000]={0};
    cout<<"input"<<endl;
    cin>>g;//测试组数
    for(int i=0;i<g;i++)
        cin>>w[i];
    cout<<"the result"<<endl;
    for(int i=0;i<g;i++)
    {
        cout<<Pell(w[i])<<endl;
    }
}
