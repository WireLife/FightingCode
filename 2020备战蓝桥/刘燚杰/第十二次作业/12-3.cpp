#include<iostream>
using namespace std;
#include<queue>

int main()
{
    queue<int>a;
    int n = 0;
    cin>>n;
    for(int i=0;i<n;i++)
        a.push(i+1);
    cout<<"Discarded cards:";
    while(1)
    {
        cout<<a.front()<<" ";
        a.pop();
        if(a.size() == 1)
            break;
        a.push(a.front());
        a.pop();
    }
    cout<<endl;
    cout<<"Remaining card:"<<a.front()<<endl;
    cout<<endl;
    return 0;
}
