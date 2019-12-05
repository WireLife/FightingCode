import java.util.*;


public class Main {

	static int result=0;
	
	static int getNumber(char c)
	{
		return c-'0';
	}
	
	static void f(String str)
	{
		char basechar=str.charAt(0);
		for(int i=0;i<=getNumber(basechar)/2;i++)
		{
			if (i==0)
				result++;
			else if (i==1)
			{
				result++;
			}
			else
			{
				f(String.valueOf(i)+str);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		f(String.valueOf(n));
		System.out.print(result);
	}

}
