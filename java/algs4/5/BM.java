/*
 *
 *
 * Execution:       java BM pattern text
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-05-02
 */
public class BM
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int R;    // the radix
    private int[] bmBc;       // bad-character shift
    private int[] bmGs;       // good-suffix shift
    private String pat;     // the pattern string


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public BM(String pat)
    {
        R = 256;
        this.pat = pat;
        int M = pat.length();
        bmBc = preBmBc(M);
        bmGs = preBmGs(M);
    }

    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    private int[] preBmBc(int M)
    {
        int[] bmBc = new int[R];
        for (int c = 0; c < R; ++c)
            bmBc[c] = -1;
        for (int i = 0; i < M; ++i)
            bmBc[pat.charAt(i)] = i;
        return bmBc;
    }
    private int[] suffix(int M)
    {
        int[] suff = new int[M];
        suff[M-1] = M;
        for (int i=M-2; i >= 0; --i)
        {
            int j = i;
            while (j >= 0 && pat.charAt(j) == pat.charAt(M-1-i+j))
                --j;
            suff[i] = i - j;
        }
        return suff;
    }
    private int[] preBmGs(int M)
    {
        int[] suffixes = suffix(M);
        int[] bmGs = new int[M];
        for (int i = 0; i < M; ++i)
            bmGs[i] = M;
        for (int i = 0; i < M; ++i) bmGs[i] = M;
        for (int i=M - 2, j=0; i >= 0 && suffixes[i] == i+1; --i)
            if (suffixes[i] == i+1)
                for (; j < M - 1 - i; ++j)
                    if (bmGs[j] == M)
                        bmGs[j] = M - 1 - i;
        for (int i = 0; i < M-1; ++i)
            bmGs[M - 1 - suffixes[i]] = M - 1 - i;
        return bmGs;
    }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public int search(String txt)
    {
        int M = pat.length();
        int N = txt.length();

        for (int i = 0, j, k; i <= N-M; i += Math.max(bmGs[j], j-bmBc[txt.charAt(k)]))
        {
            for (j = M-1, k = i+j; j >= 0 && pat.charAt(j) == txt.charAt(k); --j, --k)
                ;
            if (j < 0) return i;
        }
        return N;
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the BM data type
    public static void main(String[] args)
    {
        String pat = args[0];
        String txt = args[1];

        BM bm = new BM(pat);
        int offset = bm.search(txt);
        StdOut.println("text:    " + txt);
        StdOut.print("pattern: ");
        for (int i = 0; i < offset; ++i)
            StdOut.print(" ");
        StdOut.println(pat);
    }
}