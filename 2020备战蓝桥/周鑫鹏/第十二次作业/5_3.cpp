#include <iostream>

using namespace std;

int main()
{
    int a[100]={0};
    for(int i=1;i<51;i++)
    {
        a[i-1]=i;
    }
    int j=0;
    int k=0;
    while(a[j+1]!=0)
    {
        cout<<a[j]<<endl;
        a[50+k]=a[j+1];
        k++;
        j+=2;
    }
    cout<<"End:"<<a[j]<<endl;
    return 0;
}
