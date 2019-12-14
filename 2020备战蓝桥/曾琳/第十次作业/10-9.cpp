/*#include<iostream>
using namespace std;
int a[6] = {1,2,3,4,5,6};
int counter = 0;
void Method()
{
	int a1, a2, a3, a4, a5, a6;
	for (int c= 0; c< 6; c++)
	{
		a1 = a[c];
		for (int d = 0; d<6; d++)
		{
			if (d != c)
				a2 = a[d];
			else
				continue;
			if (a2 > a1)
			{

				for (int e = 0; e < 6; e++)
				{
					if (e != d && e != c)
					a3 = a[e];
					else continue;
					if (a3 > a2)
					{
						for (int f = 0; f < 6; f++)
						{
							if (f != e && f != d && f != c)
								a4 = a[f];
							else
								continue;
							if (a4 > a1)
							{
								for (int g = 0; g < 6; g++)
								{
									if (g != c && g != d && c != e && c != f)
										a5 = a[g];
									else
										continue;
									if (a5 > a4&&a5 > a2)
									{
										for (int h = 0; h < 6; h++)
										{
											if (h != c && h != d && h != e && h != f && h != g)
												a6 = a[h];
											else
												continue;
											if (a6 > a3&&a6 > a5)
											{
												counter++;
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
		

	}
	cout << "共有" << counter << "种方案！" << endl;
}
int main()
{
	cout << "________________" << endl;
	cout << "| a1 | a2 | a3 | " << endl;
	cout << "————————" << endl;
	cout << "| a4 | a5 | a6 |" << endl;
	cout << "————————" << endl;
	Method();
	system("pause");
	return 0;


}
*/
