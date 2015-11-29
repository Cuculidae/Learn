/*
 * The Quick3wayFast class provides static methods for sorting an
 * array using quicksort with Bently-McIlroy 3-way partitioning.
 *
 * Execution:		java Quick3wayFast N
 * Dependencies:	StdRandom.java, StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-09-06
 */
 public class Quick3wayFast
 {
 	/*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 8;    // cutoff to insertion sort, must be >= 1

	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	private Quick3wayFast() {};	// This class should not bean instantiated


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is a < b ?
	private static boolean less(Comparable a, Comparable b) {	return a.compareTo(b) < 0;	}
	// does v == w ?
    private static boolean eq(Comparable v, Comparable w) { return (v.compareTo(w) == 0);   }
	// swaps a[i] and a[j]
	private static void exch(Comparable[] a, int i, int j)
	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
	// sort from a[lo] to a[hi] using insertion sort
    private static void insertionSort(Comparable[] a, int lo, int hi)
    {
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
		
		// Bently-McIlroy 3-way partitioning
		// int p = lo+1, q = hi;		// a[lo..p-1] == a[q+1..hi] == a[lo]
		// int i = p, j = q;			// a[p..i-1] < a[lo] < a[j+1..q]
		// Comparable v = a[lo];

        int p = lo+1, q = hi;
        int i = p, j = q;
        Comparable v = a[lo];
        while (true) {
            int cmp;
            while (i <= j && (cmp = a[i].compareTo(v)) <= 0) {
            	if (cmp == 0) exch(a, p++, i);
            	++i;
            }
            while (i <= j && (cmp = a[j].compareTo(v)) >= 0) {
            	if (cmp == 0) exch(a, q--, j);
            	--j;
            }
            if (i > j) break;
            exch(a, i++, j--);
        }
        for (int k = lo; k < p; k++) exch(a, k, j--);
        for (int k = hi; k > q; k--) exch(a, k, i++);
        sort(a, lo, j);
        sort(a, i, hi);
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