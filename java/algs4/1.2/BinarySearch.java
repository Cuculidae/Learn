import java.util.Arrays;
public class BinarySearch
{
	public static int rank(int key, int a[], Counter counter)
	{
		int lo = 0;
		int hi = a.length - 1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo)/2;
			counter.increment();
			if (key > a[mid])	lo = mid + 1;
			else if (key < a[mid])  hi = mid - 1;
			else			return mid;
		}
		return -1;
	}
	public static void main(String[] args)
	{
		Counter c = new Counter("key check counts");
		int[] a = In.readInts(args[0]);
		Arrays.sort(a);
		while (!StdIn.isEmpty())
		{
			int key = StdIn.readInt();
			if (rank(key, a, c) < 0)
				StdOut.println(key);
		}
		StdOut.println(c);
	}
}
