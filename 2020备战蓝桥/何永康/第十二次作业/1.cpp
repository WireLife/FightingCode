//1、习题---5-1代码对齐（UVa1593）
//输入若干行代码，要求各列单词的左边界对齐且尽量靠左。
//单词之间至少要空一格。每个单词不超过80个字符，每行不超过180个字符
//一共最多1000行。注意输出时每行的最后一列后面没有空格符。

/*#include <iostream>          //VC++6.0 可但是用VS2019报错
#include <string>
using namespace std;
int main()
{
    char str[10000];
	cin.getline(str,10000);  //用cin>>str 到空格会截断，，改用cin.getline(str,10000)即可。
    const char *split = " ";
    char *p2 = strtok(str,split);
    while( p2 != NULL ) 
	{        
		cout<<p2<<endl;        
		p2 = strtok(NULL,split); 
	}
}
*/

/*
#include <iostream>          //VS2019 可   因为strtok函数声明与using声明引入的strtok冲突
#include <string>

int main()
{
    char s[10000];
    char* strtok(char s[], const char* split);
    std::cin.getline(s, 10000);  //用cin>>str 到空格会截断，，改用cin.getline(str,200)即可。
    const char* split = " ";
    char* p2 = strtok(s, split);
    while (p2 != NULL)
    {
        std::cout << p2 << std::endl;
        p2 = strtok(NULL, split);
    }
}*/
