//模拟双端队列

//用双端队列实现
/*
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	queue<int> q1;//建立队列
	int order;    int x;
	while (1) {
		cout << " 请选择命令:1-入队操作，2-出队操作,3-查询队列长度,4-结束 :";
		cin >> order;
		switch (order) {
		case 1: cout << " 请输入需要入队的数值:" << endl;
			cin >> x;    q1.push(x);
			break;
		case 2:
			if (q1.empty()) {
				cout << " 队列为空" << endl;
				break;
			}
			cout << "出队的数据为:" << q1.front() << endl;
			q1.pop();     break;
		case 3:
			cout << q1.size() << endl;
		break;  default: goto q;
		}
	}
q: {
	system("pause");
	return 0;
	}
}
*/

//用结构体+动态数组简单实现双端链表
#include<iostream>
using namespace std;
struct queue{                   //双端队列可以在两端插入删除数据，和返回两端的数据
public:
	int *data;		//为了更好了利用空间
	int top0, end0;
	int Capacity = 0;
	bool t = true, e = true;			//判断两个端的指针是否按着顺序排列
public:	
	queue(int capacity = 20000) { top0 = end0 = capacity / 2 - 1; Capacity = capacity; data = (int*)malloc(sizeof(int)*capacity); }   //初始化，都指向中间位置
	~queue() { free(data); }
	void push_front(int top);   //在queue前面添加一个元素
	void push_back(int back);	//在queue最后添加一个元素
	void pop_front();			//在queue前面删除一个元素
	void pop_back();			//在queue后面删除一个元素
	int front();				//返回queue最前面的元素
	int back();					//返回queue最后面的元素
	bool isfull();              //判断双端队列是否满
	bool empty();				//判断queue是否为空       
	int size();					//返回queue元素的个数
};
void queue::push_front(int top) {				//在队首添加一个元素
	if (!isfull()){								//要插入数据前必须先看找到插入的地方可否行
		if (top0 == 0 && end0 != Capacity - 1)
		{
			top0 = Capacity - 1;//如果队首指针指向了数组的最前并且数组后半部分还有大片空间时
			t = false;			//说明队首指针是由于数组前半部分数据放满了移到指向后面去了
		}
			
		else
			top0--;							//不满足以上情况的，证明队尾还有空间可以存放数据
		data[top0] = top;
		if (end0 == Capacity / 2 -1)    //起初end0指向Capacity/2,然后再队首添加了一个元素所以要把end0指向这个元素的位置
			end0 = top0;
	}
	else {
		cout << "queue is fullful" << endl;
		return;
	}
	
}
void queue::push_back(int end) {
	if (!isfull()) {
		if (end0 == Capacity - 1 && top0 != 0)    //要插入数据前必须先看找到插入的地方可否行
		{
			end0 = 0;
			e = false;		//说明队尾指针是由于数组后半部分数据放满了移到指向前面去了
		}
		else
			end0++;
		data[end0] = end;
		if (top0 == Capacity / 2 -1)	//起初top0指向Capacity/2,然后再队尾添加了一个元素所以要把top0指向这个元素的位置		
			top0 = end0;
	}
	else {
		cout << "queue is fullful" << endl;
		return;
	}
} 
void queue::pop_front() {					//弹出队列最前的一个元素
	if (!empty()) {
		if (top0 == Capacity - 1){			//如果指向队首的指针指在了数组的最后一个位置
			top0 = 0;
			t = true;
		}	
		else
			top0++;	      //队首元素被弹出,指针往后移一位
	}
	else {
		cout << "没有元素了" << endl;
		return;
	}
}
void queue::pop_back() {   //弹出队列最后一个元素
	if (!empty()) {
		if (end0 == 0){
			end0 = Capacity - 1;
			e = true;
		}			
		else
			end0--;
	}
	else {
		cout << "没有元素了" << endl;
		return;
	}
}

int queue::front() {  //返回队首元素的值
	int temp = data[top0];
	return temp;
}
int queue::back() {    //返回队尾元素的值
	int temp = data[end0];
	return temp;
}
bool queue::isfull() {    //两种情况会满:1.e和t有一个为假并且end0+1==top0 2.top0=0,end0=Capacity-1
	return (end0 + 1 == top0) && ((!e) || (!t)) || top0 == 0 && end0 == Capacity - 1;
}
bool queue::empty() {   //两种情况会空：1.e和t都为真并且end0+1==top0,2.初始时,
	return e && t && (end0 + 1 == top0) || (top0 == Capacity / 2 -1 && end0 == Capacity / 2 -1);
}
int queue::size() {
	if (empty())
		return 0;
	return e && t ? (end0 - top0 + 1) : ((Capacity - ((top0 - end0) > 0 ? (top0 - end0) : (end0 - top0) - 1)));
}

int main() {
	queue q1(3);//建立队列
	int order;    int x;
	while (1) {
		cout << " 请选择命令:1-入队操作，2-出队操作,3-查询队列长度,4-结束 :";
		cin >> order;
switch (order) {
		case 1: cout << " 请输入需要入队的数值:" << endl;
			cin >> x;    q1.push_back(x);
			break;
		case 2:
			if (q1.empty()) {
				cout << " 队列为空" << endl;
				break;
			}
			cout << "出队的数据为:" << q1.front() << endl;
			q1.pop_front();     break;
		case 3:
			cout << q1.size() << endl;
		break;  default: goto q;
		}
	}
q:	system("pause");
	return 0;
}

