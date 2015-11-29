/*
 * Generic implementation of double-ended priority queue, called min-max-heap.
 * It allows both find-min and find-max be performed in constant time.
 * Insert, deleteMin and deleteMax operations can be performed in logarithmic time.
 *
 * Execution:		java MinMaxHeap < input
 * Dependencies:	StdOut.java StdRandom.java
 * Data File:		None
 * Author:			caiguochu
 * Time:			2015-02-06
 * Revised:			2015-02-10
 */

import java.util.NoSuchElementException;

public class MinMaxHeap<Key extends Comparable<Key>>
{
	/*********************************************************************************************
	 *                                         Fields                                            *
	 *********************************************************************************************/
	private int N;            // number of elements stored
	private Key[] keys;       // stores elements in keys[1...N]



	/*********************************************************************************************
	 *                                      Constructors                                         *
	 *********************************************************************************************/
	/**
	 *Initialize an empty min-max-heap
	 */
	MinMaxHeap() {	this(1);	}

	/**
	 * Initialize an empty min-max-heap with the given capacity.
	 * @param capacity the initial capacity of the min-max-heap.
	 */
	MinMaxHeap(int capacity)
	{
		N = 0;
		keys = (Key[]) new Comparable[capacity+1];
	}


	/*********************************************************************************************
	 *                                    Helper Functions                                       *
	 *********************************************************************************************/
	// is keys[i] < keys[j] ?
	private boolean less(int i, int j) {	return keys[i].compareTo(keys[j]) < 0;	}
	// is keys[i] > keys[j] ?
	private boolean greater(int i, int j) {	return keys[i].compareTo(keys[j]) > 0;	}
	// swaps keys[i] and keys[j]
	private void exch(int i, int j) {	Key t = keys[i]; keys[i] = keys[j]; keys[j] = t;	}
	// resize array keys with the given capacity
	private void resize(int capacity)
	{
		Key[] tmp = (Key[]) new Comparable[capacity+1];
		for (int i = 1; i <= N; i++)
			tmp[i] = keys[i];
		keys = tmp;
	}
	// is keys[k] at even level ?
	private boolean atEven(int k)
	{
		while (k > 1) 	k >>= 2;
		return k == 1 ? true : false;
	}
	// Top-down rebalance at min level
	private void sinkMin(int k)
	{
		while (4*k <= N)
		{
			int i=4*k, j=i+1;
			if (j <= N && less(j, i))     i=j;
			if (j+1 <= N && less(j+1, i)) i=j+1;
			if (j+2 <= N && less(j+2, i)) i=j+2;
			if (less(i, k))
			{	
				exch(i, k);
				if (greater(i, i/2)) exch(i, i/2);
			}
			k = i;
		}
		if (2*k <= N)
		{
			int j = 2*k;
			if (j < N && less(j+1, j)) j++;
			if (less(j, k)) exch(j, k);
		}
	}
	// Top-down rebalance at max level
	private void sinkMax(int k)
	{
		while (4*k <= N)
		{
			int i=4*k, j=i+1;
			if (j <= N && greater(j, i))     i=j;
			if (j+1 <= N && greater(j+1, i)) i=j+1;
			if (j+2 <= N && greater(j+2, i)) i=j+2;
			if (greater(i, k))
			{
				exch(i, k);
				if (less(i, i/2)) exch(i, i/2);
			}
			k=i;
		}
		if (2*k <= N)
		{
			int j = 2*k;
			if (j < N && greater(j+1, j)) j++;
			if (greater(j, k)) exch(j, k);
		}
	}
	// Top-down rebalance
	private void sink(int k) {	if (atEven(k)) sinkMin(k); else sinkMax(k);	}
	// Bottom-up rebalance at min level
	private void swimMin(int k)
	{
		while(k > 3 && less(k, k/4))
			exch(k, k/=4);
	}
	// Bottom-up rebalance at max level
	private void swimMax(int k)
	{
		while (k > 3 && greater(k, k/4))
			exch(k, k/=4);
	}
	// Bottom-up rebalance
	private void swim(int k)
	{
		if (atEven(k))
		{	
			if (k > 1 && greater(k, k/2)) {	exch(k, k/=2); swimMax(k);	}
			else	swimMin(k);
		} else {
			if (k > 1 && less(k, k/2))	{	exch(k, k/=2); swimMin(k);	}
			else	swimMax(k);
		}
	}


	/*********************************************************************************************
	 *                            Application Programming Interfaces                             *
	 *********************************************************************************************/

	/**
	 * Is the min-max-heap empty ?
	 * @return true if min-max-heap is empty, false otherwise.
	 */
	public boolean isEmpty() {	return N == 0;	}

	/**
	 * Returns the size of the min-max-heap.
	 * @return the size of the min-max-heap.
	 */
	public int size() {	return N;	}

	/**
	 * Return the minimum key on the min-max-heap.
	 * @return the minimum key on the min-max-heap.
	 * @throws java.util.NoSuchElementException if min-max-heap underflow.
	 */
	public  Key min()
	{
		if (N == 0) throw new NoSuchElementException("Min-max-heap underflow!");
		return keys[1];
	}

	/**
	 * Return the maximum key on the min-max-heap.
	 * @return the maximum key on the min-max-heap.
	 * @throws java.util.NoSuchElementException if min-max-heap underflow.
	 */
	public Key max()
	{
		if (N == 0) throw new NoSuchElementException("Min-max-heap underflow!");
		if (N >= 3) // >= 3 keys, maximum is keys[2] or keys[3]
			return keys[less(2,3) ? 3 : 2];
		else return keys[N]; // <= 2 keys, 
	}

	/**
	 * Adds a new key to min-max-heap.
	 * @param key the new key to be added.
	 */
	public void insert(Key key)
	{
		if (N == keys.length-1) resize(N*2);
		keys[++N] = key;
		swim(N);
	}

	/**
	 * remove and return the minimum key on the min-max-heap.
	 * @return the minimum key on the min-max-heap.
	 * @throws java.util.NoSuchElementException if min-max-heap underflow.
	 */
	public Key delMin()
	{
		if (N == 0) throw new NoSuchElementException("Min-max-heap underflow!");
		Key min = keys[1];
		exch(1, N);
		keys[N--] = null; // avoid loitering
		sink(1);
		if (N == (keys.length-1)/4) resize(N*2);
		return min;
	}

	/**
	 * remove and return the maximum key on the min-max-heap.
	 * @return the maximum key on the min-max-heap.
	 * @throws java.util.NoSuchElementException if min-max-heap underflow.
	 */
	public Key delMax()
	{
		if (N == 0) throw new NoSuchElementException("Min-max-heap underflow!");
		int maxIndex;
		Key max;
		if(N >= 3) maxIndex = less(2, 3) ? 3 : 2; else maxIndex = N;
		max = keys[maxIndex];
		exch(maxIndex, N);
		keys[N--] = null;
		sink(maxIndex);
		if (N == (keys.length-1)/4) resize(N*2);
		return max;
	}


	/*********************************************************************************************
	 *                               Main Program ----- Unit Test                                *
	 *********************************************************************************************/
	// Unit-test the MinMaxHeap data type
	public static void main(String[] args)
	{
		if (args.length != 1) { StdOut.println("***** Usage: java MinMaxHeap N"); return;	}
		int N = Integer.parseInt(args[0]);
		MinMaxHeap<Double> heap = new MinMaxHeap<Double>(N);
		for (int i = 0; i < N; i++)
			heap.insert(StdRandom.uniform());
		for (int i = 0; !heap.isEmpty(); i++)
			StdOut.printf("%.3f%s", heap.delMin(), i%10==9?"\n":"\t");
		StdOut.println();
	}
}