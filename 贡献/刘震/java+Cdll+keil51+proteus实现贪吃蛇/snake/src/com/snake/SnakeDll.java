package com.snake;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface SnakeDll extends Library {
	SnakeDll snakedll = (SnakeDll)Native.load("snakeDll", SnakeDll.class);
	boolean OpenSerial();  // �򿪴���
	void SetComm(); 			// ���ô���
	void SentDataToCOM(int data);   // ��������
	boolean CloseCOM();				// �رմ���
}
