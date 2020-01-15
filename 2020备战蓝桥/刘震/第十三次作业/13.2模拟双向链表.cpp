/*基于59页双链表实验程序完成63页试验程序功能：建立双向链表，在头部inserttop、尾部insertend、某元素前insertbefore、
某元素后insertback插入数据。删除一个节点remove。查找某元素find。头起遍历链表ttraversal。尾起遍历链表etraversal。
修改某元素的值modify。显示链表长度zize。链表重组reorg。
*/

//单向链表的实现
/*#include<iostream>
#include<malloc.h>
using namespace std;
struct Link {
	int data;
	Link *next;
};

int main()
{

	//现在我要在链表中插入一个数据
	//首先要在内存中开辟一段空间，用malloc函数能具体直到开辟大小
	Link *p = (struct Link*)malloc(sizeof(struct Link));
	Link *head = p;
	p->data = 10;
	Link *next = (struct Link*)malloc(sizeof(struct Link));
	p->next = next;
	p = next;
	p->data = 12;
	cout << head->data << " " << (head->next)->data << endl;
	
	
	
	
	cout << p->data << endl;

	


	free(p);
	system("pause");
	return 0;
}
*/

//建立双向链表
#include<iostream>
#include<cstdlib>
using namespace std;
struct Link{
	Link *front;  //指向上一个节点的地址
	int data = 0;    //数据段，初始化为0
	Link *next;  //指向下一个节点的地址
};
void inserttop(struct Link *l);//在头部插入一个元素
void insertend(struct Link *l);//在尾部插入一个元素
void insertbefore(struct Link *l);//在某元素前插入一个元素
void insertback(struct Link *l);//在某元素后插入一个元素
void remove(int val);//删除某一个节点,这里是按值删除
Link find(int val);//查找元素
void ttraversal();//头起遍历链表
void etraversal();//尾起遍历链表
void modify(struct Link *l,int val);//修改某一的元素的值 //参数设置的是指向节点的地址，后面是要改变的值
unsigned int size();//返回节点的长度

int k = 0;
Link *fp[100];  //保存动态开辟的内存的指针
Link *Head;  //建立首节点
Link *End;   //建立尾节点
int cnt = 2; //初始节点为2

int main()
{
	//建立双向链表的起点和终点
	//为首节点开辟一段内存空间
	Head = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = Head;
	//首节点的上一个元素可定不存在
	Head->front = NULL;
	//为尾节点开辟一段内存空间
	End = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = End;
	//尾节点的最后一个元素坑定也不存在的
	End->next = NULL;
	//然后把两个节点链接起来
	Head->next = End;    //首节点的下一个节点是尾节点
	End->front = Head;   //尾节点的上一个节点是首节点
	Head->data = 3;
	End->data = 1;
	
	//在头部插入一个元素
	Link *p = (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = p;
	p->data = 100;
	inserttop(p);
	

	//测试在某一个节点前插入数据
	Link *p1= (struct Link*)malloc(sizeof(struct Link));
	fp[k++] = p1;
	p1->data = 3;
	insertbefore(p1);

	ttraversal();
	cout << endl;
	//etraversal();
	//cout << endl;
	for (int i = 0; i < k; i++)
		free(fp[i]);
	system("pause");
	return 0;

}
//在头部插入一个元素
void inserttop(struct Link *l)
{
	Head->front = l;  //把原来头部节点的指向前一个元素的指针指向要插入的节点的地址
	l->next = Head;   //把新头部的指向下一个节点的指针指向原头部的地址
	l->front = NULL;  //把新的节点的指向上衣个元素节点的指针置为NULL
	Head = l;         //把原来作为头部的标识符换成新头部
	cnt++;
}

//在尾部插入一个元素
void insertend(struct Link *l) {
	End->next = l;
	l->front = End;
	l->next = NULL;
	End = l;
	cnt++;
}

//在某元素前插入一个元素
void insertbefore(struct Link *l) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == l->data) {
			if (p == Head)    //如果要插入元素数据端正好等于链表头部的数据段，就在链表头部插入
				inserttop(l);
			else {
				//先把下一个顺序调好
				(p->front)->next = l;  //把元素的前面一个节点的指向下一个节点的指针改成指向要插入的节点的地址   
				l->next = p;			//把插入的节点的指向下一个节点的指针指向要插入的节点的下一个位置
				//在把上一个节点调好
				l->front = p->front;
				p->front = l;
				return;
			}
		}
		p = p->next;
	}
	//防止到最后都没有比较出元素
	insertback(l);  //把元素插入到最后
	cnt++;
}

//在某元素后插入一个元素
void insertback(struct Link *l) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == l->data) {
			if (p == End)    //如果要插入元素数据端正好等于链表尾部的数据段，就在链表尾部插入
				insertback(l);
			else {
				//按顺序把指针指向依次调整
				l->next = p->next;   
				p->next = l;			
				//按逆序把指针指向依次调整
				l->front = p;
				(l->next)->front = l;
				return;
			}
		}
		p = p->next;
	}
	//防止到最后都没有比较出元素
	inserttop(l);  //把元素插入到最后
	cnt++;
}

//查找元素
Link find(int val) {
	Link *p = Head;
	for (int i = 0; i < cnt; i++) {
		if (p->data == val)
			return *p;
	}
}

//头起遍历链表
void ttraversal() {
	Link *p = Head;
	for (int i = 0; i <= cnt; i++) {
		cout << p->data << " ";
		p = p->next;
	}
}

//尾起遍历链表
void etraversal() {
	Link *p = End;
	for (int i = 0; i < cnt; i++) {
		cout << p->data << " ";
		p = p->front;
	}
}

//修改某一的元素的值
void modify(struct Link *l, int val) {
	l->data = val;
}

//返回节点的数量
unsigned int size() {
	return cnt;
}

//删除某一个节点,这里是按值删除
void remove(int val) {
	Link *pp = Head;
	for (int i = 0; i < cnt; i++) {
		if (pp->data == val) {
			if (pp == Head) {
				(pp->next)->front = NULL; //如果要删除的是首元素，只需要把首元素的下一个节点的指向上一个节点的指针置为NULL
			}
			else if (pp == End) {
				(pp->front)->next = NULL; //如果要删除的是尾元素，只需要把尾元素的上一个节点的指向下一个节点的指针置为NULL
			}
			else {
				(pp->front)->next = pp->next;
				(pp->next)->front = pp->front;
			}
		}	
	}
	cnt--;
}