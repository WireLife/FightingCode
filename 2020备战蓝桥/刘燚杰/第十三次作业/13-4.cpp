#include<iostream>
using namespace std;
#include<fstream>

int area[10][10];
int main()
{
    int count = 0;
    ifstream file("areain.txt");
    for(int i=0;i<10;i++)//将文件中的数据保存在二维数组里
    {
        for(int j=0;j<10;j++)
            file>>area[i][j];
    }
    for(int i=0;i<10;i++)//另四周都为2
    {
        area[i][0] = 2;
        area[0][i] = 2;
        area[i][9] = 2;
        area[9][i] = 2;
    }
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            if(area[i][j] == 0 && area[i-1][j] == 2)//上
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i][j-1] == 2)//左
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i+1][j] == 2)//下
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i][j+1] == 2)//右
                area[i][j] == 2;
        }
    }
     for(int j=1;j<9;j++)
    {
        for(int i=1;i<9;i++)    
        {
            if(area[i][j] == 0 && area[i-1][j] == 2)//上
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i][j-1] == 2)//左
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i+1][j] == 2)//下
                area[i][j] = 2;
            if(area[i][j] == 0 && area[i][j+1] == 2)//右
                area[i][j] == 2;
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(area[i][j] == 0)
                count++;
        }
    }
    cout<<count<<endl;
    file.close();
    return 0;
}
