import java.util.Arrays;
public class ReadInts
{
	public static int[] readInts(String name)
	{
		String input = StdIn.readAll();
		String[] words = input.split("\\s+");
		int[] ints = new int[words.length];
		for (int i = 0; i < words.length; i++)
			ints[i] = Integer.parseInt(words[i]);
		return ints;
	}
	public static void main(String[] args)
	{
		int[] words = readInts(args[0]);
		StdOut.println(Arrays.toString(words));
	}
}
