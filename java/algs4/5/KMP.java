/*
 *
 *
 * Execution:       java KMP pattern text
 *                  % java KMP abracadabra abacadabrabracabracadabrabrabracad
 *                  text:    abacadabrabracabracadabrabrabracad 
 *                  pattern:               abracadabra          
 *                
 *                  % java KMP rab abacadabrabracabracadabrabrabracad
 *                  text:    abacadabrabracabracadabrabrabracad 
 *                  pattern:         rab
 *                
 *                  % java KMP bcara abacadabrabracabracadabrabrabracad
 *                  text:    abacadabrabracabracadabrabrabracad 
 *                  pattern:                                   bcara
 *                
 *                  % java KMP rabrabracad abacadabrabracabracadabrabrabracad 
 *                  text:    abacadabrabracabracadabrabrabracad
 *                  pattern:                        rabrabracad
 *                
 *                  % java KMP abacad abacadabrabracabracadabrabrabracad
 *                  text:    abacadabrabracabracadabrabrabracad
 *                  pattern: abacad
 *
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-04-30
 */
public class KMP
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int R;    // the radix
    private int[][] dfa;    // the KMP automoton
    private String pat;     // either the pattern string
    private char[] pattern; // or the char array for the pattern


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Create a DFA from a pattern string
     * @param pat the pattern
     */
    public KMP(String pat)
    {
        this.R = 256;
        this.pat = pat;

        // build DFA from pattern
        int M = pat.length();
        dfa = new int[R][M];
        dfa[pat.charAt(0)][0] = 1;
        for (int x = 0, j = 1; j < M; ++j)
        {
            for (int c = 0; c < R; ++c)
                dfa[c][j] = dfa[c][x];      // copy mismatch cases
            dfa[pat.charAt(j)][j] = j+1;    // set match case
            x = dfa[pat.charAt(j)][x];      // update the restart state
        }
    }

    // create the DFA from a character array over R-character alphabet
    public KMP(char[] pattern, int R) {
        this.R = R;
        this.pattern = new char[pattern.length];
        for (int j = 0; j < pattern.length; j++)
            this.pattern[j] = pattern[j];

        // build DFA from pattern
        int M = pattern.length;
        dfa = new int[R][M]; 
        dfa[pattern[0]][0] = 1; 
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++) 
                dfa[c][j] = dfa[c][X];     // Copy mismatch cases. 
            dfa[pattern[j]][j] = j+1;      // Set match case. 
            X = dfa[pattern[j]][X];        // Update restart state. 
        } 
    } 


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Return offset of first match; N if no match.
     * @param txt the text to be search
     * @return the offset of first match; N if no mismatch
     */
    public int search(String txt)
    {
        int M = pat.length();
        int N = txt.length();
        int i, j;
        for (i = j = 0; i < N && j < M; ++i)
            j = dfa[txt.charAt(i)][j];
        if (j == M) return i-M;
        return N;
    }


    // return offset of first match; N if no match
    public int search(char[] text) {

        // simulate operation of DFA on text
        int M = pattern.length;
        int N = text.length;
        int i, j;
        for (i = 0, j = 0; i < N && j < M; i++) {
            j = dfa[text[i]][j];
        }
        if (j == M) return i - M;    // found
        return N;                    // not found
    }


    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit-test the KMP data type
    public static void main(String[] args)
    {
        String pat = args[0];
        String txt = args[1];

        KMP kmp = new KMP(pat);
        int offset = kmp.search(txt);
        StdOut.println("text:    " + txt);
        StdOut.print("pattern: ");
        for (int i = 0; i < offset; ++i)
            StdOut.print(" ");
        StdOut.println(pat);
    }
}