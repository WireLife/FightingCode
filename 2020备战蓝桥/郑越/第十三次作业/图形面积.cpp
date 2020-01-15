//
//  main.cpp
//  *面积
//
//  Created by Richard.ZHENG on 2020/1/15.
//  Copyright © 2020 Richard.ZHENG. All rights reserved.
//

#include<iostream>

using namespace std;
int matrix[12][12];
int main(int argc, const char * argv[])
{
    int sum=0;
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
            matrix[i][j]=0;
    for(int i=0;i<12;i++)
    {
            matrix[i][0]=-1;
            matrix[0][i]=-1;
            matrix[i][11]=-1;
            matrix[11][i]=-1;
    }
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            cin>>matrix[i][j];
        }
     
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            if(matrix[i][j]==0&&matrix[i-1][j]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i][j-1]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i+1][j]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i][j+1]==-1)
                matrix[i][j]=-1;
        }
    for(int j=1;j<11;j++)
        for(int i=1;i<11;i++)
        {
            if(matrix[i][j]==0&&matrix[i-1][j]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i+1][j]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i][j-1]==-1)
                matrix[i][j]=-1;
            if(matrix[i][j]==0&&matrix[i][j+1]==-1)
                matrix[i][j]=-1;
        }
    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++)
        {
            if(matrix[i][j]==0)
            sum++;
        }
    cout<<sum<<endl;
    return 0;
}


