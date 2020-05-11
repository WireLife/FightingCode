#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    // 获取有用或者闲置端口，并且添加到串口选择下拉框
    findSerial();
    // 初始化串口，设置波特率，停止位...
    initSerials();


    connect(&serial,&QSerialPort::readyRead,this,&Test::readData);
}

Test::~Test()
{
    delete ui;
}

// 查找计算机可用串口
void Test::findSerial()
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort tempSerial;
        tempSerial.setPort(info);
        if(tempSerial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_serialSelect->addItem(tempSerial.portName());
            tempSerial.close();
        }
    }
}



void Test::initSerials()
{
    // serial.open(QIODevice::ReadWrite);
    // 设置串口名
    ui->comboBox_serialSelect->currentText();
    // 设置波特率
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());
    // 设置停止位
    serial.setStopBits(QSerialPort::OneStop);
    // 设置数据位
    serial.setDataBits(QSerialPort::Data8);
    // 设置校验位
    serial.setParity(QSerialPort::NoParity);
    // 设置流控制
    serial.setFlowControl(QSerialPort::NoFlowControl);

    // 把串口打开设为默认
    ui->checkBox_openSerial->setCheckState(Qt::Checked);
}


// 如果串口当前选择端口名改变，串口端口名设置为改变后的值
void Test::on_comboBox_serialSelect_currentIndexChanged(int index)
{
    serial.setPortName(ui->comboBox_serialSelect->currentText());
}
// 如果串口当前选择波特率改变，串口波特率设置为改变后的值
void Test::on_comboBox_baudRate_currentIndexChanged(int index)
{
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());
}

// 如果串口当前选择停止位位改变，串口停止位设置为改变后的值
void Test::on_comboBox_stopBits_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setStopBits(QSerialPort::OneStop); break;
        case 1:
            serial.setStopBits(QSerialPort::OneAndHalfStop); break;
        case 2:
            serial.setStopBits(QSerialPort::TwoStop); break;
    }
}

// 如果串口当前选择数据位改变，串口数据位设置为改变后的值
void Test::on_comboBox_dataBits_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setDataBits(QSerialPort::Data8);  break;
        case 1:
            serial.setDataBits(QSerialPort::Data7);  break;
        case 2:
            serial.setDataBits(QSerialPort::Data6);  break;
        case 3:
            serial.setDataBits(QSerialPort::Data5);  break;
    }
}

// 如果串口当前选择校验位改变，串口校验位设置为改变后的值
void Test::on_comboBox_parity_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setParity(QSerialPort::NoParity);  break;
        case 1:
            serial.setParity(QSerialPort::EvenParity);  break;
        case 2:
            serial.setParity(QSerialPort::OddParity);  break;
    }
}

// 利用复选框控制串口的打开还是关闭
void Test::on_checkBox_openSerial_stateChanged(int arg1)
{
    switch(arg1)
    {
        case Qt::Unchecked:
            serial.close();
            break;
        case Qt::Checked:
            if(!serial.open(QIODevice::ReadWrite))
                QMessageBox::warning(this, "Error", "串口未打开或者被占用！");
            break;
    }
}


// 切换端口
void Test::on_comboBox_serialSelect_currentTextChanged(const QString &arg1)
{
    serial.close();
    serial.setPortName(arg1);
    if(ui->checkBox_openSerial->checkState() == Qt::Checked)
        if(!serial.open(QIODevice::ReadWrite))
            QMessageBox::warning(this, "Error", "串口未打开或者被占用！");
}


// 发送
void Test::on_pushButton_send_clicked()
{
    serial.write(ui->plainTextEdit_singleSend->toPlainText().toLatin1());
}

// 清除发送区
void Test::on_pushButton_clearSend_clicked()
{
    ui->plainTextEdit_singleSend->clear();
}

// 接受数据
void Test::readData()
{
    dataRead.clear();
    QByteArray buf;
    buf = serial.readAll();
    if(!buf.isEmpty())
    {
        ui->plainTextEdit_receiveDisplay->appendPlainText(buf);
        dataRead = buf;
    }
    buf.clear();
}

// 清除接收区
void Test::on_pushButton_clearReceive_clicked()
{
    ui->plainTextEdit_receiveDisplay->clear();
}



/****************************************主窗口专用***************************************************/
// 主窗口调用发送数据
void Test::mainWinWrite(QByteArray data)
{
    serial.write(data);
}

// 主窗口调用接收数据
QByteArray Test::mainWinRead()
{
    QByteArray temp = dataRead;
    dataRead.clear();
    return temp;
}

// 主窗口用于判断串口是否打开
bool Test::isSerialOpen()
{
    if(ui->checkBox_openSerial->checkState() == Qt::Checked)  // 如果checkBox被选中,证明打开了串口
        return true;
    else
        return false;
}
