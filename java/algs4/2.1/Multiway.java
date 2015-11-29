/*
 * The Multiway class provides a client for reading in several sorted text 
 * files and merging them together into a single sorted text stream.
 * This implementation uses a IndexMinPQ to perform the multiway merge. 
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/24pq">
 *
 * Execution:		java Multiway file1 file2...
 * Dependencies:	IndexMinPQ.java, In.java, StdOut.java
 * Data File:		m1.txt, m2.txt, m3.txt
 * Author:			caiguochu
 * Time:			2015-02-10
 */

public class Multiway
{
	private Multiway() {}; // This class should not bean instantiated.

	// merge together the sorted input streams and write the sorted result to standard output
	public static void merge(In[] streams)
	{
		int N = streams.length;
		IndexMinPQ<String> pq = new IndexMinPQ<String>(N);

		for (int i = 0; i < N; i++)
			if (!streams[i].isEmpty())
				pq.insert(i, streams[i].readString());

		// Extract and print min and read next from its stream.
		while (!pq.isEmpty())
		{
			StdOut.println(pq.minKey());
			int i = pq.delMin();

			if (!streams[i].isEmpty())
				pq.insert(i, streams[i].readString());
		}
	}


    /**
     *  Reads sorted text files specified as command-line arguments;
     *  merges them together into a sorted output; and writes
     *  the results to standard output.
     *  Note: this client does not check that the input files are sorted.
     */	
	public static void main(String[] args)
	{
		int N = args.length;
		In[] streams = new In[N];
		for (int i = 0; i < N; i++)
			streams[i] = new In(args[i]);
		merge(streams);
	}
}
