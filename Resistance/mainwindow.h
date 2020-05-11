#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tableview.h"   // 数据库头文件
#include "serialthread.h" // 串口线程头文件

// 添加布局相关的头文件
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>

// 测试头文件
#include <QDebug>

// 数据类型注册头文件
#include <QMetaType>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_resTest_clicked();

    void on_pushButton_dataHandle_clicked();

    void on_pushButton_resValueRecorde_clicked();

    void on_pushButton_testSpecific_clicked();

    void on_pushButton_startTest_clicked();

    void on_pushButton_stopTest_clicked();

public slots:
    void upDataToTableView(double, double, double, double, double);


private:
    Ui::MainWindow *ui;
    TableView tableView;
    bool isStopTest = false;

    SerialThread *serialThread;

private:
    void initMainWindow();

};
#endif // MAINWINDOW_H
