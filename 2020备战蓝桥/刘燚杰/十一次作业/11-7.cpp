#include<iostream>
using namespace std;

string s1[100];
string s2[100];
string s[3]={"Rock","Scissors","Paper"};
int T7(int n)
{
    if(s1[n] == s2[n])
        return 0;
    for(int i=0;i<3;i++)
    {
        if(s1[n] == s[i] && s2[n] == s[i+1])
            return 1;
        if((s1[n] == s[2] && s2[n] == s[0]))
            return 1;
        if(s2[n] == s[i] && s1[n] == s[i+1])
            return 2;
        if((s2[n] == s[2] && s1[n] == s[0]))
            return 2;
    }
}
int main()
{
    int n = 0;//比赛场数
    cin>>n;
    string s0[1000];
    int time = 0;
    while(time != n)
    {
        cin>>s1[time]>>s2[time];
        if(T7(time) == 1)
            s0[time] = "Player1";
        else if(T7(time) == 0)
            s0[time] = "Tie";
        else if(T7(time) == 2)
            s0[time] = "Player2";
        time++;
    }
    for(int i=0;i<n;i++)
        cout<<s0[i]<<endl;
    return 0;
}
