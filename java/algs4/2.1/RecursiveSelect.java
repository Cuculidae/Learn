public class RecursiveSelect 
{
	private static boolean less(Comparable[] a, int i, int j)
	{	return a[i].compareTo(a[j]) < 0;	}
	private static void exch(Comparable[] a, int i, int j)
	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
	private static int partition(Comparable[] a, int lo, int hi)
	{
		int i = lo, j = hi + 1;
		while (true)
		{
			while (less(a, ++i, lo)) if (i == hi) break;
			while (less(a, lo, --j));
			if (i >= j) break;
			exch(a, i, j);
		}
		exch(a, lo, j);
		return j;
	}
	private static Comparable select(Comparable[] a, int k, int lo, int hi)
	{
		if (hi <= lo) return a[k];
		int j = partition(a, lo, hi);
		if	(j == k) return a[k];
		else if (j > k) return select(a, k, lo, j-1);
		else		return select(a, k, j+1, hi);
	}
	public static Comparable select(Comparable[] a, int k)
	{
		StdRandom.shuffle(a);
		return select(a, k, 0, a.length-1);
	}
	public static void main(String[] args)
	{
		String[] s = In.readStrings();
		Integer[] a = new Integer[s.length];
		for (int i = 0; i < a.length; i++)
			a[i] = Integer.parseInt(s[i]);
		StdOut.println(select(a,(a.length+1)/2 -1)); 
	}
}
