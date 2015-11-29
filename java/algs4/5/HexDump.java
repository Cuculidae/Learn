/*
 * Reads in a binary file and writes out the bytes in hex, N bytes per line.
 *
 * Execution:       java HexDump N < file
 *                  % java HexDump 4 < abra.txt
 * 					41 42 52 41
 * 					43 41 44 41
 * 					42 52 41 21
 *
 *                  96 bits
 * Dependencies:    BinaryStdIn.java, StdOut.java
 * Data File:       abra.txt
 * Author:          caiguochu
 * Time:            2015-07-14
 */
public class HexDump
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
        		BinaryStdIn.readChar();
        		continue;
        	}
            char c = BinaryStdIn.readChar();
            StdOut.printf("%02x", c & 0xff);
            StdOut.printf("%s", (cnt%width==(width-1)) ? "\n" : " ");
        }
        StdOut.println();
        StdOut.println(cnt*8+" bits");
    }
}