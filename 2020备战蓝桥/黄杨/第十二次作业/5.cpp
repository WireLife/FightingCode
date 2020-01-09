#include <iostream>   
#include <cstdlib>  
#include <string>  
#include <map>  
#define INF 1E9  
using namespace std;  
map<string,bool> hash;  
string s[120000];  
int main()  
{  
    int i,j;  
    int cnt=0;  
    hash.clear();  
    while(cin>>s[cnt])  
    {  
        hash[s[cnt]]=1;  
        cnt++;  
    }  
    string a,b;  
    for(i=0;i<cnt;i++)  
     for(j=0;j<s[i].size()-1;j++)  
     {  
        a=s[i].substr(0,j+1);  
        if(!hash[a])
			continue;  
        b=s[i].substr(j+1);  
        if(!hash[b])
			continue;  
        cout<<s[i]<<endl;  
        break;  
     }  
     return 0;  
}  
