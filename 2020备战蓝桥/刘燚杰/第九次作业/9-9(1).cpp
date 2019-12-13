#include<iostream>
#include<cstring>
using namespace std;

bool color(char a[],char b[])
{
    for(int i=1;i<=6;i++)
    {
        if(a[i] == '*')//若已标记，则无需再次标记 
            continue;
        for(int j=1;j<=6;j++)
        {
            if(b[j] == '*')
                continue;  
            if(a[i] == b[j])
            {
                if(a[7-i] == b[7-j])
                {
                    a[i] = a[7-i] = b[j] = b[7-j] = '*';
                    break;
                }
            }
        }
    }
    for(int i=1;i<=6;i++)
    {
        if(!(a[i]==b[i]))
            return false;
    }
    return true;
}
int main()
{
    int time = 0;//记录输入了多少组数据
    int o[5] = {0};
    string w1[5];
    char a[20] = {0};//存储第一个骰子
    char b[20] = {0};//存储第二个骰子
    while(time != 3)
    {
        cin>>w1[time];
        char w2[20];
        strcpy(w2,w1[time].c_str());
        for(int i=0;i<6;i++)
        {
            a[i+1] = w2[i];
            b[i+1] = w2[i+6];
        }
        o[time] = color(a,b);
        time++;
    }
    for(int i=0;i<time;i++)
    {
        if(o[i] == 1)
            cout<<"TRUE"<<endl;
        else if(o[i] == 0)
            cout<<"FALSE"<<endl;
    }
    return 0;
}
