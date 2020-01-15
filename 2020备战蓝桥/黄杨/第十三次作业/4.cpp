#include<iostream.h>
int a[20][20];
int main()
{
    int i,j,k=0;
    for(i=1;i<=10;i++)
      for(j=1;j<=10;j++)
         cin>>a[i][j];
    for(i=1;i<=10;i++)
    {
           j=1;
        while(a[i][j]!=1&&j<=10)
           {
               a[i][j]=2;
               j++;
           }    
           j=10;
           while(a[i][j]!=1&&j>=1)
           {
               a[i][j]=2;
               j--;
           }
    }
    for(i=1;i<=10;i++)
      for(j=1;j<=10;j++)
        if(a[i][j]==0&&(a[i][j+1]==2||a[i][j-1]==2||a[i+1][j]==2||a[i-1][j]==2))
          a[i][j]=2;
    for(i=1;i<=10;i++)
        for(j=1;j<=10;j++)
          if(a[i][j]==0)
            k++;
    cout<<k<<endl;  
    return 0; 
}
