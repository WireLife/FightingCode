//12.1
#include<bits/stdc++.h>
//�ο�����û����Ŀ��˼
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
            Max[t]=max((int)buf.length(),Max[t]);//��ÿһ�еĳ���
            //��ĵ��ʴ�С��������
            s[n].push_back(buf);//����ǰ�ĵ��ʼ��������д���
            t++;
        }
        n++;
    }
    cout<<setiosflags(ios::left);//�������ʽ����Ϊ��������
    for(int i=0;i<n;i++){
        int j=0;
        for(j;j<s[i].size()-1;j++)
            cout<<setw(Max[j]+1)<<s[i][j];//setw()���������
            //�����Ĵ�С
            //��Ϊ�����ֵռ��λ�ô�С
        cout<<s[i][j]<<endl;
    }
    return 0;
}
