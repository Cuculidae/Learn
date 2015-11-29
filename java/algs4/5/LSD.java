/*
 *
 *
 * Execution:       java LSD < INPUT

 * Dependencies:    StdIn.java, StdOut.java
 * Data File:       words3.txt
 * Author:          caiguochu
 * Time:            2015-07-12
 */
public class LSD
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private LSD() {}    // This class should not bean instantiated


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * LSD radix sort an array of string of the same length
     * @param a the array of string
     * @param W the length of each string in the array
     */
    public static void sort(String[] a, int W)
    {
        int N = a.length;
        int R = 256;    // extend ASCII alphabet size
        String[] aux = new String[N];

        for (int d = W-1; d >= 0; --d) {
            // sort by key-indexed counting on d-th character

            // compute frequency counts
            int[] count = new int[R];
            for (int i = 0; i < N; ++i)
                count[a[i].charAt(d)]++;

            // compute cumulates
            for (int r = 1; r < R; ++r)
                count[r] += count[r-1];

            // move data
            for (int i = N-1; i >= 0; --i)
                aux[--count[a[i].charAt(d)]] = a[i];

            // copy back
            for (int i = 0; i < N; ++i)
                a[i] = aux[i];
        }
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String[] a = StdIn.readAllStrings();
        int N = a.length;

        // check that strings have fixed length
        int W = a[0].length();

        // sort the strings
        sort(a, W);

        // print results
        for (int i = 0; i < N; i++)
            StdOut.println(a[i]);
    }
}