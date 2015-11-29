/*
 *
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-05-03
 */

import java.math.BigInteger;
import java.util.Random;

public class RabinKarp
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private final int R;    // radix
    private int M;          // pattern length
    private long Q;         // a large prime, small enough to avoid long
    private String pat;     // the pattern // needed only for Las Vegas
    private long pathash;   // pattern hash value
    private long RM;        // R^(M-1) % Q


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    public RabinKarp(String pat)
    {
        this.pat = pat; // save pattern (needed only for Las Vegas)
        R = 256;
        Q = longPrime();
        M = pat.length();
        
        RM = 1;
        for (int i = 1; i < M; ++i)
            RM = (R * RM) % Q;
        pathash = hash(pat, M);
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // Compute hash for key[0..M-1]
    private long hash(String key, int M)
    {
        long h = 0;
        for (int i = 0; i < M; ++i)
            h = (R*h + key.charAt(i)) % Q;
        return h;
    }

    // a random 31-bit prime
    private static long longPrime()
    {
        BigInteger prime = BigInteger.probablePrime(31, new Random());
        return prime.longValue();
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public int search(String txt)
    {
        int N = txt.length();
        if (N < M) return N;
        long txthash = hash(txt, M);
        if (txthash == pathash) return 0;
        for (int i = M; i < N; ++i)
        {
            // Remove leading digit, and trailing digit, check for match
            txthash = (txthash + Q - RM*txt.charAt(i-M) % Q) % Q; 
            txthash = (txthash*R + txt.charAt(i)) % Q; 
            if (txthash == pathash) return i-M+1;
        }
        return N;
    }


    /*********************************************************************************************
     *                                       Iterator                                            *
     *********************************************************************************************/
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        String pat = args[0];
        String txt = args[1];

        RabinKarp rk = new RabinKarp(pat);
        int offset = rk.search(txt);
        StdOut.println("text:    " + txt);
        StdOut.print("pattern: ");
        for (int i = 0; i < offset; ++i)
            StdOut.print(" ");
        StdOut.println(pat);
    }
}