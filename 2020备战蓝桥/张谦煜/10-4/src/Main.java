import java.util.*;
public class Main {

	static double h;
	static double result=0;
	static double last;
	
	static void f(int n)
	{
		if(n==0)
		{
			result-=h;
			last = h;
			return;
		}
			
		else
		{
			result+=h+h/2;
			h/=2;
			f(n-1);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		h=in.nextDouble();
		f(in.nextInt());
		System.out.println(result);
		System.out.println(last);

	}

}
