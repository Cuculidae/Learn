/*
 * The bitap algorithm (also known as the shift-or, shift-and, or Baeza-Yates-Gonnet
 * algorithm) is an approximate string matching algorithm. The algorithm tells 
 * whether a given text contains a substring which is "approximately equal" to a 
 * given pattern, where approximate equality is defined in terms of Levenshtein
 * distance -- if the substring and pattern are within a given distance k of each
 * other, then the algorithm considers them equal. The algorithm begins by 
 * precomputing a set of bitmasks containing one bit for each element of the 
 * pattern. Then it is able to do most of the work with bitwise operatioins, which
 * are extremely fast.
 * Notice that in this implementation, conterintuively, each bit with value zero
 * indicates a match, and each bit with value 1 indicates a non-match. The 
 * implementation takes advantage of the fact that left-shifting a value shifts in 
 * zeros on the right, which is precisely the behaviour we need.
 *
 * Execution:       java Bitap PATTERN TEXT
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-08-03
 */
public class Bitap
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CHAR_MAX = 256;
    private int M;
    private long[] pattern_mask;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public Bitap(String pat)
    {
        M = pat.length();
        pattern_mask = new long[CHAR_MAX+1];

        /* Initialize the pattern bitmasks */
        for (int i = 0; i <= CHAR_MAX; ++i)
            pattern_mask[i] = ~0L;
        for (int i = 0; i < M; ++i)
            pattern_mask[pat.charAt(i)] &= ~(1L << i);
    }

    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Exact substring searching in <txt>
     * @param txt the text to be search in
     * @return the index of first match, or N (the end of txt) otherwise
     */
    public int search(String txt)
    {
        int N = txt.length();
        long R = ~1;
        for (int i = 0; i < N; ++i)
        {
            /* Update the bit array */
            R |= pattern_mask[txt.charAt(i)];
            R <<= 1;
            if (0 == (R & (1L << M)))
                return (i - M) + 1;
        }
        return N;
    }

    /**
     * Approximate sring search in <txt> of distance <k> only pay attention to
     * substitutions, not to insertions or deletions -- in other words, a 
     * Hamming distance of k.
     * @param txt the text to be search in
     * @param k the distance
     * @return the first match with up to k errors, or N otherwise
     */
    public int fuzzySearch(String txt, int k)
    {
        int N = txt.length();
        int result = N;
        long[] R;

        /* Initializes the bit array R */
        R = new long[k+1];
        for (int i = 0; i <= k; ++i)
            R[i] = ~1;

        for (int i = 0; i < N; ++i)
        {
            /* Update the bit arrays */
            long old_Rd1 = R[0];

            R[0] |= pattern_mask[txt.charAt(i)];
            R[0] <<= 1;

            for (int d = 1; d <= k; ++d)
            {
                long tmp = R[d];
                /* Substitution is all we care about */
                R[d] = (old_Rd1 & (R[d] | pattern_mask[txt.charAt(i)])) << 1;
                old_Rd1 = tmp;
            }

            if (0 == (R[k] & (1L << M)))
            {
                result = i - M + 1;
                break;
            }
        }

        return result;
    }

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String pat = args[0];
        String txt = args[1];

        Bitap b = new Bitap(pat);
        int offset = b.search(txt);
        StdOut.println("text:    " + txt);
        StdOut.print("pattern: ");
        for (int i = 0; i < offset; ++i)
            StdOut.print(" ");
        StdOut.println(pat);
    }
}