#include <iostream>
using namespace std;
int Y(int year)
{
	if(year%4==0&&(year%100!=0||year%400==0))
	return 365;
	else
	return 366;
} 
int juge(int month,int all_day)
{
	if(all_day==365)
	{
	  switch(month)
	  {
	    case 2:all_day=31;break;
	    case 3:all_day=59;break;
		case 4:all_day=90;break;
		case 5:all_day=120;break;
		case 6:all_day=151;break;
		case 7:all_day=181;break;
		case 8:all_day=212;break;
		case 9:all_day=243;break;
		case 10:all_day=273;break;
		case 11:all_day=304;break;
		case 12:all_day=334;break;
	  }  
    }
    else
    {
      switch(month)
	  {
	    case 2:all_day=31;break;
	    case 3:all_day=60;break;
		case 4:all_day=91;break;
		case 5:all_day=121;break;
		case 6:all_day=152;break;
		case 7:all_day=182;break;
		case 8:all_day=213;break;
		case 9:all_day=244;break;
		case 10:all_day=274;break;
		case 11:all_day=305;break;
		case 12:all_day=335;break;
	  } 
	}
}
int main() {
	int year,month,day,all_day,n,sum=0;
	cin>>year>>month>>day;
	n=year-1990;
	if(n==0)
	{
		if(month==1)
		all_day=day-1;
		else
		{
			juge(month,365);
			all_day=all_day+day;
		 } 
	}
	else if(n==1)
	{
		juge(month,366);
		all_day=all_day+day+364;
	}
	else if(n!=1&&n!=0)
	{
		for(int i=1;i<n;i++)
		{
			sum=Y(1990+i)+sum;
		}
		Y(year);
		all_day=all_day+sum+364+juge(month,all_day);
	}
	if(all_day%3==0)
	cout<<"´òÓã";
	else if(all_day%2==0)
	cout<<"É¹Íø";
	else
	cout<<"ÐÝÏ¢"; 
	return 0;
}
