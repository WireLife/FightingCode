import java.util.*;
public class Main {

	static boolean f(String a)
	{
		String news= a.replace("-", "");
		int right =news.charAt(news.length()-1)-'0';
		news=news.substring(0,news.length()-1);
		int add=1;
		int tmp=0;
		for(char i:news.toCharArray())
		{
			tmp+=(i-'0')*add++;
		}
		return right==tmp%11?true:false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		if(f(in.nextLine()))
			System.out.println("真");
		else
			System.out.println("假");

	}

}
