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
	
	int hx = 7; // 蛇头起始位置横坐标 
	int hy = 6; // 蛇头起始位置纵坐标
	int ex = 6; // 蛇尾坐标
	int ey = 6; // 蛇尾坐标 
	int cnt = 2, maxSnake;
	int foodx = (int)(Math.random()*16),foody = (int)(Math.random()*16);   // 起始随机生成食物的横纵坐标
	boolean isfail = false;  // 作为游戏是否结束的标志
	
  /*  因为没有加载图片所以用不上双缓存
	// 双缓冲解决闪烁问题  
	private Image offScreenImage = null;
	public void update(Graphics g) {
		if(offScreenImage == null) 
			offScreenImage = this.createImage(500,450);	
		Graphics gOff = offScreenImage.getGraphics();
		paint(gOff);
		g.drawImage(offScreenImage,0,0,null);
	}
  */
		
	// 窗口绘制**********************************************************************************************/
	@Override
	public void paint(Graphics g) {  // 窗口绘制，自动调用
		super.paint(g);
		
		g.setColor(Color.BLACK);     // 画墙为黑色
		g.fillRect(30, 50, 360, 360);
		g.setColor(Color.GREEN);    // 画草地为绿色
		g.fillRect(50, 70, 320, 320);
		
		// 扫描数组
		for(int i=0; i<16; i++)
			for(int j=0;j<16;j++) {				
				if(map[i][j]!=0) {   // 蛇身
					g.setColor(Color.RED);
					g.fillRect((j+1)*20+30, (i+1)*20+50, 20, 20);
				}
				if(map[i][j]==cnt) { // 蛇头
					g.setColor(Color.PINK);
					g.fillRect((j+1)*20+30, (i+1)*20+50, 20, 20);
				}
				if(map[i][j]==-1) { // 食物
					g.setColor(Color.YELLOW);
					g.fillOval((j+1)*20+30, (i+1)*20+50, 20, 20);					
				}
			}
		
		if(isfail) {    // 游戏结束
			g.setFont(new Font("宋体",Font.BOLD,50));
			g.setColor(Color.WHITE);
			g.drawString("Game Over\n",90, 200);
			g.drawString("scores:"+(cnt-map[ex][ey]-1),100,250);
			SnakeDll.snakedll.CloseCOM();  // 调用dll关闭串口
		}
	}
	
	// 多线程， 帮助我们重画窗口
	class PaintThread extends Thread{
		@Override
		public void run() {
			//super.run();
			while(true) {
				//System.out.println("执行了！");
				repaint(); // 重画
				try {
					Thread.sleep(40);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}			
		}
	}
	
	// 设置键盘监听事件，监听按键按下，
	class KeyMonitor extends KeyAdapter{
		@Override
		public void keyPressed(KeyEvent e) {
			//super.keyPressed(e);
			//System.out.println(e.getKeyCode());
			if(!isfail)
				move(e);
		}
	}
	
	// 逻辑控制
	public void move(KeyEvent e) {
		map[foodx][foody] = -1;			
		switch (e.getKeyCode()) {   // 判断键盘按下的是哪一个键
			case KeyEvent.VK_UP:   // 按下上键：蛇头的坐标向上移一位
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
		if(!(hx>=0&hx<=15&hy>=0&hy<=15))    // 如果蛇头撞到墙，游戏结束
			isfail = true;	
		else if(map[hx][hy]!=0&map[hx][hy]!=-1)  // 如果蛇吃到自己
			isfail = true;
		else {   								
			map[hx][hy] = ++cnt;          
		
			// 把尾巴去掉，如果迟到食物，不去尾巴，
			if(map[foodx][foody]==-1) {     // 如果没有吃到食物
				maxSnake = map[ex][ey];       // 把蛇尾的数字保存下来
				map[ex][ey] = 0;              // 最后一节消失
				if(ex>0)                      // 因为蛇尾的数字最小，蛇尾的数字的与蛇尾的上一节相差为1
					if(map[ex-1][ey] - maxSnake == 1) ex--;
				if(ex<15)
					if(map[ex+1][ey] - maxSnake == 1) ex++;
				if(ey>0)
					if(map[ex][ey-1] - maxSnake == 1) ey--;
				if(ey<15)
					if(map[ex][ey+1] - maxSnake == 1) ey++;			
			}
			else {
				while(map[foodx][foody]!=0) {         // 如果吃到食物，并重新生成食物坐标，但要避开蛇身
					foodx = (int)(Math.random()*16);
					foody = (int)(Math.random()*16);
				}
			}
			
			// 向单片机发送数据
			int i, j, ledtemp;
			for(j=0;j<16;j++) {
				ledtemp = 0;
				for(i=0;i<8;i++) {
					if(map[i][j]!=0)      // 如果某一个坐标非0，那么这个位置在led点阵上是亮点，对应的led灯位高电平
						ledtemp+=(int)Math.pow(2, i);   // 因为发送数据是一个字节一个字节发送，这里把二进制转化为整形
				}
				SnakeDll.snakedll.SentDataToCOM(ledtemp);  // 调用dll向单片机发送数据
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
			/*  查看数据
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
	 * 初始化窗口
	 */
	public void LunchFrame() {
		this.setTitle("贪吃蛇游戏");
		this.setVisible(true);
		this.setSize(420,450);
		this.setLocation(800,100);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// 启动多线程
		new PaintThread().start();  // 启动重画窗口的线程
		addKeyListener(new KeyMonitor()); // 给窗口增加键盘的监听
	}
	
	public static void main(String[] args) {
		snakeGame snake = new snakeGame();   // 创建对象
		snake.LunchFrame();             // 启动窗口
		SnakeDll.snakedll.OpenSerial();  // 调用dll打开串口，串口的类型已经在dll种定义
		SnakeDll.snakedll.SetComm();     // 调用dll设置串口属性，封装为:波特率9600，数据位8，停止位1，无校验
	}
}
