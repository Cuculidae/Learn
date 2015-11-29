/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-
 */
public class LZW
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int R = 256;   // number of input chars
    private static final int L = 4096;  // number of codewords = 2^W
    private static final int W = 12;    // codeword width


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private LZW() {}    // This class should not been instantiated


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public static void compress()
    {
        String input = BinaryStdIn.readString();
        TST<Integer> st = new TST<Integer>();
        for (int i = 0; i < R; ++i)
            st.put("" + (char) i, i);
        int code = R+1; // R is codeword for EOF

        while (input.length() > 0) {
            String s = st.longestPrefixOf(input);   // find max prefix match s
            BinaryStdOut.write(st.get(s), W);       // print s's encoding
            int t = s.length();
            if (t < input.length() && code < L)     // add s to symbol table
                st.put(input.substring(0, t+1), code++);
            input = input.substring(t);
        }
        BinaryStdOut.write(R, W);
        BinaryStdOut.close();
    }

    public static void expand()
    {
        String[] st = new String[L];
        int i; // next available code

        // initialize symbol table with all 1-Character strings
        for (i = 0; i < R; ++i)
            st[i] = "" + (char) i;
        st[i++] = "";   // (unused) lookahead for EOF

        int codeword = BinaryStdIn.readInt(W);
        if (codeword == R) return;  // expanded message is empty string
        String val = st[codeword];

        while (true) {
            BinaryStdOut.write(val);
            codeword = BinaryStdIn.readInt(W);
            if (codeword == R) break;
            String s = st[codeword];
            if (i == codeword) s = val + val.charAt(0); // special case hack
            if (i < L) st[i++] = val + s.charAt(0);
            val = s;
        }
        BinaryStdOut.close();
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        if      (args[0].equals("-")) compress();
        else if (args[0].equals("+")) expand();
        else throw new IllegalArgumentException("Illegal command line argument");
    }
}