/*11.5.1统计字符*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i, capital_letter = 0, small_letter = 0, number_character = 0, space_character = 0, other_character = 0;
	string str;
	//gets(str);             //用不了
	//cin.getline(str,10);    //用不了
	getline(cin, str);      
	for (i = 0; i < str.length(); i++)   //这里想用switch语句
	{
		if (str[i] >= 'A'&&str[i] <= 'Z') capital_letter++;
		else if (str[i] >= 'a'&&str[i] <= 'z') small_letter++;
		else if (str[i] >= '0'&&str[i] <= '9') number_character++;
		else if (str[i] == ' ')space_character++;
		else other_character++;
	}

	cout << "the number of capital letter is: " << capital_letter << endl;
	cout << "the number of small letter is: " << small_letter << endl;
	cout << "the number of number character is: " << number_character << endl;
	cout << "the number of sapce character is: " << space_character << endl;
	cout << "the number of other character is: " << other_character << endl;

	system("pause");
	return 0;
}