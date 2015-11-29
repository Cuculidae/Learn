public class Evaluate
{
	public static void main(String[] args)
	{
		Stack<String> ops = new Stack<String>();
		Stack<Double> vals = new Stack<Double>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			switch(s)
			{
				case "("    : break;
				case "+"    :
				case "-"    :
				case "*"    :
				case "/"    :
				case "sqrt" : ops.push(s); break;
				case ")"    : String op = ops.pop();
					      double v = vals.pop();
					      switch(op)
					      {
						 case "+"	 : v = vals.pop() + v; break;
						 case "-"	 : v = vals.pop() - v; break;
						 case "*"	 : v = vals.pop() * v; break;
						 case "/"	 : v = vals.pop() / v; break;
						 case "sqrt"	 : v = Math.sqrt(v);   break;
						 default	 : break;
					      }
					      vals.push(v);
					      break;
				default    : vals.push(Double.parseDouble(s));
			}
		}
		StdOut.println(vals.pop());
	}
}
