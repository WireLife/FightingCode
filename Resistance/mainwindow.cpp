#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   

    //qRegisterMetaType<bool>("bool");       //数据类型注册，多线程传参用
    qRegisterMetaType<double>("double");

    serialThread = new SerialThread();          // 定义串口线程对象

    initMainWindow();   // 初始化窗口

    // 建立测试完数据给主窗口发送信号请求接收数据
    connect(serialThread, SIGNAL(singleTestDone(double,double,double,double,double)), this, SLOT(upDataToTableView(double,double,double,double,double)));
    connect(ui->pushButton_startTest, SIGNAL(clicked()), serialThread, SLOT(singleTest()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    // 堆栈窗口第一页纵向布局
    QVBoxLayout *vLayout = new QVBoxLayout;    // 纵向布局
    vLayout->addWidget(ui->widget);
    vLayout->addWidget(&tableView);
    ui->page_resTest->setLayout(vLayout);
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // 设置表格填满父窗口

    tableView.MainWin_setHandSubmit(true);      // 设置表格手动提交更新数据库
}

void MainWindow::on_pushButton_resTest_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_dataHandle_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_resValueRecorde_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_testSpecific_clicked()
{

}

void MainWindow::on_pushButton_startTest_clicked()
{
    ui->radioButton_singleTest->setEnabled(false);       // 单次测量的选项消除使能
    ui->radioButton_multipleTest->setEnabled(false);     // 多次测量的选项消除使能

//    if(ui->radioButton_singleTest->isChecked())         // 判断是多次测量还是单次测量
//        serialThread->singleTest();                     // 进行单次测量
//    else
//        ;

}
// 停止测量槽函数
void MainWindow::on_pushButton_stopTest_clicked()
{
    isStopTest = true;
}

// 向主窗口展示数据部分增加一条记录
void MainWindow::upDataToTableView(double R0, double R01, double R1, double R2, double Rx)
{
    tableView.MainWin_addRecordToTable(R0, R01, R1, R2, Rx);    // 向显示数据表格中增加一条记录
    ui->radioButton_singleTest->setEnabled(true);           // 单次测量的选项恢复使能
    ui->radioButton_multipleTest->setEnabled(true);         // 多次测量的选项回复使能
}
