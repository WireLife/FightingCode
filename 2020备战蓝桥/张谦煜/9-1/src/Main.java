import java.util.*;

class Stack<T>
{
	private ArrayList<T> stack;
	
	public Stack()
	{
		stack = new ArrayList<T>();
	}
	
	public void Push(T value)
	{
		stack.add(value);
	}
	
	public T Pop()
	{
		T result = stack.get(stack.size()-1);
		stack.remove(stack.size()-1);
		return result;
	}
	
	public boolean IsEmpty()
	{
		return stack.size()==0?true:false;
	}
	
	public int size()
	{
		return stack.size();
	}
	
}

public class Main {
	public static void main(String[] args) {
		Stack<String> sigh = new Stack<String>();
		Stack<Float> number = new Stack<Float>();
		Scanner in = new Scanner(System.in);
		Float a;
		Float b;
		String tmpsigh;
		int depth=0;
		for (String str:in.nextLine().split(" "))
		{	
			if (str.equals("+")||str.equals("-")||str.equals("*")||str.equals("/"))
			{
				sigh.Push(str);
			}
			else
			{
				number.Push(Float.parseFloat(str));
			}
			if (number.size()==2+depth)
			{
				b=number.Pop();
				a=number.Pop();
				tmpsigh = sigh.Pop();
				if (tmpsigh.equals("+"))
					number.Push(a+b);
				else if (tmpsigh.equals("-"))
					number.Push(a-b);
				else if (tmpsigh.equals("*"))
					number.Push(a*b);
				else if (tmpsigh.equals("/"))
					number.Push(a/b);
				depth++;
				
			}
		}
		b=number.Pop();
		a=number.Pop();
		tmpsigh = sigh.Pop();
		if (tmpsigh.equals("+"))
			number.Push(a+b);
		else if (tmpsigh.equals("-"))
			number.Push(a-b);
		else if (tmpsigh.equals("*"))
			number.Push(a*b);
		else if (tmpsigh.equals("/"))
			number.Push(a/b);
		System.out.println(number.Pop());
	}

}
