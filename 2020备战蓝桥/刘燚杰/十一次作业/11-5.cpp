#include<iostream>
#include<cstring>
using namespace std;

string str;
char key;

bool T5(int n)
{
    int ok;
    for(int i=0;i<n;i++)
    {
        key = str[i];
        for(int j=i+1;j<n;j++)
        {
            if(key == str[j])
            {
                ok = 0;
                break;
            }
            else
            {
                ok = 1;
                continue;
            }
        }
        if( ok == 1)
            return true;
    }
    return false;
}
int main()
{
    cout<<"please input a string:"<<endl;
    getline(cin,str);
    int len = str.length();
    if(T5(len))
        cout<<key<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
