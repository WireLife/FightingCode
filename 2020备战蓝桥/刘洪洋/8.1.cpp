#include<stdio.h>
#include<string.h> 
void revert()
{
char ch = getchar();
if (ch == '!')
{
//putchar(ch);
return;
}
else
{
revert();
putchar(ch);
}
}
int main()
{
revert();
    return 0;
}
