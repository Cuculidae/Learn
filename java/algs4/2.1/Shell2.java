/*
 *
 *
 * Execution:		java Shell2 N
 * Dependencies:	StdRandom.java, StdOut.java
 * Data File:		Node
 * Author:			caiguochu
 * Time:			20a5-09-04
 */

public class Shell2
{
	/*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
	private static int[] incs = {1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929,
							  16001, 36289, 64769, 146305, 260609};

	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Shell2() {} // This class should not bean instatiated

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
		int N = a.length;
		for (int k = incs.length - 1; k >= 0; --k)
		{
			int h = incs[k];
			for (int i = h; i < N; i++)
			{
				int j = i;
				Comparable v = a[j];
				while (j >= h && less(v, a[j-h]))
				{
					a[j] = a[j-h];
					j -= h;
				}
				a[j] = v;
			}
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