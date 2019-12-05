import java.util.*;
public class Main {

	static boolean f(int k,int x)
	{
		if(k>100000)
		{
			//System.out.println("NO");
			return false;
		}
		else if(k==x)
			return true;
		else
		{
			if(f(2*k+1,x)||f(3*k+1,x))
				return true;
			else
				return false;
		}
	}
	
	public static void main(String[] args) {
		int k,x;
		Scanner in = new Scanner(System.in);
		String tmpin[] = in.nextLine().split(",");
		k=Integer.parseInt(tmpin[0]) ;
		x=Integer.parseInt(tmpin[1]);
		if(f(k,x))
			System.out.println("YES");
		else
			System.out.println("NO");
	}

}
