#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMessageBox>

#include "test.h"

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    // 单次测量
    void singleTest();

    // 多次测量
    void repeateTest();

    // 专用测试窗口显示
    void showTestWin();


protected:
    // QThread的虚函数
    // 线程处理函数
    // 不能直接调用，要通过start间接调用
    void run();

signals:
    // 向主窗口发送一侧测试的数据信号
    void singleTestDone(double, double, double, double, double);

private:



public:
    bool isSingleTest = true;

};

#endif // MYTHREAD_H
