#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;
string s,buf;
int main()
{
	while(cin>>s)
	{
		
        int i,j;
		 j=0;
		 for(i=0;i<s.length();i++)
		 {
            if(s[i]=='-')
		    	  j++;
		 }
	     if(j==1)
		 {
		    stringstream ss(s);
			while(ss >> buf) 
	         dict.insert(buf);
		 }
		 
		 if(s<"A")break;
	}
    for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    cout << *it << "\n";
	return 0;
}