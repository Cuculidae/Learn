public class Select
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
	public static Comparable select(Comparable[] a, int k)
	{
		if (k < 0 || k >= a.length) throw new IndexOutOfBoundsException();
//		StdRandom.shuffle(a);
		int lo = 0, hi = a.length - 1;
		while (hi > lo)
		{
			int j = partition(a, lo, hi);
			if	(j == k) return a[k];
			else if (j > k)  hi = j - 1;
			else  		 lo = j + 1;
		}
		return a[k];
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
