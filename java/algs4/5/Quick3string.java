/*
 * Reads string from standard input and 3-way string quicksort them.
 * ~1.39NlgN at random input, ~1.39WNlgR guarantee, logN+W extra space,
 * not stable.
 *
 * Execution:       java Quick3string < INPUT
 *                  % java Quick3string < shell.txt
 *                  are
 *                  by
 *                  sea
 *                  seashells
 *                  seashells
 *                  sells
 *                  sells
 *                  she
 *                  she
 *                  shells
 *                  shore
 *                  surely
 *                  the
 *                  the
 * Dependencies:    StdIn.java, StdOut.java
 * Data File:       shells.txt
 * Author:          caiguochu
 * Time:            2015-07-13
 */
public class Quick3string
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 16;   // cutoff to insertion sort

    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private Quick3string() {}   // This class should not been instantiated.

    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // return the d-th character of s, -1 if d == length of s
    private static int charAt(String s, int d)
    {
        return (d == s.length()) ? -1 : s.charAt(d);
    }

    // is v less than w, starting at character d
    private static boolean less(String v, String w, int d)
    {
        int len = Math.min(v.length(), w.length());
        for (int i=d; i < len; ++i) {
            if (v.charAt(i) > w.charAt(i)) return false;
            if (v.charAt(i) < w.charAt(i)) return true;
        }
        return v.length() == len;
    }

    // exchange a[i] and a[j]
    private static void exch(String[] a, int i, int j)
    {
        String tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    // sort from a[lo] to a[hi], starting at the d-th character
    private static void insertion(String[] a, int lo, int hi, int d)
    {
        for (int i=lo+1; i<=hi; ++i)
            for (int j=i; j>lo && less(a[j], a[j-1], d); --j)
                exch(a, j, j-1);
    }

    // 3-way string quicksort a[lo...hi] starting at d-th character
    private static void sort(String[] a, int lo, int hi, int d)
    {
        // cutoff to insertion sort for small subarrays
        if (hi <= lo+CUTOFF) {
            insertion(a, lo, hi, d);
            return;
        }

        int lt = lo, gt = hi;
        int v = charAt(a[lo], d);
        int i = lo+1;
        while (i <= gt) {
            int t = charAt(a[i], d);
            if      (t < v) exch(a, lt++, i++);
            else if (t > v) exch(a, gt--, i);
            else            ++i;
        }

        // a[lo...lt-1] < v = a[lt...gt] < a[gt+1...hi]
        sort(a, lo, lt-1, d);
        if (v >= 0) sort(a, lt, gt, d+1);
        sort(a, gt+1, hi, d);
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    // sort the array a[] of strings
    public static void sort(String[] a)
    {
        sort(a, 0, a.length-1, 0);
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        // read in the strings from standard input
        String[] a = StdIn.readAllStrings();
        int N = a.length;

        // sort the strings
        sort(a);

        // print the results
        for (int i = 0; i < N; i++)
            StdOut.println(a[i]);
    }
}