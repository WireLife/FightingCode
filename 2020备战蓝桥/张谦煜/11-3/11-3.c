#include <stdio.h>

int main()
{
    char* result =(char*)malloc(1000000*sizeof(char));
    char ch = getchar();
    int i = 0;
    while (ch!='\n')
    {
        result[i++]=ch;
        ch=getchar();
    }
    result[i]='\0';
    printf("%s",result);
    
}