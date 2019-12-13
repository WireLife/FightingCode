#include<iostream>
using namespace std;

const int array[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Date
{
    int year;
    int month;
    int day;
};
struct Date D1;
struct Date D2;
bool IsLeapYear(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
    return false;
}

int DateToNum(Date D)
{
    int n = 0;
    while(D.year > 0)
    {
        int m = IsLeapYear(D.year)? 366 : 365;
        n += m;
        D.year--;
    }
    while(D.month > 0)
    {
        n += array[D.month-1];
        D.month--;
    }
    if(IsLeapYear(D.year) == 1)
        n++;
    n += D.day;
    return n;
}
void T5()
{
    int a = DateToNum(D1);
    int b = DateToNum(D2);
    int result = a-b+1;
    if(result <= 3 && result >= 0)
        cout<<"fishing"<<endl;
    if(result <=5 && result > 3)
        cout<<"sunning"<<endl;
    if(result > 5)
    {
        if(result%5 <=3 && result%5 >= 0)
            cout<<"fishing"<<endl;
        if(result%5 <=5 && result%5 > 3)
            cout<<"sunning"<<endl;
    }
}

int main()
{
    int y,m,d = 0;
    cout<<"please input the year month and day:"<<endl;
    cin>>D2.year>>D2.month>>D2.day;
    cout<<"please input someday :"<<endl;
    cin>>D1.year>>D1.month>>D1.day;
    T5();
    return 0;
}
