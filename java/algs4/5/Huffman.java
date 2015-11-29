/*
 * Compress or expand a binary input stream using the Huffman algorithm.
 *
 * Execution:       java Huffman - < INPUT (compress); java Huffman + < INPUT (expand)
 *                  % java Huffman - < abra.txt | java BinaryDump 60
 *                  010100000100101000100010010000110100001101010100101010000100
 *                  000000000000000000000000000110001111100101101000111110010100
 *                  120 bits
 *                  % java Huffman - < abra.txt | java Huffman +
 *                  ABRACADABRA!
 * Dependencies:    BinaryStdIn.java, BinaryStdOut.java, MinPQ.java
 * Data File:       abra.txt, tinytinyTales.txt, medTale.txt, tale.txt ...
 * Author:          caiguochu
 * Time:            2015-07-16
 */

public class Huffman
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int R = 256;   // alphabet size of extended ASCII

    // Huffman trie node
    private static class Node implements Comparable<Node>
    {
        private char c;
        private int freq;
        private Node left, right;

        public Node(char c, int freq, Node left, Node right)
        {
            this.c = c;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }
        // compare, based on frequency
        public int compareTo(Node that)
        {    return this.freq - that.freq;    }
        // is the node a leaf node ?
        public boolean isLeaf()
        {    return this.left == null & this.right == null;    }
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // build the Huffman trie given frequencies
    private static Node buildTrie(int[] freq)
    {
        // initialize priority queue with singleton trees
        MinPQ<Node> pq = new MinPQ<Node>();
        for (char c = 0; c < R; ++c)
            if (freq[c] > 0)
                pq.insert(new Node(c, freq[c], null, null));

        // special case in case there is only one character with a nonzero frequency
        if (pq.size() == 1) {
            if (freq['\0'] == 0) pq.insert(new Node('\0', 0, null, null));
            else                 pq.insert(new Node('\1', 0, null, null));
        }

        // merge two smallest trees
        while (pq.size() > 1)
        {
            Node x = pq.delMin();
            Node y = pq.delMin();
            Node parent = new Node('\0', x.freq+y.freq, x, y);
            pq.insert(parent);
        }
        return pq.delMin();
    }

    // make a lookup table from symbols and their encodings
    private static void buildCode(String[] st, Node x, String s)
    {
        if (!x.isLeaf()) {
            buildCode(st, x.left, s+'0');
            buildCode(st, x.right, s+'1');
        } else {
            st[x.c] = s;
        }
    }

    // write bitstring-encoded trie to standard output
    private static void writeTrie(Node x)
    {
        if (x.isLeaf())
        {
            BinaryStdOut.write(true);
            BinaryStdOut.write(x.c);
            return;
        }
        BinaryStdOut.write(false);
        writeTrie(x.left);
        writeTrie(x.right);
    }

    private static Node readTrie()
    {
        if (BinaryStdIn.readBoolean())
            return new Node(BinaryStdIn.readChar(), 0, null, null);
        return new Node('\0', 0, readTrie(), readTrie());
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    // compress bytes from standard input and write to standard output
    public static void compress()
    {
        // read the input
        String s = BinaryStdIn.readString();
        char[] input = s.toCharArray();

        // tabulate frequency counts
        int[] freq = new int[R];
        for (int i = 0; i < input.length; ++i)
            freq[input[i]]++;

        // build Huffman trie
        Node root = buildTrie(freq);
        // build code table
        String[] st = new String[R];
        buildCode(st, root, "");

        // print trie for decoder
        writeTrie(root);

        // print number of bytes in original uncompressed message
        BinaryStdOut.write(input.length);

        // use Huffman code to encode input
        for (int i = 0; i < input.length; ++i)
        {
            String code = st[input[i]];
            for (int j = 0; j < code.length(); ++j)
                if (code.charAt(j) == '1')
                    BinaryStdOut.write(true);
                else
                    BinaryStdOut.write(false);
        }

        // close output stream
        BinaryStdOut.close();
    }

    // expand Huffman-encoded input from standard input and write to standard output
    public static void expand()
    {
        // read in Huffman trie from stream
        Node root = readTrie();
        // number of bytes to write
        int N = BinaryStdIn.readInt();
        // decode using the Huffman trie
        for (int i = 0; i < N; ++i)
        {
            Node x = root;
            while (!x.isLeaf())
                if (BinaryStdIn.readBoolean())
                    x = x.right;
                else
                    x = x.left;
            BinaryStdOut.write(x.c);
        }
        BinaryStdOut.close();
    }


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    // Compress and expand using Huffman encoding.
    public static void main(String[] args)
    {
        if      (args[0].equals("-")) compress();
        else if (args[0].equals("+")) expand();
    }
}