/*
 * The MaxPQ class represents a maximum-oriented priority queue of generic keys.
 * It supports the usual insert and delete-the-maximum operations, along with 
 * methods for peeking at the maximum key, testing if the priority queue is empty.
 * This implementation uses a binary heap.
 * The insert and delete-the-maximum operations take logarithmic amortized time.
 * The max, size, and is-empty operations take constant time.
 * Construction takes time proportional to the specified capacity or the number of
 * keys used to initialize the data structure.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/24pq">
 *
 * Execution:		java MaxPQ < input
 * Dependencies:	StdIn.java, StdOut.java
 * Data File:		tinyPQ.txt
 * Author:			caiguochu
 * Time:			2015-01-26
 * Revised:			2015-02-10
 */

import java.util.Iterator;
import java.util.NoSuchElementException;

public class MaxPQ<Key extends Comparable<Key>> implements Iterable<Key>
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private Key[] pq;	// stores the element in pq[1...N], pq[0] not used
	private int N;		// number of keys on priority queue


	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/

	/**
	 * Initializes an empty priority queue
	 */
	MaxPQ()
	{	this(1);	}

	/**
	 * Initializes an empty priority queue with the given capacity
	 * @param capacity the initial capacity of the priority queue
	 */
	MaxPQ(int capacity)
	{
		pq = (Key[]) new Comparable[capacity+1];	//pq[0] not used, add 1
		N = 0;
	}

	/**
	 * Initializes a priority queue from an array of keys
	 * Takes time proportional to the number of keys, using sink-based heap construction
	 * @param a the array of keys
	 */
	MaxPQ(Key[] a)
	{
		N = a.length;
		pq = (Key[]) new Comparable[N+1];
		for (int i = 0; i < N; i++)
			pq[i+1] = a[i];
		for (int k = N/2; k >= 1; k--)
			sink(k);
	}

	/**
	 * Initializes a priority queue from another priority queue
	 * Takes time proportional to the number of keys
	 * @param that another priority queue to initialize from
	 */
	MaxPQ(MaxPQ<Key> that)
	{
		N = that.N;
		pq = (Key[]) new Comparable[N+1];
		for (int i = 1; i <= N; i++)
			pq[i] = that.pq[i];
	}


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is pq[i] less than pq[j] ?
	private boolean less(int i, int j)
	{	return pq[i].compareTo(pq[j]) < 0;	}
	// swaps pq[i] and pq[j]
	private void exch(int i, int j)
	{	Key t = pq[i]; pq[i] = pq[j]; pq[j] = t;	}
	// resizes the heap array
	private void resize(int capacity)
	{
		Key[] tmp = (Key[]) new Comparable[capacity+1];
		for (int i = 1; i <= N; i++)
			tmp[i] = pq[i];
		pq = tmp;
	}
	// Bottom up reheapifying
	private void swim(int k)
	{
		while (k > 1 && less(k/2, k))	// pq[k/2] is the father of pq[k]
			exch(k, k /= 2);
	}
	// Top down reheapifying
	private void sink(int k)
	{
		int j;
		while ((j = 2*k) <= N)
		{
			// pq[k]'s two childs: pq[2*k] and pq[2*k+1]
			if (j < N && less(j, j+1)) j++;	// biggest of two childs
			if (!less(k, j)) break;			// heapified
			exch(k, k = j);
		}
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
	/**
	 * is the priority queue empty?
	 * @return true if priority queue is empty; false otherwise
	 */
	public boolean isEmpty()
	{	return N == 0;	}

	/**
	 * returns the number of keys on the priority queue.
	 * @return the number of keys on the priority queue
	 */
	public int size()
	{	return N;	}

	/**
	 * returns the max key on the priority queue.
	 * @return the max key on the priority queue
	 * @throws java.util.NoSuchElementException if priority queue is empty
	 */
	public Key max()
	{
		if (isEmpty()) throw new NoSuchElementException("Priority Queue underflow!");
		return pq[1];
	}

	/**
	 * removes and returns the max key on the priority queue
	 * @return the max key on the priority queue
	 * @throws java.util.NoSuchElementException if priority queue is empty
	 */
	public Key delMax()
	{
		if (isEmpty()) throw new NoSuchElementException("Priority Queue underflow!");
		Key max = pq[1];
		pq[1] = pq[N];
		pq[N--] = null;	// advoid loitering and help with garbage collection
		sink(1);
		if (N == (pq.length-1)/4) resize(N*2);
		return max;
	}

	/**
	 * adds a new key v
	 * @param v the key to be added
	 */
	public void insert(Key v)
	{
		if (N == pq.length-1)
			resize(N*2);
		pq[++N] = v;
		swim(N);
	}


	/*********************************************************************************************
	 *                                       Iterator                                            *
	 *********************************************************************************************/
	/**
     * Returns an iterator that iterates over the keys on the priority queue
     * in descending order.
     * The iterator doesn't implement remove() since it's optional.
     * @return an iterator that iterates over the keys in descending order
     */
    public Iterator<Key> iterator() { return new HeapIterator(this); }

    private class HeapIterator implements Iterator<Key>
    {
        // create a new pq
        private MaxPQ<Key> copy;
        // add all items to copy of heap
        // takes linear time since already in heap order so no keys move
        public HeapIterator(MaxPQ<Key> that) { copy = new MaxPQ<Key>(that);     }
        public boolean hasNext()  { return !copy.isEmpty();                     }
        public void remove()      { throw new UnsupportedOperationException();  }
        public Key next()
        {
            if (!hasNext()) throw new NoSuchElementException();
            return copy.delMax();
        }
    }



	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
    // Unit tests the MaxPQ data type.
    public static void main(String[] args)
    {
        MaxPQ<String> pq = new MaxPQ<String>();
        while (!StdIn.isEmpty())
        {
            String key = StdIn.readString();
            if (!key.equals("-")) pq.insert(key);
            else if (!pq.isEmpty()) StdOut.print(pq.delMax() + " ");
        }
        StdOut.println("(" + pq.size() + " left on pq)");
        for (String s : pq)
        	StdOut.println(s);
    }
}