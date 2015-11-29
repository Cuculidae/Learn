/*
 * The InsertionXB class provides static methods for sorting an
 * array using an optimized version of insertion sort using binary-search method
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/21elementary">
 *
 * Execution:       java InsertionXB N
 * Dependencies:    StdRandom.java, StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-02-19
 */

public class InsertionXB {
    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private InsertionXB() { }    // This class should not be instantiated.


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // is v < w ?
    private static boolean less(Comparable v, Comparable w) {   return v.compareTo(w) < 0;  }  
    // exchange a[i] and a[j]
    private static void exch(Object[] a, int i, int j)
    {   Object swap = a[i]; a[i] = a[j]; a[j] = swap;    }
    // is array a sorted ?
    private static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i-1])) return false;
        return true;
    }
    // number of keys less than v
    private static int rank( Comparable v, Comparable[] a, int lo, int hi)
    {
        int mid, cmp;
        while (lo <= hi)
        {
            mid = (lo+hi)/2;
            cmp = v.compareTo(a[mid]);
            if      (cmp > 0) lo = mid+1;
            else if (cmp < 0) hi = mid-1;
            else              return mid;
        }
        return lo;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Rearranges the array in ascending order, using the natural order.
     * @param a the array to be sorted
     */
    public static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 1; i < N; i++) {
            Comparable v = a[i];
            int j = rank(a[i], a, 0, i-1);
            for (int k = i-1; k >= j; k--) a[k+1] = a[k];
            a[j] = v;
        }
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the optimised insertion sort algorithm
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
