
//建立双向链表
#include<iostream>
#include<cstdlib>
using namespace std;
struct Link {
	Link *front;  //指向上一个节点的地址
	int data = 0;    //数据段，初始化为0
	Link *next;  //指向下一个节点的地址
};
void linkTE(); //当只有头与尾节时
void inserttop(struct Link *l);//在头部插入一个元素
void insertend(struct Link *l);//在尾部插入一个元素
void insertbefore(struct Link *l);//在某元素前插入一个元素
void insertback(struct Link *l);//在某元素后插入一个元素
void remove(int val);//删除某一个节点,这里是按值删除
Link *find(int val);//查找元素
void ttraversal();//头起遍历链表
void etraversal();//尾起遍历链表
void modify(struct Link *l, int val);//修改某一的元素的值 //参数设置的是指向节点的地址，后面是要改变的值
int size();//返回节点的长度
void freep();  //把指针指向的空间都释放了

int k = 0;
Link *fp[100];  //保存动态开辟的内存的指针
Link *Head;  //建立首节点
Link *End;   //建立尾节点
int cnt = 0; //初始节点为2，不加的话是0
Link *temp;

int main()
{
	//建立双向链表的起点和终点
	//为首节点开辟一段内存空间
	Head = (struct Link*)malloc(sizeof(struct Link));
	//为尾节点开辟一段内存空间
	End = (struct Link*)malloc(sizeof(struct Link));

	/*************************************************************************************************/
	int box, n;
	int op, x, y;
	bool bol = true;
	while (scanf("%d%d", &box, &n) == 2) {
		//刚开始初始化，在前面插入box个数
		for (int i = box; i > 0; i--) {  
			Link*p = (struct Link*)malloc(sizeof(struct Link));
			fp[k++] = p;
			p->data = i;
			inserttop(p);			
		}
		ttraversal();
		freep();     //下一局，所有节点都释放，除了最原始的头尾两个节点
		linkTE();    //让最原始的两个头尾节点连接在一起
		k = 0;
		cnt = 0;
		cout << endl;

		//输入命令了
		for (int i = 0; i < n; i++) {
			cin >> op >> x >> y;
			if (op == 4)
				bol = false;
			else if (op == 1) {	//如果bol=true那就把x移到y的左边，否者就把x移到y的右边
				//先找到两个数的位置
				Link *xp = find(x);
				Link *yp = find(y);
				if (bol) {//要把x移到y的左边
					if (x + 1 != y) {     //把xp插在yp的前面，然后把原来的xp删除

					}
				}

			}
		}






	}
	//测试一下数据是否正确
	




	




	cout << "收到客户发" << endl;




	/*******************************************************************************************************/
	system("pause");
	return 0;

}
void linkTE() {
	Head->front = NULL;	//首节点的上一个元素可定不存在
	End->next = NULL;//尾节点的最后一个元素坑定也不存在的
	//然后把两个节点链接起来
	Head->next = End;    //首节点的下一个节点是尾节点
	End->front = Head;   //尾节点的上一个节点是首节点
	Head->data = -1;
	End->data = -1;
}


//在头部插入一个元素
void inserttop(struct Link *l){
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
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == l->data) {
			if (temp == Head)    //如果要插入元素数据端正好等于链表头部的数据段，就在链表头部插入
				inserttop(l);
			else {
				//先把下一个顺序调好
				(temp->front)->next = l;  //把元素的前面一个节点的指向下一个节点的指针改成指向要插入的节点的地址   
				l->next = temp;			//把插入的节点的指向下一个节点的指针指向要插入的节点的下一个位置
				//在把上一个节点调好
				l->front = temp->front;
				temp->front = l;
				return;
			}
		}
		temp = temp->next;
	}
	//防止到最后都没有比较出元素
	insertback(l);  //把元素插入到最后
	cnt++;
}

//在某元素后插入一个元素
void insertback(struct Link *l) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == l->data) {
			if (temp == End)    //如果要插入元素数据端正好等于链表尾部的数据段，就在链表尾部插入
				insertback(l);
			else {
				//按顺序把指针指向依次调整
				l->next = temp->next;
				temp->next = l;
				//按逆序把指针指向依次调整
				l->front = temp;
				(l->next)->front = l;
				return;
			}
		}
		temp = temp->next;
	}
	//防止到最后都没有比较出元素
	inserttop(l);  //把元素插入到最后
	cnt++;
}

//查找元素
Link *find(int val) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == val)
			return temp;
		temp = temp->next;
	}
}

//头起遍历链表
void ttraversal() {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

//尾起遍历链表
void etraversal() {
	temp = End;
	for (int i = 0; i < cnt; i++) {
		cout << temp->data << " ";
		temp = temp->front;
	}
}

//修改某一的元素的值
void modify(struct Link *l, int val) {
	l->data = val;
}

//返回节点的数量
int size() {
	return cnt;
}

//删除某一个节点,这里是按值删除
void remove(int val) {
	temp = Head;
	for (int i = 0; i < cnt; i++) {
		if (temp->data == val) {
			if (temp == Head) {
				(temp->next)->front = NULL; //如果要删除的是首元素，只需要把首元素的下一个节点的指向上一个节点的指针置为NULL
			}
			else if (temp == End) {
				(temp->front)->next = NULL; //如果要删除的是尾元素，只需要把尾元素的上一个节点的指向下一个节点的指针置为NULL
			}
			else {
				(temp->front)->next = temp->next;
				(temp->next)->front = temp->front;
			}
		}
	}
	cnt--;
}
void freep() {//把指针指向的空间都释放了
	for (int i = 0; i < k; i++)
		free(fp[i]);
}
	
