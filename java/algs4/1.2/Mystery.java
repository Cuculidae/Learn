public class Mystery
{
	public static String mystery(String s)
	{
		int N = s.length();
		if (N <= 1) return s;
		String a = s.substring(0, N/2);
		String b = s.substring(N/2, N);
		return mystery(b) + mystery(a);
	}
	public static void main(String[] args)
	{
		for (int i = 0; i < args.length; i++)
			StdOut.println(mystery(args[i]));
	}
}
