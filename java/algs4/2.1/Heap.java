/* 
 * The Heap class provides a static methods for heapsorting an array.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/24pq">
 *
 * Execution:		java Heap N
 * Dependencies:	StdOut.java, StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-01-28
 */

 public class Heap
 {
	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Heap() {}	// This class should not bean instantiated


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is a less than b ?
	private static boolean less(Comparable a, Comparable b)
	{	return a.compareTo(b) < 0;	}
	// swaps a[i] and a[j]
	private static void exch(Comparable[] a, int i, int j)
	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
	// is tha array sorted ?
	private static boolean isSorted(Comparable[] a)
	{
		for (int i = 1; i < a.length; i++)
			if (less(a[i], a[i-1])) return false;
		return true;
	}
	// swims a[k] up to reheapify a[0...N]
	private static void swim(Comparable[] a, int k)
	{
		while (k > 0 && less(a[(k-1)/2], a[k]))	//a[k]'s father: a[(k-1)/2]
			exch(a, k, k /= 2);
	}
	// sinks a[k] down to reheapify a[0...N]
	private static void sink(Comparable[] a, int k, int N)
	{
		int j;
		while ((j=2*k+1) <= N)	// k<=(N-1)/2 has an exception at N=0
		{	// a[k] has two child: a[2*k+1], a[2*k+2]
			if (j < N && less(a[j], a[j+1])) j++; // biggest of two childs
			if (!less(a[k], a[j])) break;
			exch(a, k, k = j);
		}
	}

	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/

	/**
	 * sorts an array in ascending order, using natural ordering
	 * @param a the array to be sorted
	 */
	public static void sort(Comparable[] a)
	{
		int N = a.length-1;	// last index of the array
		for (int k = (N-1)/2; k >= 0; k--)
			sink(a, k, N);
		while (N > 0)
		{
			exch(a, 0, N--);
			sink(a, 0, N);
		}
	}

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit test the Heap sort method
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