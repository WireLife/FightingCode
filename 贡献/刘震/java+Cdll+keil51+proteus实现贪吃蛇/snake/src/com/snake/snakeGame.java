package com.snake;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;

public class snakeGame extends JFrame{
	int map[][] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	
	int hx = 7; // ��ͷ��ʼλ�ú����� 
	int hy = 6; // ��ͷ��ʼλ��������
	int ex = 6; // ��β����
	int ey = 6; // ��β���� 
	int cnt = 2, maxSnake;
	int foodx = (int)(Math.random()*16),foody = (int)(Math.random()*16);   // ��ʼ�������ʳ��ĺ�������
	boolean isfail = false;  // ��Ϊ��Ϸ�Ƿ�����ı�־
	
  /*  ��Ϊû�м���ͼƬ�����ò���˫����
	// ˫��������˸����  
	private Image offScreenImage = null;
	public void update(Graphics g) {
		if(offScreenImage == null) 
			offScreenImage = this.createImage(500,450);	
		Graphics gOff = offScreenImage.getGraphics();
		paint(gOff);
		g.drawImage(offScreenImage,0,0,null);
	}
  */
		
	// ���ڻ���**********************************************************************************************/
	@Override
	public void paint(Graphics g) {  // ���ڻ��ƣ��Զ�����
		super.paint(g);
		
		g.setColor(Color.BLACK);     // ��ǽΪ��ɫ
		g.fillRect(30, 50, 360, 360);
		g.setColor(Color.GREEN);    // ���ݵ�Ϊ��ɫ
		g.fillRect(50, 70, 320, 320);
		
		// ɨ������
		for(int i=0; i<16; i++)
			for(int j=0;j<16;j++) {				
				if(map[i][j]!=0) {   // ����
					g.setColor(Color.RED);
					g.fillRect((j+1)*20+30, (i+1)*20+50, 20, 20);
				}
				if(map[i][j]==cnt) { // ��ͷ
					g.setColor(Color.PINK);
					g.fillRect((j+1)*20+30, (i+1)*20+50, 20, 20);
				}
				if(map[i][j]==-1) { // ʳ��
					g.setColor(Color.YELLOW);
					g.fillOval((j+1)*20+30, (i+1)*20+50, 20, 20);					
				}
			}
		
		if(isfail) {    // ��Ϸ����
			g.setFont(new Font("����",Font.BOLD,50));
			g.setColor(Color.WHITE);
			g.drawString("Game Over\n",90, 200);
			g.drawString("scores:"+(cnt-map[ex][ey]-1),100,250);
			SnakeDll.snakedll.CloseCOM();  // ����dll�رմ���
		}
	}
	
	// ���̣߳� ���������ػ�����
	class PaintThread extends Thread{
		@Override
		public void run() {
			//super.run();
			while(true) {
				//System.out.println("ִ���ˣ�");
				repaint(); // �ػ�
				try {
					Thread.sleep(40);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}			
		}
	}
	
	// ���ü��̼����¼��������������£�
	class KeyMonitor extends KeyAdapter{
		@Override
		public void keyPressed(KeyEvent e) {
			//super.keyPressed(e);
			//System.out.println(e.getKeyCode());
			if(!isfail)
				move(e);
		}
	}
	
	// �߼�����
	public void move(KeyEvent e) {
		map[foodx][foody] = -1;			
		switch (e.getKeyCode()) {   // �жϼ��̰��µ�����һ����
			case KeyEvent.VK_UP:   // �����ϼ�����ͷ������������һλ
				hx -= 1;
				break;
			case KeyEvent.VK_DOWN: 
				hx += 1;
				break;
			case KeyEvent.VK_LEFT: 
				hy -= 1;
				break;
			case KeyEvent.VK_RIGHT: 
				hy += 1;
				break;
			default : return;
		}
		if(!(hx>=0&hx<=15&hy>=0&hy<=15))    // �����ͷײ��ǽ����Ϸ����
			isfail = true;	
		else if(map[hx][hy]!=0&map[hx][hy]!=-1)  // ����߳Ե��Լ�
			isfail = true;
		else {   								
			map[hx][hy] = ++cnt;          
		
			// ��β��ȥ��������ٵ�ʳ���ȥβ�ͣ�
			if(map[foodx][foody]==-1) {     // ���û�гԵ�ʳ��
				maxSnake = map[ex][ey];       // ����β�����ֱ�������
				map[ex][ey] = 0;              // ���һ����ʧ
				if(ex>0)                      // ��Ϊ��β��������С����β�����ֵ�����β����һ�����Ϊ1
					if(map[ex-1][ey] - maxSnake == 1) ex--;
				if(ex<15)
					if(map[ex+1][ey] - maxSnake == 1) ex++;
				if(ey>0)
					if(map[ex][ey-1] - maxSnake == 1) ey--;
				if(ey<15)
					if(map[ex][ey+1] - maxSnake == 1) ey++;			
			}
			else {
				while(map[foodx][foody]!=0) {         // ����Ե�ʳ�����������ʳ�����꣬��Ҫ�ܿ�����
					foodx = (int)(Math.random()*16);
					foody = (int)(Math.random()*16);
				}
			}
			
			// ��Ƭ����������
			int i, j, ledtemp;
			for(j=0;j<16;j++) {
				ledtemp = 0;
				for(i=0;i<8;i++) {
					if(map[i][j]!=0)      // ���ĳһ�������0����ô���λ����led�����������㣬��Ӧ��led��λ�ߵ�ƽ
						ledtemp+=(int)Math.pow(2, i);   // ��Ϊ����������һ���ֽ�һ���ֽڷ��ͣ�����Ѷ�����ת��Ϊ����
				}
				SnakeDll.snakedll.SentDataToCOM(ledtemp);  // ����dll��Ƭ����������
				//System.out.print(ledtemp+"  ");
			}
		  // System.out.println();
			for(j=0;j<16;j++) {
				ledtemp = 0;
				for(i=8;i<16;i++)
					if(map[i][j]!=0)
						ledtemp+=(int)Math.pow(2, i-8);
				SnakeDll.snakedll.SentDataToCOM(ledtemp);
				//System.out.print(ledtemp+"  ");
			}
      
		  // System.out.println();
			/*  �鿴����
			for(i=0;i<16;i++) {
				System.out.println();
				for(j=0;j<16;j++)
					System.out.print(map[i][j]+"  ");
			}
			System.out.println();
			System.out.println("/-------------------------------------------------------------------------------------/");
			*/
		}
	}
		
	/**
	 * ��ʼ������
	 */
	public void LunchFrame() {
		this.setTitle("̰������Ϸ");
		this.setVisible(true);
		this.setSize(420,450);
		this.setLocation(800,100);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// �������߳�
		new PaintThread().start();  // �����ػ����ڵ��߳�
		addKeyListener(new KeyMonitor()); // ���������Ӽ��̵ļ���
	}
	
	public static void main(String[] args) {
		snakeGame snake = new snakeGame();   // ��������
		snake.LunchFrame();             // ��������
		SnakeDll.snakedll.OpenSerial();  // ����dll�򿪴��ڣ����ڵ������Ѿ���dll�ֶ���
		SnakeDll.snakedll.SetComm();     // ����dll���ô������ԣ���װΪ:������9600������λ8��ֹͣλ1����У��
	}
}
