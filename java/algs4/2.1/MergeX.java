/*
 *  The MergeX class provides static methods for sorting an
 *  array using an optimized version of mergesort.
 *  For additional documentation, see <href="http://algs4.cs.princeton.edu/22mergesort">
 *
 * Execution:		java MergeX N
 * Dependencies:	StdOut.java, StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-04
 */
 public class MergeX
 {
 	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
 	private static final int CUTOFF = 8; // cutoff to insertion sort


 	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
 	private MergeX() {};	// This class should not bean instantiated


 	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
 	// is a < b ?
 	private static boolean less(Comparable a, Comparable b) {	return a.compareTo(b) < 0;	}
 	// swaps a[i] and a[j]
 	private static void exch(Comparable[] a, int i, int j)
 	{	Comparable t = a[i]; a[i] = a[j]; a[j] = t;	}
 	// is the array sorted ?
 	private static boolean isSorted(Comparable[] a)
 	{
 		int N = a.length;
 		for (int i = 1; i < N; i++)
 			if (less(a[i],a[i-1]))
 				return false;
 		return true;
 	}
 	// sort a[lo...hi] using insertionsort
 	private static void insertionSort(Comparable[] a, int lo, int hi)
 	{
 		for (int i = lo+1; i <= hi; i++)
 			for (int j = i; j > lo && less(a[j], a[j-1]); j--)
 				exch(a, j, j-1);
 	}
 	// 
 	private static void merge(Comparable[] src, Comparable[] dst, int lo, int mid, int hi)
 	{
 		// Precondition: src[lo...mid] and src[mid+1...hi] are sorted subarrays
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)              while(k<=hi) dst[k++]=src[j++];
            else if (j > hi)               while(k<=hi) dst[k++]=src[i++];
            else if (less(src[j], src[i])) dst[k] = src[j++];   // to ensure stability
            else                           dst[k] = src[i++];
        }
 		// Postcondition: dst[lo...hi] is sorted subarrays
 	}
 	private static void sort(Comparable[] src, Comparable[] dst, int lo, int hi)
 	{
 		// 1. cutoff to insertionsort
 		if (hi <= lo+CUTOFF) {	insertionSort(dst, lo, hi); return;	}
 		int mid = (lo+hi)/2;
 		// 2. avoid the copy by switching arguments in the recursive code
 		sort(dst, src, lo, mid);
 		sort(dst, src, mid+1, hi);
        // 3. test whether the array is already in order   
        if (!less(src[mid+1], src[mid]))
        {	// using System.arraycopy() is a bit faster
            System.arraycopy(src, lo, dst, lo, hi - lo + 1);
            return;
        }
 		merge(src, dst, lo, mid, hi);
 	}


 	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
 	public static void sort(Comparable[] a)
 	{
 		Comparable[] aux = a.clone();
 		sort(aux, a, 0, a.length-1);
 	}
 	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
 	// Unit-test the optimised mergesort algorithm
 	public static void main(String[] args)
 	{
 		int N = Integer.parseInt(args[0]);
 		Double[] d = new Double[N];
 		for (int i = 0; i < N; i++)
 			d[i] = StdRandom.uniform();
 		sort(d);
 		for (int i = 0; i < N; i++)
 			StdOut.printf("%.3f%s", d[i], (i%10==9)?"\n":"\t");
 		StdOut.println("\n"+isSorted(d));
 	}
 }