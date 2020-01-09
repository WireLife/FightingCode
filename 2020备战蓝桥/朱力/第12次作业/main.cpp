//12.1
#include<bits/stdc++.h>
//参考网上没懂题目意思
using namespace std;
int Max[200];
vector<string> s[1010];
int read(){
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
int main(){
    int n=0;string ss,buf;
    while(getline(cin,ss)){
        int t=0;
        stringstream S(ss);
        while(S>>buf){
            Max[t]=max((int)buf.length(),Max[t]);//将每一列的长度
            //最长的单词大小保存下来
            s[n].push_back(buf);//将当前的单词加入向量中储存
            t++;
        }
        n++;
    }
    cout<<setiosflags(ios::left);//将输出格式定义为左对齐输出
    for(int i=0;i<n;i++){
        int j=0;
        for(j;j<s[i].size()-1;j++)
            cout<<setw(Max[j]+1)<<s[i][j];//setw()将括号里的
            //参数的大小
            //作为输出的值占的位置大小
        cout<<s[i][j]<<endl;
    }
    return 0;
}
