/*
 * Adaptive Arithmetic Coding
 *
 * Execution:       
 * Dependencies:    
 * Data File:       
 * Author:          caiguochu
 * Time:            2015-08-14
 */
public class Arithmetic
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int  R = 256;              // alphabet size
    private static final int  M = 16;               // word length
    private static final char MSB_MASK  = 0x8000;   // MSB mask
    private static final char SMSB_MASK = 0x4000;   // Second MSB mask
    private static final char MAX_COUNT = 0x4000;   // 
    private static final int  INCREMENT = 1;


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/



    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    public static int rank(int[] cumCount, int c)
    {
        // int lo = 0, hi = cumCount.length-1, mid = (lo+hi)/2;
        // int cmp;
        // while (lo <= hi) {
        //     mid = (lo+hi) / 2;
        //     cmp = c - cumCount[mid];
        //     if      (cmp > 0) lo = mid+1;
        //     else if (cmp < 0) hi = mid-1;
        //     else {
        //         while (cumCount[mid] == cumCount[mid-1])
        //             --mid;
        //         return mid;
        //     }
        // }
        // while (cumCount[lo] == cumCount[lo-1]) --lo;
        // return lo;
        int i=0;
        while (c >= cumCount[i])
            ++i;
        return i-1;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public static void compress()
    {
        // cummulate counts of symbols, cumCount[c] = sum of counts of symbols less than c
        int[] cumCount = new int[R+1];
        for (int i=1; i <= R; ++i) cumCount[i] = i;
        int N = R;
        // initialize low and high
        char low = 0, high = 0xFFFF;
        int step;
        // number of E3 scaling operated
        int scale = 0;
        while (!BinaryStdIn.isEmpty())
        {
            // get symbol
            char c = BinaryStdIn.readChar();
            // update low and high
            step = (high - low + 1) / N;
            high = (char) (low + step*cumCount[c+1] - 1);
            low  = (char) (low + step*cumCount[c]);
            // E1 or E2 scaling
            while ((MSB_MASK & low) == (MSB_MASK & high)) {
                boolean b = (MSB_MASK & low) == MSB_MASK;
                // send b
                BinaryStdOut.write(b);
                // shift low left by 1 bit and shift 0 into LSB
                low <<= 1;
                // shift high left by 1 bit and shift 1 into LSB
                high = (char) ((high << 1) | 1);
                // send complement of 
                for (b = !b; scale > 0; --scale)
                    BinaryStdOut.write(b);
            }
            // E3 scaling
            while (((SMSB_MASK & low) == SMSB_MASK) && ((SMSB_MASK & high) == 0)) {
                // shift low left by 1 bit and shift 0 into LSB
                low <<= 1;
                // shift high left by 1 bit and shift 1 into LSB
                high = (char) ((high << 1) | 1);
                // complement (new) MSB of low, high
                low  ^= MSB_MASK;
                high ^= MSB_MASK;
                // increment scale
                ++scale;
            }
            N += INCREMENT;
            // update cumulate counts
            for (int i=R; i > c; --i) cumCount[i] += INCREMENT;
            if (N >= MAX_COUNT) {
                N >>= 1;
                for (int i=1; i <= R; ++i) cumCount[i] = (cumCount[i]+1) >> 1;
            }
        }
        boolean b = (MSB_MASK & low) == MSB_MASK;
        BinaryStdOut.write(b);
        for (b = !b; scale > 0; --scale)
            BinaryStdOut.write(b);
        for (int i=1; i < M; ++i, low<<=1)
            BinaryStdOut.write((SMSB_MASK & low) == SMSB_MASK);
        BinaryStdOut.close();
    }

    public static void expand()
    {
        // cummulate counts of symbols, cumCount[c] = sum of counts of symbols less than c
        int[] cumCount = new int[R+1];
        for (int i=1; i <= R; ++i) cumCount[i] = i;
        int N = R;
        // initialize low and high
        char low = 0, high = 0xFFFF;
        int step;
        // read the first M bits of the received bitstream into tag t
        char t = BinaryStdIn.readChar(M);
        Outer:
        while (!BinaryStdIn.isEmpty())
        {
            step = (high - low + 1) / N;
            int cnt = (t - low) / step;
            char c = (char) rank(cumCount, cnt);
            BinaryStdOut.write(c);
            high = (char) (low + step*cumCount[c+1] - 1);
            low  = (char) (low + step*cumCount[c]);
            // scaling: MSB of low and high are both equal to b or E3 condition holds
            // decode symbol x
            // E1 or E2 scaling
            while ((MSB_MASK & low) == (MSB_MASK & high)) {
                // shift low left by 1 bit and shift 0 into LSB
                low <<= 1;
                // shift high left by 1 bit and shift 1 into LSB
                high = (char) ((high << 1) | 1);
                // shift t left by 1 bit and read next bit from received bitstream into LSB
                if (BinaryStdIn.isEmpty()) break Outer;
                int b = BinaryStdIn.readInt(1);
                t = (char) ((t << 1) | b);
            }
            // E3 scaling
            while (((SMSB_MASK & low) == SMSB_MASK) && ((SMSB_MASK & high) == 0)) {
                // shift low left by 1 bit and shift 0 into LSB
                low <<= 1;
                // shift high left by 1 bit and shift 1 into LSB
                high = (char) ((high << 1) | 1);
                // shift t left by 1 bit and read next bit from received bitstream into LSB
                if (BinaryStdIn.isEmpty()) break Outer;
                int b = BinaryStdIn.readInt(1);
                t = (char) ((t << 1) | b);
                // complement (new) MSB of low, high and t
                low  ^= MSB_MASK;
                high ^= MSB_MASK;
                t ^= MSB_MASK;
            }
            N += INCREMENT;
            // update cumulate counts
            for (int i=R; i > c; --i) cumCount[i] += INCREMENT;
            if (N >= MAX_COUNT) {
                N >>= 1;
                for (int i=1; i<=R; ++i) cumCount[i] = (cumCount[i]+1) >> 1;
            }
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
    }
}