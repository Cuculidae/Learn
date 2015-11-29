/*
 * The Alphabet class is a data type for alphabets, for use with string-processing code
 * that must convert between an alphabet of size R and the integers 0 through R-1.
 * Warning: supports only the basic multilingual plane (BMP), i.e,
 *          Unicode characters between U+0000 and U+FFFF.
 *
 * Execution:       java Alphabet
 *                  NowIsTheTimeForAllGoodMen
 *                  AACGAACGGTTTACCCCG
 *                  01234567890123456789
 * Dependencies:    StdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-07-12
 */
public class Alphabet
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    public static final Alphabet BINARY         = new Alphabet("01");
    public static final Alphabet OCTAL          = new Alphabet("01234567");
    public static final Alphabet DECIMAL        = new Alphabet("0123456789");
    public static final Alphabet HEXADECIMAL    = new Alphabet("0123456789ABCDEF");
    public static final Alphabet DNA            = new Alphabet("ACTG");
    public static final Alphabet LOWERCASE      = new Alphabet("abcdefghijklmnopqrstuvwxyz");
    public static final Alphabet UPPERCASE      = new Alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    public static final Alphabet PROTEIN        = new Alphabet("ACDEFGHIKLMNPQRSTVWY");
    public static final Alphabet BASE64         = new Alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
    public static final Alphabet ASCII          = new Alphabet(128);
    public static final Alphabet EXTENDED_ASCII = new Alphabet(256);
    public static final Alphabet UNICODE16      = new Alphabet(65536);

    private final char[] alphabet;  // the characters in the alphabet
    private final int[] inverse;    // indices
    private final int R;            // the radix of the alphabet

    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    // Creat a new alphabet from sequence of characters in string.
    public Alphabet(String alpha)
    {
        // check that alphabet contains no duplicate chars
        boolean mark[] = new boolean[Character.MAX_VALUE];
        for (int i = 0; i < alpha.length(); ++i) {
            char c = alpha.charAt(i);
            if (mark[c])
                throw new IllegalArgumentException("Illegal Alphabet: repeated character = '" + c + "'");
            mark[c] = true;
        }

        alphabet = alpha.toCharArray();
        R = alpha.length();
        inverse = new int[Character.MAX_VALUE];
        for (int i = 0; i < inverse.length; ++i)
            inverse[i] = -1;

        // can't use char since R can be as big as 65,535
        for (int c = 0; c < R; ++c)
            inverse[alphabet[c]] = c;
    }

    // Creat a new alphabet of Unicode chars 0 to R-1
    private Alphabet(int R)
    {
        alphabet = new char[R];
        inverse = new int[R];
        this.R = R;
        for (int i = 0; i < R; ++i)
        {
            alphabet[i] = (char) i;
            inverse[i]  = i;
        }
    }

    // Create a new Alphabet of Unicode chars 0 to 255 (extended ASCII)
    public Alphabet() { this(256);  }

    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    // Is character c in the alphabet
    public boolean contains(char c) {   return inverse[c] != -1;    }

    // Returns radix R
    public int R() {    return R;   }

    // Returns the number of bits to represents an index
    public int lgR()
    {
        int lgR = 0;
        for (int t = 1; t <= R; t <<= 1)
            lgR++;
        return lgR;
    }
    
    // Convert c to index between 0 and R-1
    public int toIndex(char c)
    {
        if (c < 0 || c >= inverse.length || inverse[c] == -1)
            throw new IllegalArgumentException("Character " + c + " not in alphabet[index];");
        return inverse[c];
    }

    // Convert String s over this alphabet into a base-R int array
    public int[] toIndices(String s)
    {
        int[] target = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            target[i] = inverse[s.charAt(i)];
        }
        return target;
    }

    // Convert an index between 0 and R-1 into a char over this alphabet
    public char toChar(int index)
    {
        if (index < 0 || index >= R) {
            throw new IndexOutOfBoundsException("Alphabet index out of bounds");
        }
        return alphabet[index];
    }

    // Convert base-R integer into a String over this alphabet
    public String toChars(int[] indices)
    {
        StringBuilder s = new StringBuilder(indices.length);
        for (int i = 0; i < indices.length; ++i)
            s.append(alphabet[indices[i]]);
        return s.toString();
    }

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Unit test the Alphabet data type
    public static void main(String[] args)
    {
        int[]  encoded1 = Alphabet.BASE64.toIndices("NowIsTheTimeForAllGoodMen");
        String decoded1 = Alphabet.BASE64.toChars(encoded1);
        StdOut.println(decoded1);
 
        int[]  encoded2 = Alphabet.DNA.toIndices("AACGAACGGTTTACCCCG");
        String decoded2 = Alphabet.DNA.toChars(encoded2);
        StdOut.println(decoded2);

        int[]  encoded3 = Alphabet.DECIMAL.toIndices("01234567890123456789");
        String decoded3 = Alphabet.DECIMAL.toChars(encoded3);
        StdOut.println(decoded3);
    }
}