#include<iostream>
using namespace std;

char s[10][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
int number[10] = {0,0,3,3,3,3,3,4,3,4};
int sum = 0;

void T3(int *a,int *b,int index,int n)
{
    if(index == n)
    {
        for(int i=0;i<n;i++)
        {
            sum++;
            cout<<s[a[i]][b[i]];
            if(sum%n == 0)
            {
                cout<<endl;
            }
        }
        return;
    }
    for(b[index]=0;b[index]<number[a[index]];b[index]++)
        T3(a,b,index+1,n);
}
int main()
{
    int a[11];
    int b[11];
    int n = 0;
    cout<<"please input the length of the phone number:"<<endl;
    cin>>n;
    cout<<"please input a phone number"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    T3(a,b,0,n);
    cout<<sum<<endl;
    return 0;
}
