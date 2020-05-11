#include "tableview.h"

TableView::TableView(QWidget *parent) : QTableView(parent)
{
    openMysql();            // 连接数据库并且打开数据库
    putModelToTableView();  // 把数据库放在tableView里面
}

TableView::~TableView()
{
    tableModel->submitAll();   // 最终所有的记录都要上传至数据库当中
}

// 打开数据库
void TableView::openMysql()
{
    // 1.创建一个数据库句柄
    db = QSqlDatabase::addDatabase("QMYSQL");

    // 2.连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("sql3835...");
    db.setDatabaseName("stu");

    // 3.打开数据库
    if(!db.open()){
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    query = QSqlQuery(db);   // 获取当前使用的数据库
}

// 把数据库放在tableView里面
void TableView::putModelToTableView()
{
    tableModel = new QSqlTableModel(this);      // 创建一个数据库表格模型
    tableModel->setTable("student");            // 使用的是哪个表？
    setModel(tableModel);                       // 把tableModel放在tableView里面
    tableModel->select();                       // 显示tableModel数据
    setEditTriggers(QAbstractItemView::NoEditTriggers);     // 设置tableView不允许界面修改
}



/******************************************主窗口专用************************************************************/
// 向数据库插入一条记录,并在主窗口的表格里面显示出来，如果要上传至数据库需要手动提交或者在析构函数中提交。
void TableView::MainWin_addRecordToTable(double R0, double R01, double R1, double R2, double Rx)
{
    QSqlRecord record = tableModel->record();       // 获得表格一条空记录
    record.setValue("R0", R0);
    record.setValue("R0'", R01);
    record.setValue("R1", R1);
    record.setValue("R2", R2);
    record.setValue("Rx", Rx);
    int row = tableModel->rowCount();           // 获取目前表格最后一行有记录的行号
    tableModel->insertRecord(row, record);      // 在第一个空行里面插入一条记录
    //QString data = QString("insert into student(R0,`R0'`,R1,R2,Rx) values('%1','%2','%3','%4','%5')").arg(R0).arg(R01).arg(R1).arg(R2).arg(Rx);
    //query.exec(data);
}

// 设置手动提交
void TableView::MainWin_setHandSubmit(bool flag)
{
    if(flag)
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);  // 手动提交
    else
        tableModel->setEditStrategy(QSqlTableModel::OnFieldChange);   // 直接提交至数据库
}
