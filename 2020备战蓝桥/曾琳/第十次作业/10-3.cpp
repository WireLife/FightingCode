/*#include<iostream>
using namespace std;
int n = 0;
char a2[] = { 'A','B','C' };
char a3[] = { 'D','E','F' };
char a4[] = { 'G','H','I' };
char a5[] = { 'J','K','L' };
char a6[] = { 'M','O','N' };
char a7[] = { 'P','Q','R','S' };
char a8[] = { 'T','U','V' };
char a9[] = { 'W','X','Y','Z' };
char read[12] = {'0'};
char store[12] = { '0' };
void Sort(int number)
{
	char* r = read;
	while ((*r) != '\0')
	{
		int i = 0;
		for (int b2 = 0; b2 < 3; b2++)
		{
	
			for (int b3 = 0; b3 < 3; b3++)
			{
			
				for (int b4 = 0; b4 < 3; b4++)
				{
				
					for (int b5 = 0; b5 < 3; b5++)
					{
					
						for (int b6 = 0; b6 < 3; b6++)
						{
							
							for (int b7 = 0; b7 < 4; b7++)
							{
								
								for (int b8 = 0; b8 < 3; b8++)
								{
									

									for (int b9 = 0; b9 < 4; b9++)
									{
										cout << a2[b2];
										cout << a3[b3];
										cout << a4[b4;
										cout << a5[b5];
										cout << a6[b6];
										cout << a7[b7];
										cout << a8[b8];
										cout << a9[b9];
										cout << endl;
									}
								}

							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	cout << "input the size:\n";
	int number;
	cin >> number;
	cout << "input the teldephone number when '#' to end" << endl;
	char tem;
	for (int i = 0; i < number; i++)
	{
		cin >> tem;

		read[i] = tem;
	}
	Sort(number);
	cout << "共有" << n << "种方案！" << endl;
	system("pause");
	return 0;
}
*/
