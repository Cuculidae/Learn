/*
 * Compress or expand a genomic sequence using a 2-bit code.
 *
 * Execution:       java Genome - < INPUT (compress); java Genome + < INPUT (expand)
 *                  % java Genome - < genomeTiny.txt | java Genome +
 *                  ATAGATGCATAGCGCATAGCTAGATGTGCTAGC
 * Dependencies:    BinaryStdIn.java, BinaryStdOut.java
 * Data File:       genomeTiny.txt, genomeVirus.txt
 * Author:          caiguochu
 * Time:            2015-07-15
 */
public class Genome
{
    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    public static void compress()
    {
        Alphabet DNA = new Alphabet("ACTG");
        String s = BinaryStdIn.readString();
        int N = s.length();
        BinaryStdOut.write(N);
        for (int i = 0; i < N; ++i)
        {
            int d = DNA.toIndex(s.charAt(i));
            BinaryStdOut.write(d, DNA.lgR());
        }
        BinaryStdOut.close();
    }

    public static void expand()
    {
        Alphabet DNA = new Alphabet("ACTG");
        int w = DNA.lgR();
        int N = BinaryStdIn.readInt();
        for (int i = 0; i < N; ++i)
        {
            char c = BinaryStdIn.readChar(w);
            BinaryStdOut.write(DNA.toChar(c));
        }
        BinaryStdOut.close();
    }
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        if (args[0].equals("-")) compress();
        if (args[0].equals("+")) expand();
    }
}