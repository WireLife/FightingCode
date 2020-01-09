/*12.8ģ��һ��ͼ�����ϵͳ���ȸ�������ϵ����鱾���������������������ͬ����end������Ȼ����3��ָ�BORROWָ���
ʾ���飬RETURNָ���ʾ���飬SHELVEָ���ʾ�������ѹ黹����δ�ϼܵ�ͼ����������β�����ܲ����ͼ�����Ͳ���
λ�ã������ǵ�һ�������ĳ����ĺ��棩��ͼ������ķ������Ȱ����ߴ�С�����ţ��ٰ������С�����š��ڴ����һ��
ָ��֮ǰ����Ӧ���Ƚ�����ͼ�鰴�����ַ�ʽ����
*/

/*//������������ô������
�������� ����
�������� ����
�������� ����
*/




#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct LIB
{
	string bookName;
	string anthor;

	//��������
	bool operator == (const string &temp) {
		return (this->anthor == temp || this->bookName == temp);
	}

	/*//��������
	bool operator == (const string &temp) {
		return (this->bookName == temp);
	}*/

		
};
vector<LIB>lib;  //ͼ���
vector<LIB>libb; //�ݻ���

int libLen = 0;

//��ӡ
void Print();
//��ʼǰ���뼸�����������
void PreInput();
//����
void Sort();
//�������
void Output(vector<LIB>lib);
//����
void Borrow();
//����
void Return();
//�ݻ�
void Shelve();


int main()
{
	Print();
	PreInput();
	Sort();
	//Output();
	string contral;
	for (int i = 0;; i++)
	{
		cout << "**********************************������ָ��*************************************" << endl;
		cin >> contral;
		if (contral == "BORROW")
			Borrow();
		if (contral == "RETURN")
			Return();
		if (contral == "LOOK")
			Output(lib);
		if (contral == "SHELVELOOK")
			Output(libb);
		if (contral == "SHELVE")
			Shelve();
		if (contral == "EXIT")
			break;
			
	}

	system("pause");
	return 0;

}

void Print()
{
	cout << "*********************************************************************************" << endl;
	cout << "*                                  ͼ��ݹ���ϵͳ                               *" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "ָ�BORROW RETURN SHELVE LOOK SHELVELOOK EXIT" << endl;
}

void PreInput()
{
	LIB book;
	string temp;
	for (int i = 0;; i++)
	{
		cin >> temp;
		if (temp == "END")  //����ֻ��������������ʱ���Ƿ���ENDָ��
			break;
		book.bookName = temp;
		cin >> temp;
		book.anthor = temp;
		lib.push_back(book);
		libLen++;
	}
}

bool cmp(LIB a, LIB b)
{
	if (a.anthor == b.anthor)
		return a.bookName < b.bookName;
	else
		return a.anthor < b.anthor;
}
void Sort()   //���򣬰��մ�С�����˳������
{
	sort(lib.begin(),lib.end(),cmp);
}

void Output(vector<LIB>lib)
{
	cout << setw(20) << "****����****" << setw(50) << "****����****" << endl;
	for (vector<LIB>::iterator it = lib.begin(); it != lib.end(); it++)
		cout << setw(20) << it->anthor << setw(50) << it->bookName << endl;
}

void Borrow()
{
	int t;
	cout << "����������������������";
	string temp;
	vector<LIB>::iterator it;
	cin >> temp;
	it = find(lib.begin(), lib.end(), temp);
	if (it == lib.end()) cout << "**********************************��Ǹû�У�*************************************" << endl;
	else
	{
		cout << endl << setw(20) << it->anthor << setw(50) << it->bookName << endl << endl;

		cout << "****************************�Ƿ����?  3:��  4:��********************************" ;
		cin >> t;
		if (t == 3)
			lib.erase(it);
		if (t == 4)
			return;
	}
}

void Return()
{
	cout << "***************************����������������������:*******************************" << endl;
	LIB book;
	cin >> book.bookName >> book.anthor;
	libb.push_back(book);
	Sort();
}

void Shelve()
{
	for (vector<LIB>::iterator it = libb.begin(); it != libb.end(); it++)
		lib.push_back(*it);
	Sort();
	libb.clear();
}