/*
 * The QuickX class provides static methods for sorting an
 * array using an optimized version of quicksort (using Bentley-McIlroy
 * 3-way partitioning, Tukey's ninther, and cutoff to insertion sort).
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/21elementary">
 * Reference: Engineering a Sort Function by Jon L. Bentley
 * and M. Douglas McIlroy. Softwae-Practice and Experience,
 * Vol. 23 (11), 1249-1265 (November 1993).
 *
 * Execution:       java Quick3way N
 * Dependencies:    StdOut.java, StdRandom.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-02-04
 */
 public class QuickX
 {
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 8;    // cutoff to insertion sort, must be >= 1


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private QuickX() {}; // This class should not bean instantiated


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // is a < b ?
    private static boolean less(Comparable a, Comparable b) {   return a.compareTo(b) < 0;  }
    // does v == w ?
    private static boolean eq(Comparable v, Comparable w) { return (v.compareTo(w) == 0);   }
    // swaps a[i] and a[j]
    private static void exch(Comparable[] a, int i, int j)
    {   Comparable t = a[i]; a[i] = a[j]; a[j] = t; }
    // is the array sorted ?
    private static boolean isSorted(Comparable[] a)
    {
        for (int i = 1; i < a.length; i++)
            if (less(a[i], a[i-1]))
                return false;
        return true;
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
    // return the index of the median element among a[i], a[j], and a[k]
    private static int median3(Comparable[] a, int i, int j, int k) {
        return (less(a[i], a[j]) ?
               (less(a[j], a[k]) ? j : less(a[i], a[k]) ? k : i) :
               (less(a[k], a[j]) ? j : less(a[k], a[i]) ? k : i));
    }
    // quicksort the subarray a[lo...hi] using 3-way partitioning
    private static void sort(Comparable[] a, int lo, int hi) { 
        int N = hi - lo + 1;
        // cutoff to insertion sort
        if (N<= CUTOFF) {
            insertionSort(a, lo, hi);
            return;
        }else if (N <= 40) {  // use median-of-3 as partitioning element
            int m = median3(a, lo, lo + N/2, hi);
            exch(a, m, lo);
        }else  { // use Tukey ninther as partitioning element
            int eps = N/8;
            int mid = lo + N/2;
            int m1 = median3(a, lo, lo + eps, lo + eps + eps);
            int m2 = median3(a, mid - eps, mid, mid + eps);
            int m3 = median3(a, hi - eps - eps, hi - eps, hi); 
            int ninther = median3(a, m1, m2, m3);
            exch(a, ninther, lo);
        }
        // Bentley-McIlroy 3-way partitioning
        int i = lo, j = hi+1;
        int p = lo, q = hi+1;
        Comparable v = a[lo];
        while (true) {
            while (less(a[++i], v) && i < hi);
            while (less(v, a[--j]));    // v as a sentinel
            if (i == j) exch(a, ++p, i);
            if (i >= j) break;
            exch(a, i, j);
            if (eq(a[i], v)) exch(a, ++p, i);
            if (eq(a[j], v)) exch(a, --q, j);
        }
        i = j + 1;
        for (int k = lo; k <= p; k++) exch(a, k, j--);
        for (int k = hi; k >= q; k--) exch(a, k, i++);
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
     public static void sort(Comparable[] a){   sort(a, 0, a.length-1); }


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