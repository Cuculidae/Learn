public class Test
{
	public static void main(String[] args)
	{
		char c = (char) -1;
		if (c > '\0') StdOut.println("fuck");
		StdOut.println(c);
		StdOut.println((int) c);
	}
}