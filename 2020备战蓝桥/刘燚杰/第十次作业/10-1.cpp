
#include<iostream>
using namespace std;

bool T1(char *s)
{
    int sum = 0;
    int j = 1;
    for(int i=4;i<=14;i++)
    {
        if(s[i] == '-')
        {
            continue;
        }
        sum += (int(s[i])-48)*j;
        j++;
    }
    if(sum%11 == 10)
    {
        if(s[16] == 'X')
            return true;
        else
            return false;
    }
    else
    {
        if(sum%11 == (int(s[16])-48))
            return true;
        return false;
    }
}

int main()
{
    char s[100]={0};
    while(cin>>s)
    {
        if(T1(s))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
    }
    return 0;
}
