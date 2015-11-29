public class CmpOfShell
{
	private static boolean less(Comparable a, Comparable b)
	{	return a.compareTo(b) < 0;	} 
	private static void exch(Comparable[] a, int i, int j)
	{
		Comparable tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	public static void sort(Comparable[] a)
	{
		int N = a.length;
		int h = 1;
		while (h < N/3)
			h = h*3 + 1;	// 1, 4, 13, 121, 364, 1093...
		StdOut.println("**********|***************|");
		while (h >= 1)
		{
			int ncmp = 0;
			for (int i = h; i < N; i++)
			{
				for (int j = i; j >= h ; j -= h)
					if (less(a[j], a[j-h]))
					{
						exch(a, j, j - h);
						ncmp++;
					}
			} 
			StdOut.printf("%10d|%15d|\n", h, ncmp);
			StdOut.println("**********|***************|");
			h /= 3;
		}
	}
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		Double[] d = new Double[N];
		for (int i = 0; i < N; i++)
			d[i] = StdRandom.uniform();
		sort(d);
	}
}