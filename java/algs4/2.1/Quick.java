/*
 * The Quick class provides static methods for sorting an
 * array and selecting the ith smallest element in an array using quicksort.
 *
 * Execution:		java Quick N
 * Dependencies:	StdRandom.java, StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-01-25
 */
public class Quick
{
	/*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 8;    // cutoff to insertion sort, must be >= 1
    
	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Quick() {}	// This class should not  bean instantiated


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
	// partitions a[lo...hi] by returning index j
	// so that a[lo...j-1] <= a[j] <= a[j+1...hi]
	private static int partition(Comparable[] a, int lo, int hi)
	{
		int i = lo, j = hi+1;
		Comparable pivot = a[lo];
		while (true)
		{
			while (less(pivot, a[--j]));	// a[lo] as a sentinel
			while (i < hi && less(a[++i], pivot));
			if (i >= j)	break;
			exch(a, i, j);
		}
		exch(a, lo, j);
		return j;
	}
	// quicksort the subarray a[lo...hi]
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if (hi <= lo+CUTOFF) {
			insertionSort(a, lo, hi);
			return;
		}
		int j = partition(a, lo, hi);
		sort(a, lo, j-1);
		sort(a, j+1, hi);
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
		StdRandom.shuffle(a);	// random shuffle the array
		sort(a, 0, a.length-1);
	}
	/**
	 * Rearranges the array so that a[k] contains the kth smallest key;
     * a[0] through a[k-1] are less than (or equal to) a[k]; and
     * a[k+1] through a[N-1] are greater than (or equal to) a[k].
     * @param a the array
     * @param k find the kth smallest
	 */
	public static Comparable select(Comparable[] a, int k)
	{
		if (k < 0 || k >= a.length-1)
			throw new IndexOutOfBoundsException("Selected element out of bounds!");
		int j, lo = 0, hi = a.length-1;
		StdRandom.shuffle(a);
		while (hi > lo)
		{
			j = partition(a, lo, hi);
			if      (k > j) lo = j+1;
			else if (k < j) hi = j-1;
			else    return a[j];
		}
		return a[lo];
	}


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
		StdOut.printf("The %dth smallest element is %.3f\n", N/2, select(d, N/2));
		sort(d);
		for (int i = 0; i < N; i++)
			StdOut.printf("%.3f%s", d[i], (i%10==9)?"\n":"\t");
		StdOut.println("\n"+isSorted(d)+"\n");
	}
}