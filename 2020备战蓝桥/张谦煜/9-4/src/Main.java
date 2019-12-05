import java.util.*;

public class Main {

	static int f(int n)
	{
		if(n==1)
			return 1;
		else if(n==2)
			return 2;
		return 2*f(n-1)+f(n-2);
	}
	
	public static void main(String[] args) {
		int peak;
		Scanner in = new Scanner(System.in);
		peak=in.nextInt();
		ArrayList<Integer> results = new ArrayList<Integer>();
		while(peak--!=0)
		{
			results.add(f(in.nextInt()));
		}
		for(int item:results)
		{
			System.out.println(item);
		}
	}

}
