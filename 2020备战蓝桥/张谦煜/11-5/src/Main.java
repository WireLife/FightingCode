import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String input=in.nextLine();
		Map<Character,Integer> map = new HashMap<Character,Integer>();
		for(char item:input.toCharArray())
		{
			if(map.containsKey(item))
			{
				System.out.print(item);
				System.exit(0);
			}
			else
			{
				map.put(item, 1);
			}
		}
		System.out.print("no");

	}

}
