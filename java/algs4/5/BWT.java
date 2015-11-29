/*
 * Burrows-Wheeler Transform
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-08-19
 */

import java.util.Arrays;

public class BWT
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int CUTOFF = 10;
    private static final int BLOCK_SIZE = 0x00010000;
    private static final int R = 256;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // return character in offset d of rotations start at index i, or -1 indicating the end
    private static int charAt(char[] T, int i, int d)
    {   return (d == T.length) ? -1 : T[(i + d) % T.length];   }
    private static int cmp(char[] T, int i, int j, int d)
    {
        int x = charAt(T, i, d), y = charAt(T, j, d);
        while (x != -1 && x == y) {
            ++d;
            x = charAt(T, i, d);
            y = charAt(T, j, d);
        }
        return x - y;
    }

    // exchange two rotations of the original text
    private static void exch(int[] R, int i, int j)
    {
        int t = R[i]; R[i] = R[j]; R[j] = t;
    }
    // insertion sort
    private static void insertion(char[] T, int[] R, int lo, int hi, int d)
    {
        for (int i = lo+1; i <= hi; ++i)
            for (int j = i; j > lo && cmp(T, R[j], R[j-1], d) < 0; --j)
                exch(R, j, j-1);
    }
    // quick3way string sort
    private static void sort(char[] T, int[] R, int lo, int hi, int d)
    {
        if (hi <= lo+CUTOFF) {
            insertion(T, R, lo, hi, d);
            return;
        }

        int lt = lo, gt = hi;
        int v = charAt(T, R[lo], d);
        int i = lo+1;
        
        while (i <= gt) {
            int t = charAt(T, R[i], d);
            if      (t < v) exch(R, lt++, i++);
            else if (t > v) exch(R, i, gt--);
            else ++i;
        }
        // a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]
        sort(T, R, lo, lt-1, d);
        if (v >= 0) sort(T, R, lt, gt, d+1);
        sort(T, R, gt+1, hi, d);
    }

    private static void fBWT(char[] T)
    {
        int N = T.length;
        // index of first column F
        int[] R = new int[N];
        for (int i = 0; i < N; ++i)
            R[i] = i;

        // sorting
        sort(T, R, 0, N-1, 0);

        // output the row num of original text 
        for (int i = 0; i < N; ++i)
            if (R[i] == 0) {
                BinaryStdOut.write(i);
                break;
            }

        // output last column F
        for (int i = 0; i < N; ++i)
            BinaryStdOut.write(T[(R[i] == 0) ? N-1 : R[i]-1]);
        BinaryStdOut.flush();
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public static void fBWT()
    {
        char[] T = new char[BLOCK_SIZE];
        while (!BinaryStdIn.isEmpty())
        {
            int i;
            for (i = 0; i < BLOCK_SIZE && !BinaryStdIn.isEmpty(); ++i)
                T[i] = BinaryStdIn.readChar();
            if (i != BLOCK_SIZE) T = Arrays.copyOfRange(T, 0, i);
            fBWT(T);
        }
        BinaryStdOut.close();
    }

    // reverse BWT
    public static void rBWT()
    {
        char[] L = new char[BLOCK_SIZE];

        while (!BinaryStdIn.isEmpty())
        {
            int a = BinaryStdIn.readInt();
            int i;
            for (i = 0; i < BLOCK_SIZE && !BinaryStdIn.isEmpty(); ++i)
                L[i] = BinaryStdIn.readChar();
            
            int[] K = new int[R];
            int[] C = new int[i];
            for (int j = 0; j < i; ++j) {
                C[j] = K[L[j]];
                ++K[L[j]];
            }

            int[] M = new int[R];
            for (int c = 1; c < R; ++c)
                M[c] = M[c-1] + K[c-1];
            
            int[] W = new int[i];
            for (int j = 0; j < i; ++j) {
                W[M[L[j]]] = j;
                M[L[j]] += 1;
            }

            for (int j = 0, k = W[a]; j < i; ++j) {
                BinaryStdOut.write(L[k]);
                k = W[k];
            }
        }
        BinaryStdOut.close();
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        if      (args[0].equals("-")) fBWT();
        else if (args[0].equals("+")) rBWT();
    }
}