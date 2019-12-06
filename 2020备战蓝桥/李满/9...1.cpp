#include<stdio.h>

char symbol[101];
double operation( )
{
	if(symbol[0]=='+')
	return operation()+operation();
	else if(symbol[0]=='-')
	return operation()-operation();
	else if(symbol[0]=='*')
	return operation()*operation();
	else if(symbol[0]=='/')
	return operation()/operation();
	else return operation();
 } 

 int main()
 {
 	printf("%s",operation());
 	return 0;
 }
