#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,t,k=0;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(1)
    {
        t=a[0];
        a[0]=fabs(a[0]-a[1]);
        a[1]=fabs(a[1]-a[2]);
        a[2]=fabs(a[2]-a[3]);
        a[3]=fabs(a[3]-t);
        k++;
        if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
        {
            cout<<"0"<<endl;
            break;
        }
        if(k>=1000)
        {
            cout<<"1"<<endl;
            break;
        }
    }
    cout<<k<<endl;
return 0;
}






