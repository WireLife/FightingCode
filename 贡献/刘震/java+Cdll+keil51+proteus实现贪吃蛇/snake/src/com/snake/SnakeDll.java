package com.snake;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface SnakeDll extends Library {
	SnakeDll snakedll = (SnakeDll)Native.load("snakeDll", SnakeDll.class);
	boolean OpenSerial();  // 打开串口
	void SetComm(); 			// 配置串口
	void SentDataToCOM(int data);   // 发送数据
	boolean CloseCOM();				// 关闭串口
}
