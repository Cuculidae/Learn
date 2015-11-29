/*
 *
 *  The Insertion class provides static methods for sorting an
 *  array using insertion sort.
 *  For additional documentation, see <href="http://algs4.cs.princeton.edu/21elementary">
 *
 * Execution:		java Insertion N
 * Dependencies:	StdOut.java, StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-05
 */
 public class Insertion
 {
	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Insertion() {} // This class should not bean instantiated


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
		for (int i = 1; i < a.length; i++)
			for (int j = i; j > 0 && less(a[j], a[j-1]); j--)
				exch(a, j, j-1);
	}


	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the selection sort algorithm
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