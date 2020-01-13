#include <iostream>
#include <map>
//13.6
using namespace std;

int main()
{
    int sum;
    int i;
    map<int,int> ms;
    int num,m,n;
    int k,total=1;
    cin>>num>>k;
    int b=k;
    while(b){
        cin>>m>>n;
        ms.insert(pair<int, int>(m,n));
        b--;
    }
    cout<<endl;
    for(i=0;i<k;i++){
        total=total*2;
    }
    cout<<total<<endl;
    return 0;
}
