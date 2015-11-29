/*
 * The TopM class provides a client that reads a sequence of
 * transactions from standard input and prints the M largest ones
 * to standard output. This implementation uses a MinPQ of size
 * at most M + 1 to identify the M largest transactions
 * and a Stack to output them in the proper order.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/24pq">
 *
 * Execution:		java TopM M < input
 * Dependencies:	MinPQ.java, Stack.java, Transaction.java, StdIn.java, StdOut.java 
 * Data File:		tinyBatch.txt
 * Author:			caiguochu
 * Time:			2015-01-27
 * Revised:			2015-02-10
 */
public class TopM
{
	private TopM() {} // This class should not bean instantiated

    /**
     *  Reads a sequence of transactions from standard input; takes a
     *  command-line integer M; prints to standard output the M largest
     *  transactions in descending order.
     */
	public static void main(String[] args)
	{
		int M = Integer.parseInt(args[0]);
		MinPQ<Transaction> pq = new MinPQ<Transaction>(M+1);
		
		while (StdIn.hasNextLine())
		{
            // Create an entry from the next line and put on the PQ. 
            String line = StdIn.readLine();
            Transaction transaction = new Transaction(line);
            pq.insert(transaction); 

			// remove minimum if M+1 entries on the PQ
			if (pq.size() > M)
				pq.delMin();
		} // top M entries are on the PQ

		// print entries on PQ in reverse order
		Stack<Transaction> stack = new Stack<Transaction>();
		while (!pq.isEmpty())	stack.push(pq.delMin());
		for (Transaction t : stack)	StdOut.println(t);
	}
}