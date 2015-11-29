/*
 * The BinarySearchST represents an ordered symbo table of key-value pairs,
 * in which the key must implement the Comparable interface.
 * This implementation uses parallel arrays, one for the keys, another for
 * the associated values.
 * It supports the usual get, put, delete, size, contains and is-empty
 * operations. It also provides some order-relavent operations: min, max
 * delete-min, delete-max, floor, ceiling, rank, select.
 *
 * Execution:       java BinarySearchST < INPUT
 * 				    % more tinyST.txt
 * 				    S E A R C H E X A M P L E
 * 				    
 * 				    % java BinarySearchST < tinyST.txt
 * 				    A 8
 * 				    C 4
 * 				    E 12
 * 				    H 5
 * 				    L 11
 * 				    M 9
 * 				    P 10
 * 				    R 3
 * 				    S 0
 * 				    X 7
 * Dependencies:    Queue.java, StdIn.java, StdOut.java
 * Data File:       tinyST.java
 * Author:          caiguochu
 * Time:            2015-05-28
 */


import java.util.NoSuchElementException;

public class BinarySearchST<Key extends Comparable<Key>, Value>
{
    /*********************************************************************************************
     *                                         Fields                                            *
     *********************************************************************************************/
    private static final int INIT_CAPACITY = 64;	// constant default initial cpacity
    private Key[] keys;		// the keys
    private Value[] vals;	// the associated values
    private int N;			// number of key-value pairs


    /*********************************************************************************************
     *                                      Constructors                                         *
     *********************************************************************************************/
    /**
     * Creates an empty symbol table with default initial capacity.
     */
    public BinarySearchST()
    {
    	this(INIT_CAPACITY);
    }

    /**
     * Creates an empty symbol table with a given initial capacity.
     */
    public BinarySearchST(int capacity)
    {
    	keys = (Key[]) new Comparable[capacity];
    	vals = (Value[]) new Object[capacity];
    }


    /*********************************************************************************************
     *                                    Helper Functions                                       *
     *********************************************************************************************/
    // resize the underlying array
    private void resize(int capacity)
    {
    	Key[]   tempk = (Key[])   new Comparable[capacity];
    	Value[] tempv = (Value[]) new Comparable[capacity];

    	for (int i = 0; i < N; ++i)
    	{
    		tempk[i] = keys[i];
    		tempv[i] = vals[i];
    	}

    	keys = tempk;
    	vals = tempv;
    }


    /*********************************************************************************************
     *                            Application Programming Interfaces                             *
     *********************************************************************************************/
    /**
     * Returns the number of key-value pairs in the symbol table.
     * @return the number of key-value pairs in the symbol table
     */
    public int size()
    	{	return N;	}

    /**
     * Is the symbol table empty?
     * @return true if the symbol table is empty, false otherwise
     */
    public boolean isEmpty()
    	{	return N == 0;	}

    /**
     * Does the symbol table contains the given key?
     * @return true if the symbol table contains the given key,
     *		and false otherwise.
     */
    public boolean contains(Key key)
    	{	return get(key) != null;	}

    /**
     * Returns the number of keys in the table that are smaller than the given key.
     * @param key the given key
     * @return the number of keys in the table that are smaller than the given key
     */
    public int rank(Key key)
    {
    	int lo = 0, hi = N-1;
    	while (lo <= hi)
    	{
    		int mid = (lo + hi) / 2;
    		int cmp = key.compareTo(keys[mid]);
    		if 		(cmp < 0)	hi = mid - 1;
    		else if (cmp > 0)	lo = mid + 1;
    		else				return mid;
    	}
    	return lo;
    }

    /**
     * Returns the value associated with the given key, or null if no such key
     * @return the value associated with the given key, or null if no such key
     */
    public Value get(Key key)
    {
    	if (isEmpty())	return null;
    	int i = rank(key);
    	// found
    	if (i < N && keys[i].compareTo(key) == 0)
    		return vals[i];
    	// not found
    	return null;
    }

    /**
     * Search for key. Update value if found; grow table if new.
     */
    public void put(Key key, Value val)
    {
    	if (val == null)
    	{
    		delete(key);
    		return;
    	}

    	int i = rank(key);
    	// key is already in table
    	if (i < N && keys[i].compareTo(key) == 0)
    	{
    		vals[i] = val;
    		return ;
    	}

    	if (N == keys.length)	resize(2*keys.length);

    	for (int j = N; j > i; j--)
    	{
    		keys[j] = keys[j-1];
    		vals[j] = vals[j-1];
    	}
    	keys[i] = key;
    	vals[i] = val;
    	N++;
    }

    /**
     * Removes the key-value pair if present
     */
    public void delete(Key key)
    {
    	if (isEmpty()) return;

    	// compute rank
    	int i = rank(key);

    	// key not in tabel
    	if (i == N || keys[i].compareTo(key) != 0)
    	{
    		return;
    	}

    	for (int j = i; j < N-1; j++)
    	{
    		keys[j] = keys[j+1];
    		vals[j] = vals[j+1];
    	}

    	N--;
    	keys[N] = null;	// to avoid loitering
    	vals[N] = null;

    	// resize if 1/4 full
    	if (N > 0 && N == keys.length/4)
    		resize(keys.length/2);
    }

    /**
     * Delete the minimum key and its associated value
     */
    public void delMin()
    {
    	if (isEmpty())
    		throw new NoSuchElementException("Symbol table underflow error");
    	delete(min());
    }

    /**
     * Delete the maximum key and its associated value
     */
    public void delMax()
    {
    	if (isEmpty())
    		throw new NoSuchElementException("Symbo table underflow error");
    	delete(max());
    }

    /**
     * Returns the minimum key, or null if the table is empty
     * @return the minimum key, or null if the table is empty
     */
    public Key min()
    {
    	if (isEmpty())	return null;
    	return keys[0];
    }

    /**
     * Returns the maximum key, or null if the table is empty
     * @return the maxinum key, or null if the table is empty
     */
    public Key max()
    {
    	if (isEmpty())	return null;
    	return keys[N-1];
    }

    /**
     * Returns the key of the given rank k
     * @param k the given rank
     * @return the key of the given rank
     */
    public Key select(int k)
    {
    	if (k < 0 || k >= N)	return null;
    	return keys[k];
    }

    /**
     * Returns the key not greater than the given key
     * @return the key not greater than the given key
     */
    public Key floor(Key key)
    {
    	int i = rank(key);
    	if (i < N && key.compareTo(keys[i]) == 0) return keys[i];
    	if (i == 0) return null;
    	else return keys[i-1];
    }

    /**
     * Returns the key not less than the given key
     * @return the key not less than the given key
     */
    public Key ceiling(Key key)
    {
    	int i = rank(key);
    	if (i == N)	return null;
    	else 		return keys[i];
    }

    /**
     * Returns the number of key-value pairs in the given
     * range specified by key lo and key hi
     * @param lo the low key specified the beginning of the range
     * @param hi the hight key specified the end of the range
     * @return the number of key-value pairs in the given range
     */
    public int size(Key lo, Key hi)
    {
    	if (lo == null & hi == null) return 0;
    	if (lo == null)	throw new NullPointerException("lo is null in size()");
    	if (hi == null) throw new NullPointerException("hi is null in size()");
    	if (lo.compareTo(hi) > 0)	return 0;
    	if (contains(hi))	return rank(hi) - rank(lo) + 1;
    	else 				return rank(hi) - rank(lo);
    }

    /**
     * Returns all the keys in the symbo table as an iterable.
     * @return all the keys in the symbol table as an iterable
     */
    public Iterable<Key> keys()
    {
    	return keys(min(), max());
    }

    /**
     * Returns the keys as an iterable in the given range
     * specified by key lo and key hi.
     * @param lo the low key specifies the beginning of the range
     * @param hi the high key specifies the end of the range
     * @return the keys as iterable in the given range
     */
    public Iterable<Key> keys(Key lo, Key hi)
    {
    	Queue<Key> queue = new Queue<Key>();
    	if (lo == null && hi == null)	return queue;
    	if (lo == null)	throw new NullPointerException("lo is null in keys()");
    	if (hi == null) throw new NullPointerException("hi is null in keys()");
    	if (lo.compareTo(hi) > 0)	return queue;
    	for (int i = rank(lo); i < rank(hi); ++i)
    	{
    		queue.enqueue(keys[i]);
    	}
    	if (contains(hi))	queue.enqueue(keys[rank(hi)]);
    	return queue;
    }


    /*********************************************************************************************
     *                                       Iterator                                            *
     *********************************************************************************************/
    

    /*********************************************************************************************
     *                               Main Program ----- Unit Test                                *
     *********************************************************************************************/

    public static void main(String[] args)
    {
        BinarySearchST<String, Integer> st;
        st = new BinarySearchST<String, Integer>();
        for (int i = 0; !StdIn.isEmpty(); i++)
        {
            String key = StdIn.readString();
            st.put(key, i);
        }
        for (String s : st.keys())
            StdOut.println(s + " " + st.get(s));
    }
}