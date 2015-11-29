/*
 * Writes 1000000 pseudo bits to standard output.
 *
 * Execution:       java BinaryStdOut
 * Dependencies:    BinaryStdOut.java
 * Data File:       None
 * Author:          caiguochu
 * Time:            2015-07-15
 */
public class RandomBits
{   
    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        int x = 11111;
        for (int i = 0; i < 1000000; ++i)
        {
            x = x*314159 + 218281;
            BinaryStdOut.write(x > 0);
        }
        BinaryStdOut.close();
    }
}