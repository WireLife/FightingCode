#pragma once

#include<Windows.h>
#include<iostream>
using namespace std;

extern "C" _declspec(dllexport) bool OpenSerial();
extern "C" _declspec(dllexport) void SetComm();
extern "C" _declspec(dllexport) void SentDataToCOM(int data);
extern "C" _declspec(dllexport) bool CloseCOM();