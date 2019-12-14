//有问题，未解决

#include <iostream>

#include <cstring>

using namespace std;



//123456分别表示上前左右后下

int x[6][6] = 

{

    1,2,3,4,5,6,

    5,1,3,4,6,2,

    2,6,3,4,1,5,    

    1,4,2,5,3,6,    

    1,5,4,3,2,6,    

    1,3,5,2,4,6

};//任取一个面位于前面 

int y[4][6] = 

{    

    1,2,3,4,5,6,    

    3,2,6,1,5,4,    

    6,2,4,3,5,1,    

    4,2,1,6,5,3

};//转动上下左右四个面

//通过两次循环遍历二维数组x和y即可考虑到骰子所有情况



bool color(char *a, char *b)

{

    for(int i=0;i<6;i++)

    {

        char t1[7];

        for(int j=0;j<6;j++)

            t1[j] == a[x[i][j]-1];

        t1[6] = '\0';

        for(int m=0;m<4;m++)

        {

            char t2[7];

            for(int n=0;n<6;n++)

                t2[n] = t1[y[m][n]-1];

            t2[6] = '\0';

            if(strcmp(t2,b) == 0)

                return true;

        }     

    }

    return false;

}

int main()

{

    int time = 0;//记录输入了多少组数据

    int o[5] = {0};

    string w1[5];

 //   char w[15] = {0};//用来存储用户输入的数据

    char a[7] = {0};//存储第一个骰子

    char b[7] = {0};//存储第二个骰子

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

        if(o[i] == 0)

            cout<<"FALSE"<<endl;

    }

    return 0;

}
