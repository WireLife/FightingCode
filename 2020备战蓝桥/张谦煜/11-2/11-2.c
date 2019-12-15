#include<stdio.h>

int main()
{
    char* str1 = (char*)malloc(10000*sizeof(char));
    char* str2 = (char*)malloc(10000*sizeof(char));
    scanf("%s%s",str1,str2);
    char* str = (char*)malloc(20000*sizeof(char));
    int i;
    for(i = 0;i<10000&&str1[i]!='\0';i++)
    {
        str[i]=str1[i];
    }
    int j =i;
    for(i = 0;i<10000&&str2[i]!='\0';i++)
    {
        str[j++]=str1[i];
    }
    str[j]='\0';
    printf("%s",str);
    return 0;
}