/*
 *
 *
 * Execution:		java Shell
 * Dependencies:	StdRandom.java, StdOut.java
 * Data File:		Node
 * Author:			caiguochu
 * Time:			20a5-02-11
 */

public class Shell
{
	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Shell() {} // This class should not bean instatiated

	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is a less than b ?
	private static boolean less(Comparable a, Comparable b) {	return a.compareTo(b) < 0;	}
	// swaps a[i] and a[j]
	private static void exch(Comparable[] a, int i, int j)
	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
	// is the array sorted ?
	private static boolean isSorted(Comparable[] a)
	{
		for (int i = 1; i < a.length; i++)
			if (less(a[i], a[i-1]))
				return false;
		return true;
	}

	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	/**
	 * sorts array in ascending order, using the natural order
	 * @param a the array to be sorted
	 */
	public static void sort(Comparable[] a)
	{
		int h = 1, N = a.length;
		while (h <= N/3) h = 3*h + 1; // 1, 4, 13, 40, 121, 364, 1093, 3280...
		while (h >= 1)
		{
			for (int i = h; i < N; i++)
				for (int j = i; j >= h && less(a[j], a[j-h]); j -= h)
					exch(a, j, j-h);
			h /= 3;
		}
	}
	 

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the shell sort algorithm
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		Double[] d = new Double[N];
		for (int i = 0; i < N; i++)
			d[i] = StdRandom.uniform();
		sort(d);
		for (int i = 0; i < N; i++)
			StdOut.printf("%.3f%s", d[i], (i%10==9)?"\n":"\t");
		StdOut.println("\n"+isSorted(d)+"\n");
	}
}