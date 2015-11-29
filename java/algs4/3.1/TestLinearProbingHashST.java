public class TestLinearProbingHashST
{
	public static void main(String[] args)
	{
		LinearProbingHashST<String, Integer> st = new LinearProbingHashST<String, Integer>();
		while (!StdIn.isEmpty())
		{
			String s = StdIn.readString();
			st.put(s, 1);
		}
		st.print();
		StdOut.println("\nafter delete(\"C\")");
		st.delete("C");
		st.print();
		if (!st.contains("E")) StdOut.println("false");
	}
}
