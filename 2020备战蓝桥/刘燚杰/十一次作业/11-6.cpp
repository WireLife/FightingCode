#include<iostream>
#include<cstring>
using namespace std;

string str1;
string str2;

bool T6(double s,int n)
{
    int count = 0;//相同碱基对个数
    for(int i=0;i<n;i++)
    {
        if(str1[i] == str2[i])
            count++;
    }
    double result = (double)count/(double)n;
    if(result >= s)
        return true;
    else
        return false;
}
int main()
{
    double stan = 0;
    cout<<"please input the standard:"<<endl;
    cin>>stan;
    cout<<"please input the first string:"<<endl;
    cin>>str1;
    cout<<"please input the second string having the same length of the first one:"<<endl;
    cin>>str2;
    int len = str1.length();
    if(T6(stan,len))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}
