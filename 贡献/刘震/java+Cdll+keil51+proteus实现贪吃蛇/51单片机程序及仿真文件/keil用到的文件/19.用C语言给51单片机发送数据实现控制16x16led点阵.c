// 19.用C语言给单片机发送数据实现控制16x16led点阵
#include<reg52.h>
#include<intrins.h>   // 包含_nop_()
typedef unsigned char u8;
typedef unsigned int u16;

//用三个引脚操作hc595芯片
sbit dataClk = P2^0;                
sbit dataBit = P2^1;
sbit viewClk = P2^2;

// 初始化所有的灯都不亮 
u8 led[32]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8 code pos[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 

// 初始化串口
void set(){
  // 设置定时器，波特率选为9600，不加倍
  TMOD = 0x20;    // 用定时器1,工作方式2，重装八位,0010 0000
  TH1 = 0xfd;     // 波特率9600 
  TL1 = 0xfd;

  // 不加倍
  PCON = 0x00;

  // 设置串口工作方式
  SCON = 0x50;      // 工作方式1，不允许接收 0100 0000;

  // 设置中断
  EA = 1;   // 开放总中断
  ES = 1;   // 开放串口中断

  // 启动定时器
  TR1 = 1;
}

// 延时
void delay(u16 time){
  while(time--);
}

// 把接收的数据一位一位的发送给串转并芯片，一次发4个字节，
void outHc595(u8 dat1,u8 dat2,u8 dat3,u8 dat4 ){
  u8 i;
  // 一位字节的串转并
  for(i=0;i<8;i++){
    dataBit = dat1 >> 7;   // 把一个字节的第一个bit位发送给595芯片
    dat1 <<= 1;      // 这个字节的每个bit位整体左移一位，第二个bit位数值移至第一个bit位
    dataClk = 0;
    _nop_();       // 等待一个及其周期
    _nop_();
    dataClk = 1;   // 595好像是上升沿有效
  }
  
  for(i=0;i<8;i++){
    dataBit = dat2 >> 7;
    dat2 <<= 1;
    dataClk = 0;
    _nop_();
    _nop_();
    dataClk = 1;
  }

  for(i=0;i<8;i++){
    dataBit = dat3 >> 7;
    dat3 <<= 1;
    dataClk = 0;
    _nop_();
    _nop_();
    dataClk = 1;
  }
  
  for(i=0;i<8;i++){
    dataBit = dat4 >> 7;
    dat4 <<= 1;
    dataClk = 0;
    _nop_();
    _nop_();
    dataClk = 1;
  }
       
  viewClk = 0;
  _nop_();
  _nop_();
  viewClk = 1;
}  

void main(){
  u8 i,a = 0x01;
  set();
  while(1){    // 把接受的数据发送给16x16led点阵
    for(i=0;i<8;i++){
      outHc595(0x00,pos[i],~led[i],~led[i+16]);
      delay(10);
    }
    for(i=8;i<16;i++){
      outHc595(pos[i-8],0x00,~led[i],~led[i+16]);
      delay(10);
    }      
  }
}

// 串口中断函数
void Ser() interrupt 4{
  static u8 i = 0;
  while(RI==0);      // 等待接受完毕
  RI = 0;            // 必须以软件的方式置0，为接受下一个字节做准备
  led[i] = SBUF;     // 把接受缓冲区的数据取出来赋给用来显示led点阵的数组
  i++;
  if(i==32)
    i=0;
}