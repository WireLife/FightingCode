import java.util.*;
public class Main {

	public static void main(String[] args) {
		int peak;
		Scanner in = new Scanner(System.in);
		peak=Integer.parseInt(in.nextLine());
		ArrayList<Integer> top = new ArrayList<Integer>();
		ArrayList<Integer> bottum = new ArrayList<Integer>();
		
		while (peak--!=0)
		{
			String str[] = in.nextLine().split("/");
			top.add(Integer.parseInt(str[0]));
			bottum.add(Integer.parseInt(str[1]));
		}
		int add=bottum.get(0);
		for(int i =1;i<top.size();i++)
		{
			 add*=bottum.get(i);
		}
		for(int i =0;i<top.size();i++)
		{
			top.set(i,add/bottum.get(i)*top.get(i));
			bottum.set(i,add);
		}
		int resulttop=0;
		int resultbottum=bottum.get(0);
		for(int i =0;i<top.size();i++)
		{
			resulttop+=top.get(i);
		}
		for(int i=2;i<resulttop&&i<resultbottum;i++)
		{
			while (resulttop%i==0&&resultbottum%i==0)
			{
				resulttop/=i;
				resultbottum/=i;
			}
		}
		System.out.println(resulttop+"/"+resultbottum);
	}

}
