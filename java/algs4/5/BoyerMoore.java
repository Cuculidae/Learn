/*
 *
 *
 * Execution:       java BoyerMoore pattern text
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-04-30
 */
public class BoyerMoore
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int R;
    private int[] right;
    private String pat;
    private char[] pattern;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public BoyerMoore(String pat)
    {
        R = 256;
        this.pat = pat;
        right = new int[R];
        for (int c = 0; c < R; ++c)
            right[c] = -1;
        int M = pat.length();
        for (int i = 0; i < M; ++i)
            right[pat.charAt(i)] = i;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public int search(String txt)
    {
        int M = pat.length();
        int N = txt.length();

        int skip;
        for (int i = 0; i <= N - M; i += skip)
        {
            skip = 0;
            for (int j = M-1; j >= 0; --j)
                if (pat.charAt(j) != txt.charAt(i+j))
                {
                    skip = Math.max(1, j - right[txt.charAt(i+j)]);
                    break;
                }
            if (skip == 0) return i;
        }
        return N;
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the BoyerMoore data type
    public static void main(String[] args)
    {
        String pat = args[0];
        String txt = args[1];

        BoyerMoore bm = new BoyerMoore(pat);
        int offset = bm.search(txt);
        StdOut.println("text:    " + txt);
        StdOut.print("pattern: ");
        for (int i = 0; i < offset; ++i)
            StdOut.print(" ");
        StdOut.println(pat);
    }
}