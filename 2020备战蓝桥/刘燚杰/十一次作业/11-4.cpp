#include<iostream>
#include<cstring>
using namespace std;

string str;
int sum = 0;

void T4(int n)
{
    if(str[n] >= '0' && str[n] <='9' )
        sum++;
    if(n > 0)
        T4(n-1);
    else
        cout<<sum<<endl;
}
int main()
{
    getline(cin,str);
    int len = str.length();
    T4(len-1);
    return 0;
}
