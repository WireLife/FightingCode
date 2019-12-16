import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		int result=0;
		for(char item:str.toCharArray())
		{
			if(Character.isDigit(item))
				result++;
		}
		System.out.print(result);
	}

}
