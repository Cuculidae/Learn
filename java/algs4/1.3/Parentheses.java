public class Parentheses
{
	public static boolean isBalanced(String s)
	{
		Stack<Character> c = new Stack<Character>();
		char ch;
		for (int i = 0; i < s.length(); i++)
		{
			ch = s.charAt(i);
			switch(ch)
			{
				case '(':
				case '[':
				case '{':
					c.push(ch);
					break;
				case ')':
					if (c.pop() != '(')
						return false;
					break;
				case ']':
					if (c.pop() != '[')
						return false;
					break;
				case '}':
					if (c.pop() != '{')
						return false;
					break;
				default:
					break;
			}
		}
		return true;
	}
	public static String complete(String str)
	{	//²¹È«À¨ºÅ
		Stack<String> ops = new Stack<String>();
		Stack<String> vals = new Stack<String>();
		char ch;
		String s;
		for (int i = 0; i < str.length(); i++)
		{
			ch = str.charAt(i);
			switch (ch)
			{
				case '+'	:
				case '-'	:
				case '*'	:
				case '/'	:
						ops.push(ch + "");
						break;
				case ')'	:
				case ']'	:
				case '}'	:
						s = vals.pop();
						vals.push("( " + vals.pop() + " " + ops.pop() + " " + s + " ) ");
						break;
				case '\t'	:
				case ' '	:
				case '\n'	:
						break;
				default		:
						if (Character.isDigit(ch))
								vals.push(ch + "");
						break;
			}
		}
		return vals.pop();
	}
	public static void main(String[] args)
	{
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readAll();
			StdOut.println(complete(s));
		}
	}
}
