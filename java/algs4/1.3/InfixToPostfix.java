public class InfixToPostfix
{
	public static String infixToPostfix(String str)
	{	//将中缀表达式转换为后缀表达式
		Stack<String> ops = new Stack<String>();
		Stack<String> vals = new Stack<String>();
		String s;
		char ch;
		for (int i = 0; i < str.length(); i++)
		{
			ch = str.charAt(i);
			switch(ch)
			{
				case '+'	:
				case '-'	:
				case '*'	:
				case '/'	:
						ops.push(ch + "");
						break;
				case ')'	:
						s = vals.pop();
						vals.push("( " + vals.pop() + " " + s + " " + ops.pop() +  " ) ");
						break;						
				case ']'	:
						s = vals.pop();
						vals.push("[ " + vals.pop() + " " + s + " " + ops.pop() +  " ] ");
						break;						
				case '}'	:
						s = vals.pop();
						vals.push("{ " + vals.pop() + " " + s + " " + ops.pop() +  " } ");
						break;
				case ' '	:
				case '\t'	:
				case '\n'	:
						break;
				default		:
						if (Character.isDigit(ch))
						{
							s = "";
							while (Character.isDigit(ch))
							{
								s += ch;
								ch = str.charAt(++i);
								if (i == str.length() - 1)
									break;
							}
							vals.push(s);
							if (i == str.length() - 1)
								break;
							i--;
						}
						break;
			}
		}
		return vals.pop();
	}
	public static void main(String[] args)
	{
		String s = StdIn.readAll();
		StdOut.println(infixToPostfix(s));
	}
}
