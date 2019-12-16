#include<iostream>
#include<cstring>
using namespace std;

string str1;
string str2;

void T2()
{
    int i,j=0;
    while(str1[i] != '\0')
        i++;
    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++,j++;
    }
    str1[i] = '\0';
    for(int n=0;n<i;n++)
        cout<<str1[n];
} 

int main()
{
    cout<<"please input two strings:"<<endl;
    cin>>str1>>str2;
    cout<<"after linking:"<<endl;
    T2();
}
