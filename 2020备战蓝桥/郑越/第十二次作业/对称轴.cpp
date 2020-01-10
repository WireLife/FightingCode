#include <iostream>
using namespace std;
int max(int a[][2],int N)
{
    int Max=a[0][1],i;
    for(i=1;i<N;i++)
    {
        if(a[i][1]>Max)
            Max=a[i][1];
    }
    return Max;
}
int main(int argc, const char * argv[]) {
    int N,i,j,xnSym=0,xSym=0,m,x,Max,xS,k,key;
    scanf("%d",&N);
    int co_ord[N][2];
    int max(int a[][2],int N);
    Max=max(co_ord,N);
     for(i=0;i<N;i++)
        scanf("%d %d",&co_ord[i][0],&co_ord[i][1]);
    k=0;
    for(i=0;i<N;i++)
    {
        if(co_ord[i][1]==co_ord[0][1])
        {
            xnSym=xnSym+co_ord[i][0];
            k++;
        }
    }
    xSym=xnSym/k;
    m=co_ord[0][1];
    key=1;
        for(i=1;i<N;i++)
        {
            m=co_ord[i][1];
            x=0;
            k=0;
            for(j=0;j<N;j++)
            {
                
                if(co_ord[j][1]==m)
                {
                    x=x+co_ord[j][0];
                    k++;
                }
            }
            xS=x/k;
            if(xS!=xSym)
            {
                key=0;
            }break;
        }
    if(key==1)
        cout<<"Yes"<<endl;
    else
        cout<<"NO"<<endl;
        
        
    return 0;
}
