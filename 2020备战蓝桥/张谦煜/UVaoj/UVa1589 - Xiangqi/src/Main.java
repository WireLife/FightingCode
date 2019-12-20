import java.util.*;

class Point
{
	public int x;
	public int y;

	public Point(int x,int y) 
	{
		this.x=x;
		this.y=y;
	}
	
	@Override
	public boolean equals(Object o)
	{
		if(this == o)
			return true;
		if(o == null || getClass()!=o.getClass())
			return false;
		
		Point point =(Point)o;
		return x==point.x&&y==point.y;
	}
	
	@Override
	public int hashCode()
	{
		return Objects.hash(x,y);
	}
}

enum Type
{
	Null,blackgeneral,redgeneral,chariot,cannon,horse
}

public class Main {
	static ArrayList<Point> list = new ArrayList<Point>();
	static Map<Point,Type> map = new HashMap<Point,Type>();
	static Point BlackGp;
	
	
	//一定被吃返回true
	static boolean win(Point tmpP) {
		for(Point item:list)
		{
			if(map.get(item)==Type.redgeneral)
			{
				if(item.y==tmpP.y&&!item.equals(tmpP))
				{
					boolean flag=false;
					for(Point item2:list)
					{
						if(item2.y==item.y&&(item2.x<item.x&&item2.x>tmpP.x))
						{
							flag=true;
							break;
						}
					}
					if(!flag)
					{
						return true;
					}
				}
			}
			else if(map.get(item)==Type.chariot)
			{
				if(item.x==tmpP.x&&!item.equals(tmpP))
				{
					boolean flag=false;
					for(Point item2:list)
					{
						if(item2.x==item.x&&((item2.y<item.y&&item2.y>tmpP.y)||item2.y>item.y&&item2.y<tmpP.y))
						{
							flag=true;
							break;
						}
					}
					if(!flag)
					{
						return true;
					}
				}
				else if(item.y==tmpP.y&&!item.equals(tmpP))
				{
					boolean flag=false;
					for(Point item2:list)
					{
						if(item2.y==item.y&&((item2.x<item.x&&item2.x>tmpP.x)||item2.x>item.x&&item2.x<tmpP.x))
						{
							flag=true;
							break;
						}
					}
					if(!flag)
					{
						return true;
					}
				}
			}
			else if(map.get(item)==Type.cannon)
			{
				if(item.x==tmpP.x&&!item.equals(tmpP))
				{
					int num =0;
					for(Point item2:list)
					{
						if(item2.x==item.x&&(item2.y>Math.min(item.y,tmpP.y)&&item2.y<Math.max(item.y,tmpP.y)))
						{
							if(num==1)
							{
								num++;
								break;
							}
							num++;
						}
					}
					if(num==1)
					{
						return true;
					}
				}
				else if(item.y==tmpP.y)
				{
					int num =0;
					for(Point item2:list)
					{
						if(item2.y==item.y&&(item2.x<item.x&&item2.x>tmpP.x))
						{
							if(num==1)
							{
								num++;
								break;
							}
							num++;
						}
					}
					if(num==1)
					{
						return true;
					}
				}
			}
			else if(map.get(item)==Type.horse&&!item.equals(tmpP))
			{
				//往上跳
				if(tmpP.x==item.x-1&&tmpP.y==item.y+2||tmpP.x==item.x+1&&tmpP.y==item.y+2)
				{
					if(!map.containsKey(new Point(item.x,item.y+1)))
					{
						return true;
					}
				}
				//往左跳
				else if(tmpP.x==item.x-2&&tmpP.y==item.y+1||tmpP.x==item.x-2&&tmpP.y==item.y-1)
				{
					if(!map.containsKey(new Point(item.x-1,item.y)))
					{
						return true;
					}
				}
				//往下跳
				else if(tmpP.x==item.x-1&&tmpP.y==item.y-2||tmpP.x==item.x+1&&tmpP.y==item.y-2)
				{
					if(!map.containsKey(new Point(item.x,item.y-1)))
					{
						return true;
					}
				}
				//往右跳
				else if(tmpP.x==item.x+2&&tmpP.y==item.y+1||tmpP.x==item.x+2&&tmpP.y==item.y-1)
				{
					if(!map.containsKey(new Point(item.x+1,item.y)))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		String input=in.nextLine();
		
		ArrayList<String> result = new ArrayList<String>();
		while(!input.equals("0 0 0"))
		{
			String characters[] = input.split(" ");
			int lineNum =Integer.parseInt(characters[0]);
			BlackGp=new Point(Integer.parseInt(characters[1]),Integer.parseInt(characters[2]));
			while(lineNum!=0)
			{
				lineNum--;
				input=in.nextLine();
				characters=input.split(" ");
				Point newP=new Point(Integer.parseInt(characters[1]),Integer.parseInt(characters[2]));
				list.add(newP);
				if(characters[0].equals("G"))
					map.put(newP, Type.redgeneral);
				else if(characters[0].equals("R"))
					map.put(newP, Type.chariot);
				else if(characters[0].equals("H"))
					map.put(newP, Type.horse);
				else if(characters[0].equals("C"))
					map.put(newP, Type.cannon);
			}
			
			boolean flag = false;
			//直接吃
			for (Point item:list)
			{
				if(map.get(item)==Type.redgeneral&&item.y==BlackGp.y)
				{
					boolean flag2 =false;
					for(Point item2:list)
					{
						if(item2.y==item.y&&(item2.x<item.x&&item2.x>BlackGp.x))
						{
							flag2=true;
							break;
						}
					}
					if(!flag2)
					{
						result.add("NO");
						flag=true;
					}
				}
				
			}
			
			//往上
			if(BlackGp.x!=1&&!flag)
			{
				if(!win(new Point(BlackGp.x-1,BlackGp.y)))
				{
					System.out.println("NO");
					//result.add("NO");
					flag=true;
				}
			}
			//往左
			if(BlackGp.y!=4&&!flag)
			{
				if(!win(new Point(BlackGp.x,BlackGp.y-1)))
				{
					System.out.println("NO");
					//result.add("NO");
					flag=true;
				}
			}
			//往下
			if(BlackGp.x!=3&&!flag)
			{
				if(!win(new Point(BlackGp.x+1,BlackGp.y)))
				{
					System.out.println("NO");
					//result.add("NO");
					flag=true;
				}
			}
			//往右
			if(BlackGp.y!=6&&!flag)
			{
				if(!win(new Point(BlackGp.x,BlackGp.y+1)))
				{
					System.out.println("NO");
					//result.add("NO");
					flag=true;
				}
			}
			if(!flag)
				System.out.println("YES");
				//result.add("YES");
			
			//if(result.size()==362)
				//System.out.println(list);
			
			map = new HashMap<Point,Type>();
			list = new ArrayList<Point>();
			in.nextLine();
			input=in.nextLine();
		}
//		for(String i:result)
//		{
//			System.out.println(i);
//		}
	}

}
