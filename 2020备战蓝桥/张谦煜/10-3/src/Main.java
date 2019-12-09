import java.util.*;
public class Main {
	static String str[]= {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
	static int strlen[]= {0,0,3,3,3,3,3,4,3,4};
	static int total=0;
	static ArrayList<Integer> numbers = new ArrayList<Integer>();
	static char output[] = new char[20];
	
	static void f(int index)
	{
		if(index==numbers.size())
		{
			System.out.println(output);
			total++;
			return;
		}
		
		for(int i=0;i<strlen[numbers.get(index)];i++)
		{
			if(numbers.get(index)!=0||numbers.get(index)!=1)
				output[index]=(str[numbers.get(index)].charAt(i));
			f(index+1);
		}
	}
	
	
	public static void main(String[] args) {
		int numberLen;
		Scanner in = new Scanner(System.in);
		numberLen = in.nextInt();
		
		while(numberLen--!=0)
		{
			numbers.add(in.nextInt());
		}
		f(0);
		System.out.println(total);
	}

}
