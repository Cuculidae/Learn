/*
 * The QuickDualPivot class provides static methods for sorting an
 * array using Yaroslavskiy's dual-pivot-quicksort.
 *
 * Execution:		java QuickDualPivot N
 * Dependencies:	StdOut.java, StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-05
 */
public class QuickDualPivot
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 27;    // cutoff to insertion sort, must be >= 1


	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private QuickDualPivot() {}	// This class should not  bean instantiated


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
	// insertion-sort
	private static void insertionSort(Comparable[] a, int lo, int hi)
	{
		for (int i = lo+1; i <= hi; i++)
			for (int j = i; j > lo && less(a[j], a[j-1]); j--)
				exch(a, j, j-1);
	}
	// quicksort the subarray a[lo...hi]
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if (hi <= lo+CUTOFF) {	insertionSort(a, lo, hi); return;	}
		if (less(a[hi], a[lo])) exch(a, lo, hi); // make sure a[lo] <= a[hi]
		int lt = lo+1, gt = hi-1, i = lo+1;
		while (i <= gt)
		{
			if (less(a[i], a[lo]))      exch(a, lt++, i++);
			else if (less(a[hi], a[i])) exch(a, gt--, i);
			else                        i++;
		}
		// a[lo+1...lt-1] < a[lo] <= a[lt...gt] <= a[hi] < a[gt+1...hi-1]
		exch(a, lo, --lt);
		exch(a, hi, ++gt);
		sort(a, lo, lt-1);
		if (less(a[lt], a[gt])) sort(a, lt+1, gt-1);
		sort(a, gt+1, hi);
	}
	

	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	/**
	 * sorts array in ascending order, using the natural order
	 * @param a the array to be sorted
	 */
	public static void sort(Comparable[] a) {	sort(a, 0, a.length-1);	}
	

	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the Quick-sort algorithm
	public static void main(String[] args)
	{
		int N = Integer.parseInt(args[0]);
		Double[] d = new Double[N];
		for (int i = 0; i < N; i++)
			d[i] = StdRandom.uniform();
		d[0] = d[N-1];
		sort(d);
		for (int i = 0; i < N; i++)
			StdOut.printf("%.3f%s", d[i], (i%10==9)?"\n":"\t");
		StdOut.println("\n"+isSorted(d)+"\n");
	}
}