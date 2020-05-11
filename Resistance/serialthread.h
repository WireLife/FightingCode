#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QObject>
#include <QThread>      // 线程头文件
#include <QByteArray>   // 接收串口的数据用的头文件

#include <QDebug>   // 输出头文件

#include "test.h"   // 串口对象头文件

class SerialThread : public QObject
{
    Q_OBJECT
public:
    explicit SerialThread(QObject *parent = nullptr);

public slots:
    void singleTest();   // 单次测量

signals:
    void singleTestDone(double, double, double, double, double);


public slots:




private:
    QThread *thread;   // 里面存放串口的线程
    Test *testWin;     // 串口指针
};

#endif // SERIALTHREAD_H
