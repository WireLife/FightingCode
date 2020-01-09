/*12.8模拟一个图书管理系统，先给出书架上的书书本名和作者名，标题各部相同，以end结束，然后有3种指令：BORROW指令表
示借书，RETURN指令表示还书，SHELVE指令表示把所有已归还但还未上架的图书排序后依次插入书架并输出图书标题和插入
位置（可能是第一本书或者某本书的后面）。图书排序的方法是先按作者从小到大排，再按标题从小到大排。在处理第一条
指令之前，你应当先将所有图书按照这种方式排序。
*/

/*//假设现在有这么几本书
我是张三 张三
我是李四 李四
我是王五 王五
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

	//查找作者
	bool operator == (const string &temp) {
		return (this->anthor == temp || this->bookName == temp);
	}

	/*//查找书名
	bool operator == (const string &temp) {
		return (this->bookName == temp);
	}*/

		
};
vector<LIB>lib;  //图书馆
vector<LIB>libb; //暂缓区

int libLen = 0;

//打印
void Print();
//开始前输入几本书和其作者
void PreInput();
//排序
void Sort();
//输出函数
void Output(vector<LIB>lib);
//借书
void Borrow();
//还书
void Return();
//暂缓
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
		cout << "**********************************请输入指令*************************************" << endl;
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
	cout << "*                                  图书馆管理系统                               *" << endl;
	cout << "*********************************************************************************" << endl;
	cout << "指令：BORROW RETURN SHELVE LOOK SHELVELOOK EXIT" << endl;
}

void PreInput()
{
	LIB book;
	string temp;
	for (int i = 0;; i++)
	{
		cin >> temp;
		if (temp == "END")  //这里只考虑了输入书名时候是否会给END指令
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
void Sort()   //排序，按照从小到大的顺序排序
{
	sort(lib.begin(),lib.end(),cmp);
}

void Output(vector<LIB>lib)
{
	cout << setw(20) << "****作者****" << setw(50) << "****书名****" << endl;
	for (vector<LIB>::iterator it = lib.begin(); it != lib.end(); it++)
		cout << setw(20) << it->anthor << setw(50) << it->bookName << endl;
}

void Borrow()
{
	int t;
	cout << "请输入书名或者作者名：";
	string temp;
	vector<LIB>::iterator it;
	cin >> temp;
	it = find(lib.begin(), lib.end(), temp);
	if (it == lib.end()) cout << "**********************************抱歉没有！*************************************" << endl;
	else
	{
		cout << endl << setw(20) << it->anthor << setw(50) << it->bookName << endl << endl;

		cout << "****************************是否借阅?  3:是  4:否********************************" ;
		cin >> t;
		if (t == 3)
			lib.erase(it);
		if (t == 4)
			return;
	}
}

void Return()
{
	cout << "***************************请依次输入书名和作者名:*******************************" << endl;
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