#include<iostream>
using namespace std;
#include<map>
#include<cstring>

int main()
{
    map<int,string>a;
    int i = 0;
    int n = 0;
    cin>>n;
    a.clear();
    while(i < n)
    {
        cin>>a[i];
        i++;
    }
    string temp;
    string p;
    string q;
    int len = 0;
    for(int i=0;i<n;i++)
    {
        temp = a[i];
        len = temp.size();
        for(int j=0;j<len-1;j++)
        {
            p = temp.substr(0,j+1);
            q = temp.substr(j+1);
            for(int x=0;x<n;x++)
            {
                if(p == a[x])
                {
                    for(int y=0;y<n;y++)
                    {
                        if(q == a[y])
                            cout<<"compound:"<<temp<<endl;
                    }
                }
            }
        }
    }
    return 0;
}

