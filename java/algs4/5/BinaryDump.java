/*
 * Reads in a binary file and writes out the bits, N per line.
 *
 * Execution:       java BinaryDump N < file
 *                  % java BinaryDump 16 < abra.txt
 *                  0100000101000010
 *                  0101001001000001
 *                  0100001101000001
 *                  0100010001000001
 *                  0100001001010010
 *                  0100000100100001
 *
 *                  96 bits
 * Dependencies:    BinaryStdIn.java, StdOut.java
 * Data File:       abra.txt
 * Author:          caiguochu
 * Time:            2015-07-14
 */
public class BinaryDump
{
    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        int width = Integer.parseInt(args[0]);
        int cnt;
        for (cnt = 0; !BinaryStdIn.isEmpty(); ++cnt)
        {
            if (width == 0)
            {
                BinaryStdIn.readBoolean();
                continue;
            }
            if (BinaryStdIn.readBoolean())
                StdOut.print("1");
            else StdOut.print("0");
            if (cnt % width == (width - 1))
                StdOut.println();
        }
        StdOut.println();
        StdOut.println(cnt+" bits");
    }
}