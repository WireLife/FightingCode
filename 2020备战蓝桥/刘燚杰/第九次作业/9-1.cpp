
#include<iostream>
#include<string>
#include<sstream>//isstringstream
#include<stdio.h>
using namespace std;

int main()
{
    string s = "* 11 12";
    int former = 0,midder=0,latter = 0;
    istringstream iss(s);
    string subs;
    iss >> subs;
    if(subs == "*" || subs == "/")
  {
    if(subs == "*")
        {
            iss >> subs;
            if(subs != "+" && subs != "-")
            {
                former = atoi(subs.c_str());
                iss >> subs;
                latter = atoi(subs.c_str());
             //   return (former*latter);
                    cout<<(former*latter)<<endl;
            }
            else if(subs == "+")
            {
                iss>>subs;
                former = atoi(subs.c_str());
                iss >> subs;
                midder = atoi(subs.c_str());
                iss >> subs;
                latter = atoi(subs.c_str());
            //    return ((former+midder)*latter);
                cout<<((former+midder)*latter)<<endl;
            }
            else if(subs == "-")
            {
                iss>>subs;
                former = atoi(subs.c_str());
                iss >> subs;
                midder = atoi(subs.c_str());
                iss >> subs;
                latter = atoi(subs.c_str());
            //    return ((former-midder)*latter);
                cout<<((former-midder)*latter)<<endl;    
            }
        }
        if(subs == "/")
        {
            iss >> subs;
            if(subs != "+" && subs != "-")
            {
                int former = atoi(subs.c_str());
                iss >> subs;
                int latter = atoi(subs.c_str());
            //    return (former/latter);
                cout<<(former/latter)<<endl;
            }
            else if(subs == "+")
            {
                iss>>subs;
                former = atoi(subs.c_str());
                iss >> subs;
                midder = atoi(subs.c_str());
                iss >> subs;
                latter = atoi(subs.c_str());
            //    return ((former+midder)/latter);
                cout<<((former+midder)/latter)<<endl;
            }
            else if(subs == "-")
            {
                iss>>subs;
                former = atoi(subs.c_str());
                iss >> subs;
                midder = atoi(subs.c_str());
                iss >> subs;
                latter = atoi(subs.c_str());
            //    return ((former-midder)/latter);  
                cout<<((former-midder)/latter)<<endl;  
            }
        }
    }
}
