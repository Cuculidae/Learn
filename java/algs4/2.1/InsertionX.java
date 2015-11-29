/*
 * The InsertionX class provides static methods for sorting an
 * array using an optimized version of insertion sort (with half exchanges
 * and a sentinel).
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/21elementary">
 *
 * Execution:       java InsertionX N
 * Dependencies:    StdRandom.java, StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-02-19
 */

public class InsertionX {
    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private InsertionX() { }    // This class should not be instantiated.


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // is v < w ?
    private static boolean less(Comparable v, Comparable w) {   return v.compareTo(w) < 0;  }  
    // exchange a[i] and a[j]
    private static void exch(Object[] a, int i, int j)
    {   Object swap = a[i]; a[i] = a[j]; a[j] = swap;    }
    // is array a sorted ?
    private static boolean isSorted(Comparable[] a)
    {
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i-1])) return false;
        return true;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Rearranges the array in ascending order, using the natural order.
     * @param a the array to be sorted
     */
    public static void sort(Comparable[] a)
    {
        int N = a.length;
        // put smallest element in position to serve as sentinel
        for (int i = N-1; i > 0; i--)
            if (less(a[i], a[i-1])) exch(a, i, i-1);
        // insertion sort with half-exchanges
        for (int i = 2; i < N; i++) {
            Comparable v = a[i];
            int j = i;
            while (less(v, a[--j])) a[j+1] = a[j];
            a[j+1] = v;
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
