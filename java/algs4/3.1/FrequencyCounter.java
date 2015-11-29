/*
 * The FrequencyCounter class provides a client for
 * reading in a sequence of words and printing a word (exceeding
 * a given length) that occurs most frequently. It is useful as
 * a test client for various sysmbol table implementations.
 * For additional documentation, see "http://algs4.cs.princeton.edu/31elementary"
 * Algorithms, 4th Edition by Robert Sedgewick and Kevin Wayne.
 *
 * Execution:       java FrequencyCounter minLength < INPUT
 *                  % java FrequencyCounter 1 < tinyTale.txt
 *                    it 10
 *                    distinct = 20
 *                    words    = 60
 *                    
 *                  % java FrequencyCounter 8 < tale.txt
 *                    business 122
 *                    distinct = 5126
 *                    words    = 14346
 *                    
 *                  % java FrequencyCounter 10 < leipzig1M.txt
 *                    government 24763
 *                    distinct = 165555
 *                    words    = 1610829
 * Dependencies:    ST.java, StdIn.java, StdOut.java
 * Data File:       tinyTale.txt, tale.txt, leipzig1M.txt
 * Author:          caiguochu
 * Time:            2015-05-28
 */
public class FrequencyCounter
{
    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    private FrequencyCounter() {}	// This class should not been instantiated.


    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/
    /**
     * Reads in a command-line integer and sequence of words from
     * standard input and prints out a word (whose length exceeds
     * the threshold) that occurs most frequently to standard output.
     * It also prints out the number of words whose length exceeds
     * the threshold and the number of distinct such words.
     */
    public static void main(String[] args)
    {
        int distinct = 0, words = 0;
        int minlen = Integer.parseInt(args[0]);	// threshold length
        ST<String, Integer> st = new ST<String, Integer>();

        // compute frequency counts
        while (!StdIn.isEmpty())
        {
        	String key = StdIn.readString();
        	if (key.length() < minlen) continue;
        	words++;
        	if (st.contains(key))
        	{
        		st.put(key, st.get(key) + 1);
        	}
        	else {
        		st.put(key, 1);
        		distinct++;
        	}
        }

        // find a key with highest frequency count
        String max = " ";
        st.put(max, 0);
        for (String word : st.keys())
        {
        	if (st.get(word) > st.get(max))
        		max = word;
        }

        StdOut.println(max + " " + st.get(max));
        StdOut.println("distinct = " + distinct);
        StdOut.println("words    = " + words);
    }
}