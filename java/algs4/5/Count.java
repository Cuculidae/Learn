/*
 * Create an alphabet specified on the command line, read in a
 * sequence of characters over that alphabet (ignoring character
 * not in the alphabet), computes the frequency of occurrence of
 * each character, and print out the results.
 *
 * Execution:       java Count ALPHABET_STRING < INPUT
 *                  %  java Count ABCDR < abra.txt 
 *                  A 5
 *                  B 2
 *                  C 1
 *                  D 1
 *                  R 2
 *                
 *                  % java Count 0123456789 < pi.txt
 *                  0 99959
 *                  1 99757
 *                  2 100026
 *                  3 100230
 *                  4 100230
 *                  5 100359
 *                  6 99548
 *                  7 99800
 *                  8 99985
 *                  9 100106
 * Dependencies:    StdIn.java, StdOut.java
 * Data File:       abra.txt, pi.txt
 * Author:          caiguochu
 * Time:            2015-07-12
 */
public class Count
{
    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private Count() {}    // This class should not bean instantiated

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        Alphabet alpha = new Alphabet(args[0]);
        int R = alpha.R();
        int[] count = new int[R];

        String s = StdIn.readAll();
        int N = s.length();
        for (int i = 0; i < N; ++i)
            if (alpha.contains(s.charAt(i)))
                count[alpha.toIndex(s.charAt(i))]++;

        for (int c = 0; c < R; ++c)
            StdOut.println(alpha.toChar(c) + " " + count[c]);
    }
}