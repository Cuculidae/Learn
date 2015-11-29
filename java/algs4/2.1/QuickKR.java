/*
 * The QuickKR class provides static methods for sorting an
 * array using a version of quicksort from K&R C.
 * Reference: The C Programming Language by Brian W. Kernighan and
 * Dennis M. Ritchie, p. 87.
 * Warning: goes quadratic if many duplicate keys.
 *
 * Execution:		java QuickKR N
 * Dependencies:	StdOut.java, StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-04
 */
public class QuickKR
{
	/*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 8;    // cutoff to insertion sort, must be >= 1

	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private QuickKR() {}	// This class should not  bean instantiated


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is a less than b ?
	private static boolean less(Comparable a, Comparable b)
	{	return a.compareTo(b) < 0;	}
	// swaps a[i] and a[j]
	private static void exch(Comparable[] a, int i, int j)
	{
		Comparable tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	// sort from a[lo] to a[hi] using insertion sort
    private static void insertionSort(Comparable[] a, int lo, int hi) {
        for (int i = lo+1; i <= hi; i++)
        {
            int j = i;
            Comparable v = a[j];
            while (j > lo && less(v, a[j-1]))
            {
                a[j] = a[j-1];
                --j;
            }
            a[j] = v;
        }
    }
	// is the array sorted ?
	private static boolean isSorted(Comparable[] a)
	{
		for (int i = 1; i < a.length; i++)
			if (less(a[i], a[i-1]))
				return false;
		return true;
	}
	// quicksort the subarray a[lo...hi]
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if (hi <= lo+CUTOFF) {
			insertionSort(a, lo, hi);
			return;
		}
		exch(a, lo, (lo+hi)/2);	// use middle element as pivot
		int last = lo;
		for (int i = lo+1; i <= hi; i++)
			if (less(a[i], a[lo])) exch(a, ++last, i);
		exch(a, last, lo);
		sort(a, lo, last-1);
		sort(a, last+1, hi);
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