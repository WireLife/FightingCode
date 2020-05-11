#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QMessageBox>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    ~Test();

    void mainWinWrite(QByteArray data);   // 外部接口用于发送数据
    QByteArray mainWinRead();           // 外部接口用于接收数据
    bool isSerialOpen();

private slots:
    void on_comboBox_serialSelect_currentIndexChanged(int index);

    void on_comboBox_baudRate_currentIndexChanged(int index);

    void on_comboBox_stopBits_currentIndexChanged(int index);

    void on_comboBox_dataBits_currentIndexChanged(int index);

    void on_comboBox_parity_currentIndexChanged(int index);

    void on_checkBox_openSerial_stateChanged(int arg1);

    void on_comboBox_serialSelect_currentTextChanged(const QString &arg1);

    void on_pushButton_send_clicked();

    void on_pushButton_clearSend_clicked();

    void readData();

    void on_pushButton_clearReceive_clicked();

private:
    Ui::Test *ui;
    QSerialPort serial;
    QByteArray dataRead;


private:
    void findSerial();   // 查找计算机可用串口
    void initSerials();  // 初始化串口

};

#endif // TEST_H
