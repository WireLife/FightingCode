// snakeDll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Inc.h"


// 将要导出的函数

// 打开串口
// 配置串口
// 读写串口
// 关闭串口

// 打开串口
static HANDLE hCom;
static DCB dcb;
bool OpenSerial() {

	hCom = CreateFile(
		TEXT("COM5"),							// 要打开的串口名 
		GENERIC_READ | GENERIC_WRITE,   // 允许读写
		0,								// 独享
		NULL,
		OPEN_EXISTING,					// 串口已经存在
		FILE_ATTRIBUTE_NORMAL,			// 普通
		NULL);
	if (hCom == INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("打开串口失败"), TEXT("串口状态"), MB_OK);
		//cout << COM << endl;
		return false;
	}
	else {
		return false;
	}
}

// 配置串口
void SetComm() {
	// 设置读写缓冲区
	SetupComm(hCom, 1024, 1024); 
	
	// 获得串口属性
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 9600;
	dcb.ByteSize = 8;
	dcb.Parity = 0;
	dcb.StopBits = 1;

	// 重新设置串口属性
	SetCommState(hCom, &dcb);

	// 清空缓存区
	PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
}

DWORD dwWrittenLen = 0;
// 向串口发送数据,每次只发送一个字节
void SentDataToCOM(int data) {
	char c[1] = { data };
	WriteFile(hCom, c, 1, &dwWrittenLen, NULL);
}

// 关闭串口
bool CloseCOM() {
	return CloseHandle(hCom);
}
