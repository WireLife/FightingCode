#include <iostream>
using namespace std;

bool Judge(int y,int x)
{    
    if(y>x) 
        return false;    
    if(y==x) 
        return true;    
    if(Judge(2*y+1,x) || Judge(3*y+1,x))
        return true;    
    return false;
}
int main()
{    
    int k=0, x=0;
    cin>>k;
    cin.get();//去除逗号
    cin>>x;
    bool result = Judge(k,x);
    if(result)
        cout<<"YES"<<endl;    
    else 
        cout<<"NO"<<endl;
}
