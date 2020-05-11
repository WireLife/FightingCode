#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

// 和数据库操作有关
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>

// 信息提示窗口类头文件
#include <QMessageBox>
#include <QDebug>

class TableView : public QTableView
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

    void MainWin_addRecordToTable(double R0 = 0, double R01 = 0, double R1 = 0, double R2 = 0, double Rx = 0);  // 外部函数向数据库发送记录
    void MainWin_setHandSubmit(bool flag);



private:
    QSqlDatabase db;
    QSqlTableModel *tableModel;
    QSqlQuery query;


private:
    void openMysql();
    void putModelToTableView();
};

#endif // TABLEVIEW_H
