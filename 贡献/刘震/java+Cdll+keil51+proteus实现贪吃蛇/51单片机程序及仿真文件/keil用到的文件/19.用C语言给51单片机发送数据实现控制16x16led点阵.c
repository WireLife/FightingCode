// 19.��C���Ը���Ƭ����������ʵ�ֿ���16x16led����
#include<reg52.h>
#include<intrins.h>   // ����_nop_()
typedef unsigned char u8;
typedef unsigned int u16;

//���������Ų���hc595оƬ
sbit dataClk = P2^0;                
sbit dataBit = P2^1;
sbit viewClk = P2^2;

// ��ʼ�����еĵƶ����� 
u8 led[32]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8 code pos[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01}; 

// ��ʼ������
void set(){
  // ���ö�ʱ����������ѡΪ9600�����ӱ�
  TMOD = 0x20;    // �ö�ʱ��1,������ʽ2����װ��λ,0010 0000
  TH1 = 0xfd;     // ������9600 
  TL1 = 0xfd;

  // ���ӱ�
  PCON = 0x00;

  // ���ô��ڹ�����ʽ
  SCON = 0x50;      // ������ʽ1����������� 0100 0000;

  // �����ж�
  EA = 1;   // �������ж�
  ES = 1;   // ���Ŵ����ж�

  // ������ʱ��
  TR1 = 1;
}

// ��ʱ
void delay(u16 time){
  while(time--);
}

// �ѽ��յ�����һλһλ�ķ��͸���ת��оƬ��һ�η�4���ֽڣ�
void outHc595(u8 dat1,u8 dat2,u8 dat3,u8 dat4 ){
  u8 i;
  // һλ�ֽڵĴ�ת��
  for(i=0;i<8;i++){
    dataBit = dat1 >> 7;   // ��һ���ֽڵĵ�һ��bitλ���͸�595оƬ
    dat1 <<= 1;      // ����ֽڵ�ÿ��bitλ��������һλ���ڶ���bitλ��ֵ������һ��bitλ
    dataClk = 0;
    _nop_();       // �ȴ�һ����������
    _nop_();
    dataClk = 1;   // 595��������������Ч
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
  while(1){    // �ѽ��ܵ����ݷ��͸�16x16led����
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

// �����жϺ���
void Ser() interrupt 4{
  static u8 i = 0;
  while(RI==0);      // �ȴ��������
  RI = 0;            // ����������ķ�ʽ��0��Ϊ������һ���ֽ���׼��
  led[i] = SBUF;     // �ѽ��ܻ�����������ȡ��������������ʾled���������
  i++;
  if(i==32)
    i=0;
}