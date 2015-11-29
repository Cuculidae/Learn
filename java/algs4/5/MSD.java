/*
 * Sort a String[] array of N extended ASCII strings (R = 256)
 * Guarantee: ~NW, Average: NlogrN at random input, N+DR extra space.
 *
 * Execution:       java MSD < INPUT
 *                  % java MSD < shells.txt 
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
 * Time:            2015-07-12
 */
public class MSD
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 16;
    private static int R = 256; //extended ASCII alphabet size
    private static String[] aux;

    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private MSD() {}    // This class should not been instantiated.


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // is v less than w, starting at character d ?
    private static boolean less(String v, String w, int d)
    {
        int len = Math.min(v.length(), w.length());
        for (int i=d; i < len; ++i) {
            if (v.charAt(i) < w.charAt(i)) return true;
            if (v.charAt(i) > w.charAt(i)) return false;
        }
        return v.length() < w.length();
    }

    // exchange a[i] and a[j]
    private static void exch(String[] a, int i, int j)
    {
        String tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    // insertion sort a[lo...hi], starting at d-th character 
    private static void insertion(String[] a, int lo, int hi, int d)
    {
        for (int i = lo; i <= hi; ++i)
            for (int j=i; j>lo && less(a[j], a[j-1], d); --j)
                exch(a, j, j-1);
    }

    // returns d-th character of s, -1 if d == length of string
    private static int charAt(String s, int d)
    {
        return (d == s.length()) ? -1 : s.charAt(d);
    }

    // sort from a[lo] to a[hi], starting at the d-th character
    private static void sort(String[] a, int lo, int hi, int d)
    {
        // cutoff to insertion sort for small subarrays
        if (hi <= lo + CUTOFF) {
            insertion(a, lo, hi, d);
            return;
        }

        // compute frequency counts
        int[] count = new int[R+2];
        for (int i=lo; i <= hi; ++i) {
            count[charAt(a[i], d) + 2]++;
        }

        // transform counts to indicies
        for (int r = 0; r < R+1; ++r)
            count[r+1] += count[r];

        // distribute
        for (int i = lo; i <= hi; ++i) {
            aux[count[charAt(a[i], d)+1]++] = a[i];
        }

        // copy back
        for (int i = lo; i <= hi; ++i)
            a[i] = aux[i-lo];

        // recursively sort for each character (excludes sentinel -1)
        for (int r=0; r < R; ++r)
            sort(a, lo+count[r], lo+count[r+1]-1, d+1);
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public static void sort(String[] a)
    {
        int N = a.length;
        aux = new String[N];
        sort(a, 0, N-1, 0);
    }

    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String[] a = StdIn.readAllStrings();
        int N = a.length;
        sort(a);
        for (int i = 0; i < N; i++)
            StdOut.println(a[i]);
    }
}