#include<iostream>
using namespace std;

typedef struct
{
    int data[2000];
    int top0;
    int end0;
    int size;
    bool quque_empty(){return size == 0;}//判空
    void push_front(int a){size++;data[top0] = a;top0--;}//首端入队
    void push_back(int a){size++;data[end0] = a;end0--;}//尾端入队
    void pop_front()//首端出队
    {
        if(top0 == end0)
            cout<<"error!"<<endl;
        else
        {
            top0++;
            size--;
        }
    }
    void pop_back()//尾端出队
    {
        if(top0 == end0)
            cout<<"error!"<<endl;
        else
        {
            end0--;
            size--;
        }
    }
    int quque_size(){return size;}//求长
    int front(){return data[top0+1];}//返回首元素
    int back(){return data[end0-1];}//返回尾元素
}quque;

int main()
{
    quque q1;
    q1.size = 0;
    q1.top0 = 1000;
    q1.end0 = 1000;
    int order;
    int x;
    while(1)
    {
        cout<<"请选择命令:1-前端入队操作，2-后端入队操作，3-前端出队操作，4-后端出队操作，5-查询长度，6-结束:";
        cin>>order;
        switch (order)
        {
        case 1: {
            cout<<"请输入前端需要入队的数值:"<<endl;
            cin>>x;
            q1.push_front(x);
            break;
        }
        case 2: {
            cout<<"请输入后端需要入队的数值:"<<endl;
            cin>>x;
            q1.push_back(x);
            break;
        }
        case 3: {
            if(q1.quque_empty())
            {
                cout<<"队列为空"<<endl;
                break;
            }
            cout<<"前端出队的数据为:"<<q1.front()<<endl;
            q1.pop_front();
            break;
        }
        case 4: {
            if(q1.quque_empty())
            {
                cout<<"队列为空"<<endl;
                break;
            }
            cout<<"后端出队的数据为:"<<q1.back()<<endl;
            q1.pop_back();
            break;
        }
        case 5: {
            cout<<q1.quque_size()<<endl;
            break;
        }
        default: goto q;
        }
    }
    q: return 0;
}
