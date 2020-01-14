#include <iostream>
using namespace std;

int N,A,B;
int a[200],b[200];
int result = 99999;

void DFS(int now, int step)//深度优先搜索
{
    if(step > N)
        return;
    if(now == B)
        result = min(result, step);
    else if(step <= result)
    {
        b[now] = 1;
        if(now - a[now] >= 1 && !b[now - a[now]])
            DFS(now - a[now], step+1);
        if(now + a[now] <= N && !b[now + a[now]])
            DFS(now + a[now], step+1);
        b[now] = 0;
    }
}
int main()
{
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    b[A] = 1;
    DFS(A, 0);
    if(result != 99999)
        cout<<result<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}
