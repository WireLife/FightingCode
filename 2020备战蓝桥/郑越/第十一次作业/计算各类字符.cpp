#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[100];
    int count_LETTERS=0,count_letters=0,count_numbers=0,count_blank=0,count_else=0;
    gets(str);
    for(int i=0;i<strlen(str);i++)
        if(str[i]>='0'&&str[i]<='9')
            count_numbers++;
        else
            if(str[i]>='A'&&str[i]<='Z')
                count_LETTERS++;
        else
            if(str[i]>='a'&&str[i]<='z')
               count_letters++;
        else
            if(str[i]==' ')
               count_blank++;
        else
            count_else++;
    printf("大写字母有%d个\n小写字母有%d个\n空字符有%d个\n数字有%d个\n其他字符有%d个\n",count_LETTERS,count_letters,count_blank,count_numbers,count_else);
            
    
    
    return 0;
}
