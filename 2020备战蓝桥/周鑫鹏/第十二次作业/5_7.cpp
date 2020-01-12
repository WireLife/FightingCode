#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M(vector<int>::iterator it,vector<int>::iterator it1);
int main()
{
    int a,t;
    int k=0;
    vector<int> vec;
    cout<<"0 to end"<<endl;
    cin>>t;
    while(t!=0)
    {
        vec.push_back(t);
        cin>>t;
    }
    cout<<"Î»ÖÃ:";
    cin>>a;
    vector<int>::iterator it=vec.begin();
    vector<int>::iterator b=it+a;
    while(1)
    {
        if(M(it,vec.end()))
        {
            if(it==b)
                break;
            k++;
        }
        else
        {
            vec.push_back(*it);
            if(it==b)
                b=vec.end();
        }
        it++;
    }
    cout<<"Íê³ÉÊ±¿Ì:"<<k<<endl;
    return 0;
}
int M(vector<int>::iterator it,vector<int>::iterator it1)
{
    vector<int>::iterator itr=it;
    auto a=max_element(it,it1);
    if(*it==*a)
        return 1;
    return 0;
}
