#include<iostream>
#include<cstring>
using namespace std;

string str;
int sum1 = 0; //大写字母
int sum2 = 0;//小写字母
int sum3 = 0;//数字
int sum4 = 0;//空格
int sum5 = 0;//其他

void T1(int n)
{
    if(str[n] >= 'A' && str[n] <= 'Z')
        sum1++;
    else if(str[n] >= 'a' && str[n] <= 'z')
        sum2++;
    else if(str[n] >= '0' && str[n] <= '9')
        sum3++;
    else if(str[n] == ' ')
        sum4++;
    else
        sum5++;
    if(n > 0)
        T1(n-1);
    else
    {
        cout<<"DX:"<<sum1<<endl;
        cout<<"XX:"<<sum2<<endl;
        cout<<"Number:"<<sum3<<endl;
        cout<<"Blank:"<<sum4<<endl;
        cout<<"Others:"<<sum5<<endl;    
    }
}


int main()
{
    cout<<"please enter a string:"<<endl;
    //cin>>str;
    getline(cin,str);//cin在输入遇到空格时结束
    int len = str.length();
    T1(len-1);
    return 0;
}
