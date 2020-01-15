//7.家庭问题
//借鉴加以修改完成
#include<iostream>
using namespace std;
#define N 101
int father[N];
int a[N];
int Find(int x){
    if(father[x]==x)
        return x;
    return father[x]=Find(father[x]);
}
void Union(int x,int y){
    int f1=Find(x);
    int f2=Find(y);
    if(f1!=f2)
        father[f2]=f1;
}
int main(){
    int n,k;//n为总人数，k为关系总数
    cin>>n>>k;
    for(int i=1;i<=n;i++)//对人进行赋值，分别赋值为1， 2，3...n
        father[i]=i;
    for(i=1;i<=k;i++){//对关系进行输入
        int x,y;
        cin>>x>>y;
        Union(x,y);
    }
    for(i=1;i<=n;i++)
        a[Find(i)]++;
    int cnt_1=0,cnt_2=0; 
	for(i=1;i<=n;i++)
        if(father[i]==i)
            cnt_1++;
    for(i=1;i<=n;i++)
        if(a[i]>cnt_2)
            cnt_2=a[i]; 
    cout<<cnt_1<<" "<<cnt_2<<endl;
    return 0;
}
