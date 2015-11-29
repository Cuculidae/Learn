/*
 * The Quick3way class provides static methods for sorting an
 * array using quicksort with 3-way partitioning.
 *
 * Execution:		java Quick3way N
 * Dependencies:	StdRandom.java, StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-04
 */
 public class Quick3way
 {
 	/*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 15;    // cutoff to insertion sort, must be >= 1

	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Quick3way() {};	// This class should not bean instantiated


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is a < b ?
	private static boolean less(Comparable a, Comparable b) {	return a.compareTo(b) < 0;	}
	// swaps a[i] and a[j]
	private static void exch(Comparable[] a, int i, int j)
	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
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
	// quicksort the subarray a[lo...hi] using 3-way partitioning
	private static void sort(Comparable[] a, int lo, int hi)
	{
		if (hi <= lo+CUTOFF) {
			insertionSort(a, lo, hi);
			return;
		}
		int lt = lo, i = lo+1, gt = hi;
		Comparable v = a[lo];
		while (i <= gt)
		{
			int cmp = a[i].compareTo(v);
			if      (cmp < 0) exch(a, lt++, i++);
			else if (cmp > 0) exch(a, i, gt--);
			else              i++;
		}
		// a[lo...lt-1] < v = a[lt...gt] < a[gt+1...hi]
		sort(a, lo, lt-1);
		sort(a, gt+1, hi);
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	/**
	 * Rearranges the array in ascending order, using the natural order
	 * @param a the array to be sorted
	 */
	 public static void sort(Comparable[] a) 
	 {
	 	StdRandom.shuffle(a);
	 	sort(a, 0, a.length-1);
	 }


	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the 3-way partitioning quick-sort algorithm
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