import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		int digit=0;
		int upchar=0;
		int lwchar=0;
		int space=0;
		int others=0;
		for(char item:input.toCharArray())
		{
			if(Character.isDigit(item))
				digit++;
			else if (Character.isLowerCase(item))
				lwchar++;
			else if(Character.isUpperCase(item))
				upchar++;
			else if(Character.isWhitespace(item))
				space++;
			else
				others++;
		}
		System.out.println("digit:"+digit);
		System.out.println("upchar:"+upchar);
		System.out.println("lwchar:"+lwchar);
		System.out.println("space:"+space);
		System.out.println("others:"+others);
	}

}
