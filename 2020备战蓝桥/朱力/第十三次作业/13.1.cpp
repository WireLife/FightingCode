#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include<deque>
using namespace std;
typedef struct
{
    int data[2000];
    int top0;
    int end0;
    int size;
    bool quque_empty() { return size == 0; }                    //判空
    void push_front(int x) { size++; data[top0] = x; top0--; }  //队首入队
    void push_back(int x) { size++; data[end0] = x; end0--; }   //队尾入队
    void pop_front()//首出队
    {
        if (top0 == end0) {
            cout << "default" << endl;
        }
        else
        {
            top0++;
            size--;
        }
    }
    void pop_back()                         //队尾出队
    {
        if (top0 == end0) {
            cout << "default" << endl;
        }
        else
        {
            end0--;
            size--;
        }
    }
    int quque_size() { return size; }       //求队长
    int front() { return data[top0 + 1]; }  //返回队首元素
    int back() { return data[end0 - 1]; }   //返回队尾元素
}quque;

int main()
{
    quque Q;
    Q.size = 0;
    Q.top0 = 1000;      //从中间开始往两边走
    Q.end0 = 1000;
    int order;          //case控制条件
    int x;              //数据输入
    while (1)
    {
        cout << "请选择命令:1-前端入队操作，2-后端入队操作，3-前端出队操作，4-后端出队操作，5-查询长度，6-结束:";
        cout << endl;
        cin >> order;
        switch (order)
        {
        case 1: {
            cout << "请输入前端入队的数值:" << endl;
            cin >> x;
            Q.push_front(x);
            break;
        }
        case 2: {
            cout << "请输入后端入队的数值:" << endl;
            cin >> x;
            Q.push_back(x);
            break;
        }
        case 3: {
            if (Q.quque_empty()){
                cout << "队列为空" << endl;//为空输出1，不为空输出0；
                break;
            }
            cout << "前端出队的数据为:" << Q.front() << endl;
            Q.pop_front();
            break;
        }
        case 4: {
            if (Q.quque_empty())
            {
                cout << "队列为空" << endl;
                break;
            }
            cout << "后端出队的数据为:" << Q.back() << endl;
            Q.pop_back();
            break;
        }
        case 5: {
            cout << Q.quque_size() << endl;
            break;
        }
        default: goto q;
        }
    }
q: return 0;
}