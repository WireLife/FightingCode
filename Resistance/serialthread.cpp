#include "serialthread.h"

SerialThread::SerialThread(QObject *parent) : QObject(parent)
{
    thread = new QThread();         // 创建一个子线程对象
    testWin = new Test();           // 创建一个串口对象
    this->moveToThread(thread);         // 把本对象放在子线程中
    testWin->moveToThread(thread);      // 把串口对象放在子线程当中
}


// 单次测量
void SerialThread::singleTest()
{
    double R0 = 1, R01 = 2, R1 = 3, R2 = 4, Rx = 5;
    QByteArray vis1, vis2;


    for(int i = 0; i < 3; i++)      // 先发送一组数据，获取第一个电桥的状态
    {
        testWin->mainWinWrite("00");
        qDebug()<< "在向硬件发送数据";
        while((vis1 = testWin->mainWinRead()).isEmpty()) //; // 等待硬件电路返回数据
            qDebug()<< "等待接收数据" << endl;
    }
/*
    for(int i = 0; i < 99; i++)
    {
        for(int j = 0; j < 3; j++)
        {    // 发送三次数据，算一组数据
            testWin.mainWinWrite("00");
            while((vis2 = testWin.mainWinRead()).isEmpty());  // 等待硬件电路返回数据
        }
        if(vis1 != vis2)
            break;
    }
*/
    emit singleTestDone(R0, R01, R1, R2, Rx);
}


// 多次测量
