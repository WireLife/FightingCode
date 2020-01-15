#include <iostream>
#include <assert.h>
using namespace std;
const int maxSize = 50;
template<class T>
class Queue{
public:
	Queue(){};
	~Queue(){};
	virtual void EnQueue(const T&x) = 0;
	virtual bool DeQueue(T& x) = 0;
	virtual bool getFront(T& x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool Isfull()const = 0;
	virtual int getSize()const = 0;
};
template<class T>
class SeqQueue:public Queue<T>{
public:
	SeqQueue(int sz = 10);
	~SeqQueue(){delete[] elements};
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	void makeEmpty(){front = rear = 0;}
	bool IsEmpty()const{
		return (front == rear) ? true:false;
	}
	bool IsFull()const{
		return ((rear+1)%maxSize == front) ? true:false;
	}
	int getSize()const{
		return (rear-front+maxSize)%maxSize;
	}
	friend ostream& operator<<(ostream& os, SeqQueue<T>& Q);
protected:
	int rear, front;
	T* elements;
	int maxSize;
};

//构造函数：建立一个最大具有maxSize个元素的空队列
template<class T>
SeqQueue<T>::SeqQueue(int sz):front(0), rear(0),maxSize(sz){
	elements = new T[maxSize];
	assert(elements != NULL);
};
//SeqList<T>::SeqList(int sz)

//入队函数：若队列不满，则将元素x插入到该队列的对尾，否则出错处理
template <class T>
bool SeqQueue<T>::EnQueue(const T& x){
	if(IsFull() == true)
		return false;
	elements[rear] = x;
	rear = (rear+1)%maxSize;
	return true;
};

//出队函数：若队列不空则函数退掉一个队头并返回true，否则函数返回false
template<class T>
bool SeqQueue<T>::DeQueue(T& x){
	if(IsEmpty() == true)
		return false;
	x = elements[front];
	front = (front+1)%maxSize;
	return true;
};

//若队列不空则函数返回该队列对头元素的值
template<class T>
bool SeqQueue<T>::getFront(T& x){
	if(IsEmpty() == true)
		return false;
	x = elements[front];
	return true;
};

//重载<<：输出队中元素的重载操作<<
template<class T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q){
	os<<"front="<<Q.front<<",rear="<<Q.rear<<endl;
	for(int i=front; i != rear; (i+1)%maxSize;)
		os<<i<<":"<<Q.elements[i]<<endl;
	return os;
};

template <class T>
class Deque: public Queue<T>{
public:
	virtual bool getHead(T& x)const = 0;
	virtual bool getTail(T& x)const = 0;

	virtual bool EnQueue(const T& x);
	virtual bool EnQueueHead(const T& x) = 0;
	virtual bool EnQueueTail(const T& x) = 0;

	virtual bool DeQueue(T& x);
	virtual bool DeQueueHead(T& x) = 0;
	virtual bool DeQueueTail(T& x) = 0;
};

template<class T>
bool Deque<T>::EnQueue(const T& x){
	return EnQueueTail(x);
};

template<class T>
bool Deque<T>::DeQueue(T& x){
	T temp;
	bool tag = DeQueueHead(temp);
	x = temp;
	return tag;
};

template <class T>
class SeqDeque:public Deque<T>, public SeqQueue<T>{
public:
	SeqDeque(int sz);
};

template <class T>
bool SeqDeque<T>::getHead(T& x)const{
	T temp;
	bool tag = SeqQueue<T>::getFront(temp);
	x = temp;
	return tag;
};

template <class T>
bool SeqDeque<T>::EnQueueTail(const T& x){
	return SeqQueue<T>::EnQueue(x);
};

template <class T>
bool SeqDeque<T>::DeQueueHead(T& x){
	T temp;
	bool tag = SeqQueue<T>::DeQueue(temp);
	x = temp;
	return tag;
};

template <class T>
bool SeqDeque<T>::getTail(T& x)const{
	if(front == rear)
		return false;
	x = elements[(rear-1+masSize)%maxSize];
	return true;
};

template <class T>
bool SeqDeque<T>::EnQueueHead(const T& x){
	if((rear+1)% maxSize == front)
		return false;
	x = elements[(rear-1+maxSize)%maxSize];
	return true;
};

template <class T>
bool SeqDeque<T>::DeQueueTail(T& x){
	if(front == rear)
		return false;
	rear = (rear-1+maxSize)%maxSize;
	x = elements[rear];
	return true;
};



