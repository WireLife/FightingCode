#include<iostream>
using namespace std;

typedef struct
{
	int data[2000];
	int top0;
	int end0;
	int size;
	void push_front(int x){data[top0--]=x;size++;}
	void push_back(int x){data[end0++]=x;size++;}
	void pop_front(){if(top0==end0)cout<<"error!";else {top0++;size--;}}
	void pop_back(){if(top0==end0)cout<<"error!";else {end0--;size--;}}
	bool empty(){return(top0==end0);}
	int Size(){return size;}
	int front(){return data[top0+1];}
	int back(){return data[end0-1];}
}quque;

int main()
{
	quque q1;
	q1.top0=1000;
	q1.end0=1000;
	q1.size=0;
    int order;
    int x;
	while (1)
	{
		cout<<" 请选择命令:1-前端入队操作，2-前端出队操作,3-尾端入队操作，4-尾端出队操作，5-查询队列长度,6-结束 :";
        cin>>order;
        switch (order) 
		{
		case 1: 
			cout<<" 请输入前端需要入队的数值:"<<endl;
            cin>>x;
		    q1.push_front(x);
            break;
		case 2:
			if (q1.empty())
			{
				cout<<" 队列为空"<<endl;
                break;
			}
            cout<<"前端出队的数据为:"<<q1.front()<<endl;
        	q1.pop_front();
	    	break;
		case 3:
			cout<<" 请输入尾端需要入队的数值:"<<endl;
            cin>>x;
		    q1.push_back(x);
            break;
		case 4:
			if (q1.empty())
			{
				cout<<" 队列为空"<<endl;
                break;
			}
            cout<<"尾端出队的数据为:"<<q1.back()<<endl;
        	q1.pop_back();
	    	break;
		case 5:
			cout<<q1.Size()<<endl;
            break;
		default: goto q;
        }
    }
q:	       return 0;
}
