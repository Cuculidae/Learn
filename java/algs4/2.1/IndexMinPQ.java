/*
 * The IndexMinPQ class represents an indexed minimum-oriented priority queue of generic keys.
 * It supports the usual insert and delete-the-minimum operations, along with 
 * delete and change-the-key  methods. 
 * In order to let the client refer to keys on the priority queue,
 * an integer between 0 and NMAX-1 is associated with each key;the client
 * uses this integer to specify which key to delete or change.
 * It also supports methods for peeking at a minimum key,
 * testing if the priority queue is empty, and iterating through the keys.
 * This implementation uses a binary heap along with an array to associate
 * keys with integers in the given range.
 * The insert, delete-the-minimum, delete, operations take logarithmic time.
 * The is-empty, size, min-index, min-key, and key-of operations take constant time.
 * Construction takes time proportional to the specified capacity.
 * For additional documentation, see <href="http://algs4.cs.princeton.edu/24pq">
 *
 * Execution:		java IndexMinPQ < input
 * Dependencies:	In.java, StdOut.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-01-29
 * Revised:			2015-02-10
 */

import java.util.Iterator;
import java.util.NoSuchElementException;

public class IndexMinPQ<Key extends Comparable<Key>> implements Iterable<Key>
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private int N;        // number of keys on priority queue
	private int[] pq;     // 1-based indexing binary heap storing indices associated with each item
	private int[] qp;     // inverse pq -- pq[qp[i]] == qp[pq[i]] == i, 
	private Key[] keys; // store keys


	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
    /**
     * Initializes an empty indexed-priority queue with indices between 0 and NMAX-1.
     * @param NMAX the keys on the priority queue are index from 0 to NMAX-1
     * @throws java.lang.IllegalArgumentException if NMAX < 0
     */
	IndexMinPQ(int NMAX)
	{
		pq = new int[NMAX+1];
		qp = new int[NMAX+1];
		//use the convention that qp[i]= -1 if i is not on the queue
		for (int i = 0; i <= NMAX; i++) qp[i] = -1;
		keys = (Key[]) new Comparable[NMAX];
		N = 0;
	}

    /**
     * Initializes an indexed-priority queue from another indexed-priority queue
     * @param that another indexed-priority queue to initialize from
     */
	IndexMinPQ(IndexMinPQ<Key> that)
	{
		N = that.N;
		pq = new int[N+1];
		qp = new int[N+1];
		keys = (Key[]) new Comparable[N];
		for (int i = 1; i <= N; i++)
		{
			pq[i] = that.pq[i];
			qp[i] = that.qp[i];
			keys[i-1] = that.keys[i-1];
		}
	}


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is keys[i] < keys[j] ?
	private boolean greater(int i, int j)
	{	return keys[pq[i]].compareTo(keys[pq[j]]) > 0;	}
	// is index i valid ?
	private boolean isValidIndex(int i)
	{	return 0 <= i && i < keys.length;	}
	// swaps pq[i] and pq[j], update qp
	private void exch(int i, int j)
	{	
		int t = pq[i]; pq[i] = pq[j]; pq[j] = t;
		qp[pq[i]] = i; qp[pq[j]] = j;
	}
	// Bottom-up reheapifying
	private void swim(int i)
	{
		while (i > 1 && greater(i/2, i))
			exch(i, i/=2);
	}
	// Top-down reheapifying
	private void sink(int i)
	{
		int j;
		while ((j=2*i) <= N)
		{
			if (j < N && greater(j, j+1)) j++;
			if (!greater(i, j)) break;
			exch(i, i = j);
		}
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/
    /**
     * Is the priority queue empty?
     * @return true if the priority queue is empty; false otherwise
     */
	public boolean isEmpty()	{ return N == 0;	}

    /**
     * Returns the number of keys on the priority queue.
     * @return the number of keys on the priority queue 
     */
	public int size()	{	return N;	}

    /**
     * Is index on the priority queue?
     * @param index an index
     * @throws java.lang.IndexOutOfBoundsException if index out of bounds
     */
	public boolean contains(int index)	
	{	
		if (!isValidIndex(index)) return false;
		return qp[index] != -1;	//use the convention qp[i]= -1 if i is not on the queue
	}

    /**
     * Returns the key associated with index index.
     * @param index the index of the key to return
     * @return the key associated with index index
     * @throws java.util.NoSuchElementException no key is associated with index i
     */
    public Key keyOf(int index) {
        if (!contains(index))
        	throw new NoSuchElementException("index is not in the priority queue");
        else return keys[index];
    }

    /**
     * Return a minimum key.
     * @return a minimum key
     * @throws java.util.NoSuchElementException if priority queue is empty
     */
	public Key minKey()
	{
		if (isEmpty())	throw new NoSuchElementException("Priority Queue undeflow!");
		return keys[pq[1]];
	}

    /**
     * Returns an index associated with a minimum key.
     * @return an index associated with a minimum key
     * @throws java.util.NoSuchElementException if priority queue is empty
     */
	public int minIndex()
	{
		if (isEmpty())	throw new NoSuchElementException("Priority Queue undeflow!");
		return pq[1];
	}

    /**
     * Removes a minimum key and returns its associated index.
     * @return an index associated with a minimum key
     * @throws java.util.NoSuchElementException if priority queue is empty
     */
	public int delMin()
	{
		if (isEmpty())	throw new NoSuchElementException("Priority Queue undeflow!");
		int indexOfMin = pq[1];
		qp[indexOfMin] = -1;
		keys[indexOfMin] = null; // avoid loitering
		pq[1] = pq[N--];
		sink(1);
		return indexOfMin;
	}

    /**
     * Associate key with index index.
     * @param index an index
     * @param key the key to associate with index
     * @throws java.lang.IndexOutOfBoundsException if index out of bounds
     * @throws java.util.IllegalArgumentException if there already is an item associated with index
     */
	public void insert(int index, Key item)
	{
		if (!isValidIndex(index)) 
			throw new IndexOutOfBoundsException("Unvalid Index! must 0 <= index < numb_of_keys");
		if (contains(index)) // must stop, otherwise will distroy heap-order
			throw new IllegalArgumentException("Index already in PQ");
		pq[++N] = index;
		qp[index] = N;
		keys[index] = item;
		swim(N);
	}

    /**
     * Change the key associated with index to the specified value.
     * @param index the index of the key to change
     * @param key change the key assocated with index to this key
     * @throws java.lang.IndexOutOfBoundsException if index out of bounds
     */
	public void change(int index, Key item)
	{
		if (!isValidIndex(index))
			throw new IndexOutOfBoundsException("Unvalid Index! must 0 <= index < num_of_keys");
		if (!contains(index))	// if not contains the index, resolve to insert
		{	
			insert(index, item);
			return;
		};
		keys[index] = item;
		int k = qp[index];
		swim(k);
		sink(k);
	}

    /**
     * Remove the key associated with index index, do nothing if no key associates with index
     * @param index the index of the key to remove
     */
	public void delete(int index)
	{
		if (!contains(index)) return; 
		int k = qp[index];
		exch(k, N--);
		sink(k);
		keys[index] = null; // avoid loitering
		qp[index] = -1;
	}


	/*********************************************************************************************
	 *                                       Iterator                                            *
	 *********************************************************************************************/
	/**
     * Returns an iterator that iterates over the keys on the priority queue
     * in ascending order.
     * The iterator doesn't implement remove() since it's optional.
     * @return an iterator that iterates over the keys in descending order
     */
    public Iterator<Key> iterator() { return new HeapIterator(this); }

    private class HeapIterator implements Iterator<Key>
    {
        // create a new pq
        private IndexMinPQ<Key> copy;
        // add all items to copy of heap
        // takes linear time since already in heap order so no keys move
        public HeapIterator(IndexMinPQ<Key> that) { copy = new IndexMinPQ<Key>(that); }
        public boolean hasNext()  { return !copy.isEmpty();                     }
        public void remove()      { throw new UnsupportedOperationException();  }
        public Key next()
        {
            if (!hasNext()) throw new NoSuchElementException();
            Key min = copy.minKey();
            copy.delMin();
            return min;
        }
    }


	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	//Unit-test IndexMinPQ data type
	public static void main(String[] args)
	{ 
		String[] a = In.readStrings();
		IndexMinPQ<String> pq = new IndexMinPQ<String>(a.length);
		for (int i = 0; i < a.length; i++)
			pq.insert(i, a[i]);
		for (String s : pq)
			StdOut.println(s);
	}
}