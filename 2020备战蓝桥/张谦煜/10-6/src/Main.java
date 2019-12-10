import java.util.*;
public class Main {

	static ArrayList<Integer> prime = new ArrayList<Integer>();
	static ArrayList<Integer> reduce = new ArrayList<Integer>();
	
	
	public static void main(String[] args) {
		prime.add(2);
		for(int i = 3;i<=1993;i++)
		{
			prime.add(i);
			int j;
			for(j = 2;j<=Math.sqrt(i);j++)
			{
				if(i%j==0)
				{
					prime.remove(prime.size()-1);
					break;
				}
					
			}
			if(j==(int)Math.sqrt(i)+1)
				reduce.add(prime.get(prime.size()-1)-prime.get(prime.size()-2));
		}
		int tmp=0;
		int result=0;
		int minindex =0;
//		for(int item:reduce)
//		{
//			if(tmp==1898)
//			{
//				result++;
//				tmp-=reduce.get(minindex++);
//			}
//			else if(tmp>1898)
//			{
//				tmp-=reduce.get(minindex++);
//				if(tmp==1898)
//					result++;
//			}
//			tmp+=item;
//		}
		for(int i = 0;i<reduce.size();i++)
		{
			tmp=reduce.get(i);
			for(int j=i+1;j<reduce.size();j++)
			{
				tmp+=reduce.get(j);
				if(tmp==1898)
				{
					result++;
					break;
				}
				else if(tmp>1898)
				{
					break;
				}
			}
		}
		System.out.println(result);

	}

}
